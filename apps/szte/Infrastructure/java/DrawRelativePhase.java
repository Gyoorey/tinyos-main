import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Component;
import java.awt.GradientPaint;
import java.awt.Graphics2D;
import java.awt.GridLayout;
import java.awt.Paint;
import java.awt.Shape;
import java.util.ArrayList;
import java.util.HashMap;

import javax.swing.JPanel;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.axis.ValueAxis;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.chart.plot.XYPlot;
import org.jfree.chart.renderer.xy.XYLineAndShapeRenderer;
import org.jfree.data.xy.XYSeries;
import org.jfree.data.xy.XYSeriesCollection;
import org.jfree.ui.ApplicationFrame;
import org.jfree.ui.RefineryUtilities;


public class DrawRelativePhase implements RelativePhaseListener{

	class AppFrame extends ApplicationFrame {
		private static final long serialVersionUID = 425044847909613911L;
		JPanel panel;
		
		public AppFrame(String appTitle) {
			super(appTitle);
			panel = new JPanel(new GridLayout(3,1));
		}
		
		public void addChartPanel(ChartPanel chart) {
			this.setContentPane(panel);
			panel.add(chart);
		}
		
		//connect all chart renderer to period's chart
		public void setAllChartRenderer() {	
			ChartPanel refCp = null;
			for(Component cp : panel.getComponents()) {	//find the period chart
				if(((ChartPanel)cp).getChart().getTitle().getText().equals("Period")) {
					refCp = (ChartPanel) cp;
					break;
				}
			}
			if(refCp != null)  {
				for(Component cp : panel.getComponents()) {	//add all chart renderer to period's chart renderer
					((ChartPanel)cp).getChart().getXYPlot().setRenderer(new RendererSelect((XYSeriesCollection) refCp.getChart().getXYPlot().getDataset()).getTransparencyRenderer());				
				}
			}
		}
	}
	
	class RendererSelect {
		XYSeriesCollection dataSet;
		
		public RendererSelect(XYSeriesCollection dataSet) {
			this.dataSet = dataSet;
		}
		
		public XYLineAndShapeRenderer getNormalRenderer() {
			XYLineAndShapeRenderer renderer = new XYLineAndShapeRenderer();
			return renderer; 
		}
		
		public XYLineAndShapeRenderer getTransparencyRenderer() {
			@SuppressWarnings("serial")
			XYLineAndShapeRenderer renderer = new XYLineAndShapeRenderer(){
		        @Override
		        public Paint getItemPaint(int row, int col) {
		            Paint cpaint = getItemColor(row, col);
		            if (cpaint == null) {
		                cpaint = super.getItemPaint(row, col);
		            }
		            return cpaint;
		        }

			    public Color getItemColor(int row, int col) {
			        double y = dataSet.getYValue(row, col);	//row - series id, col - col-th element of the series
			        double y2 = 1;
			        if(col > 0)
			        	y2 = dataSet.getYValue(row, col-1);
			        if(y == 0 || y2 == 0) 
			        	return new Color(0,0,255,0);
			    	else 
			        	return (Color) getSeriesPaint(row);
			    }
		
				@SuppressWarnings("deprecation")
				@Override
			    protected void drawFirstPassShape(Graphics2D g2, int pass, int series,
					int item, Shape shape) {
			    	g2.setStroke(new BasicStroke(2));
					Color c1 = getItemColor(series, item);
					Color c2 = getItemColor(series, item - 1);
					GradientPaint linePaint = new GradientPaint(0, 0, c1, 0, 0, c2);
					g2.setPaint(linePaint);
					this.setShapesVisible(false);
					g2.draw(shape);
			    }
			};
			return renderer;
		}
	}
	
	class Chart {	
		static final int DRAW_LAST_N_VALUE = 150;
		static final double PI = Math.PI;
		static final double PI2 = 2*Math.PI;
		
		private ChartPanel chartPanel;
		public JFreeChart chart;
		public XYSeriesCollection dataSet; 
		public ArrayList<String> series;	//store the curves dataset index. String = "slotId:rx1,rx2"
		public RendererSelect renderer;

		public Chart(String chartTitle, AppFrame appframe, String xAxis, String yAxis) {
			series = new ArrayList<String>();
			dataSet = new XYSeriesCollection();
			renderer = new RendererSelect(dataSet);
	        JFreeChart chart = createChart(chartTitle, xAxis, yAxis, dataSet);
	        chartPanel = new ChartPanel(chart); 
	        chartPanel.setPreferredSize(new java.awt.Dimension(500, 270));
	        appframe.addChartPanel(chartPanel);
		}
		
	    protected JFreeChart createChart(String chartTitle, String xAxis, String yAxis, XYSeriesCollection dataSet) {
	    	chart = ChartFactory.createXYLineChart(
				chartTitle,
				xAxis,
				yAxis,
				dataSet,
				PlotOrientation.VERTICAL,
				true, true, false);  
	    	XYPlot plot = chart.getXYPlot();
			ValueAxis domainAxis = plot.getDomainAxis();
			domainAxis.setAutoRange(true);
			domainAxis.setFixedAutoRange(DRAW_LAST_N_VALUE); 
			domainAxis.setAutoTickUnitSelection(false);
			domainAxis.setVerticalTickLabels(true);
			return chart;       
	    }

	    
		public void register(String seriesId, double data) {		//create new curve in chart
			XYSeries xys = new XYSeries(seriesId);
			dataSet.addSeries(xys);
			if(dataSet.getDomainUpperBound(false) != dataSet.getDomainUpperBound(false)) {	//check if(dataSet.getDomainUpperBound(false) == NaN)
				xys.add(0,data);
			}		
			else
				xys.add(dataSet.getDomainUpperBound(false), data);	
			series.add(seriesId);			
		}
		
	    public void refreshChart(double data, String seriesId) {
	    	XYSeries xys = dataSet.getSeries(series.indexOf(seriesId));
	   		xys.add(xys.getMaxX()+1, data);
	    }
	}
	
	class UnwrapChart extends Chart {
		
		HashMap<String, Double> lastRelativePhase;	//stored the series last relative phases
		HashMap<String, Integer> overflowCounter; 
		
		public UnwrapChart(String chartTitle, AppFrame appframe, String xAxis, String yAxis) {
			super(chartTitle,appframe, xAxis, yAxis);
			lastRelativePhase = new HashMap<String, Double>();
			overflowCounter = new HashMap<String, Integer>();
		}
		
		public void register(String seriesId, double data) {		//create new curve in chart
			super.register(seriesId, data);
			lastRelativePhase.put(seriesId, PI);	//add initial value to not jump +-2PI at the start point
			overflowCounter.put(seriesId,0);
		}
		
		public void refreshChart(double relativePhase, String seriesId, double avgPeriod) {
			XYSeries xys = dataSet.getSeries(series.indexOf(seriesId));
			double lastRF = lastRelativePhase.get(seriesId);
			if(avgPeriod == 0.0) {
				xys.add(xys.getMaxX()+1, lastRF);
			} else {
				lastRelativePhase.put(seriesId, relativePhase);
				if( lastRF - relativePhase > PI) {
					overflowCounter.put(seriesId, (overflowCounter.get(seriesId)+1));
				} else if( relativePhase - lastRF > PI) {
					overflowCounter.put(seriesId, (overflowCounter.get(seriesId)-1));
				} 
				xys.add(xys.getMaxX()+1, relativePhase + (overflowCounter.get(seriesId)*PI2));
			}
		}
	}

	AppFrame appFrame;
	Chart drwRelativePhase;
	Chart drwPeriod;
	UnwrapChart drwUnwrapPhase;

	public DrawRelativePhase(String appTitle, String chartTitle, int[] otherNode) {	//chartTitle is the reference node id
		appFrame = new AppFrame(appTitle);
		drwRelativePhase = new Chart("Relative Phase",appFrame, "Sample", "Radian");
		drwPeriod = new Chart("Period",appFrame,"Sample", "Sample");
		drwUnwrapPhase = new UnwrapChart("Unwrap Phase",appFrame, "Sample", "Radian");
		drwRelativePhase.chart.getXYPlot().getRangeAxis().setRange(0.00,2*Math.PI);
		appFrame.setAllChartRenderer();
		appFrame.pack( );          
		RefineryUtilities.centerFrameOnScreen(appFrame);          
		appFrame.setVisible(true);
		addSeriesToChart(otherNode);
	}
	
	private void addSeriesToChart(int[] otherNode) {
		for(int i : otherNode) {
			drwRelativePhase.register(i+"", 0.0);
			drwPeriod.register(i+"", 0.0);
			drwUnwrapPhase.register(i+"", 0.0); 	
		}
	}

	public void relativePhaseReceived(final double relativePhase, final double avgPeriod, final int status, int slotId, int rx1, int rx2) {
		final String str = rx2+"";
		newDataComing(relativePhase, avgPeriod, status, str);
	}
	
	public void newDataComing(final double relativePhase, final double avgPeriod, int status, final String seriesId) {
		drwRelativePhase.refreshChart(relativePhase, seriesId);
		drwPeriod.refreshChart(avgPeriod, seriesId);
		drwUnwrapPhase.refreshChart(relativePhase, seriesId,avgPeriod);
	}
	
}
