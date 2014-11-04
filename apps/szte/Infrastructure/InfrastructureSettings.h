#ifndef __INFRASTRUCTURESETTINGS_H__
#define __INFRASTRUCTURESETTINGS_H__

enum {
	TX1 = 0, //sendWave 1
	TX2 = 1, //sendWave 1
	RX = 2, //sampleRSSI
	SSYN=3, //sends sync message
	RSYN=4, //waits for sync message  
	DEB = 5,
	NTRX = 6,
	NDEB = 7,
	W1 = 8,
	W10 = 9,
	W100 = 10,
  DSYN = 11,
	WCAL = 12,
};

#define FOUR_MOTE 0
#define FOUR_MOTE_WF 1
#define PHASEMAP_TEST_13 2
#define PHASEMAP_TEST_18 3
#define PROCESSING_DEBUG 4

#ifndef MEASURE_TYPE
#error "Please define MEASURE_TYPE"
#endif

#if MEASURE_TYPE == FOUR_MOTE
	#define  NUMBER_OF_INFRAST_NODES 4
	#define NUMBER_OF_SLOTS 20
	#define NUMBER_OF_RX 6
	const_uint8_t motesettings[NUMBER_OF_INFRAST_NODES][NUMBER_OF_SLOTS] = {
		//  0     1     2     3     4     5     6     7     8     9    10    11    12    13    14    15    16    17    18    19
		{SSYN,  TX1,   RX,   RX, WCAL, RSYN,  TX1,   RX,   RX, WCAL, RSYN,  TX1,   RX,   RX, WCAL, RSYN,  TX1,  TX1,  TX1, WCAL},
		{RSYN,  TX2,  TX1,  TX1, WCAL, SSYN,   RX,  TX1,   RX, WCAL, RSYN,   RX,  TX1,   RX, WCAL, RSYN,  TX2,   RX,   RX, WCAL},
		{RSYN,   RX,  TX2,   RX, WCAL, RSYN,  TX2 , TX2 , TX1, WCAL, SSYN,   RX,   RX,  TX1, WCAL, RSYN,   RX,  TX2,   RX, WCAL},
		{RSYN,   RX,   RX,  TX2, WCAL, RSYN,   RX,   RX,  TX2, WCAL, RSYN,  TX2,  TX2,  TX2, WCAL, SSYN,   RX,   RX,  TX2, WCAL}
	};
#elif MEASURE_TYPE == FOUR_MOTE_WF
	#define  NUMBER_OF_INFRAST_NODES 4
	#define NUMBER_OF_SLOTS 56
	#define NUMBER_OF_RX 6
	const_uint8_t motesettings[NUMBER_OF_INFRAST_NODES][NUMBER_OF_SLOTS] = {
		//  0     1     2     3     4     5     6     7     8     9    10    11    12    13    14    15    16    17    18    19    20    21    22    23    24    25    26    27    28    29    30    31    32    33    34    35    36    37    38    39    40    41    42    43    44    45    46    47    48    49    50    51    52    53    54    55
		{SSYN,  TX1,   RX,   RX, WCAL, RSYN,  TX1,   RX,   RX, WCAL, RSYN,  TX1,   RX,   RX, WCAL, RSYN,  TX1,  TX1,  TX1, WCAL, DSYN,  DEB,  DEB, DSYN,  DEB,  DEB, DSYN,  DEB,  DEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB},
		{RSYN,  TX2,  TX1,  TX1, WCAL, SSYN,   RX,  TX1,   RX, WCAL, RSYN,   RX,  TX1,   RX, WCAL, RSYN,  TX2,   RX,   RX, WCAL, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, DSYN,  DEB,  DEB, DSYN,  DEB,  DEB, DSYN,  DEB,  DEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB},
		{RSYN,   RX,  TX2,   RX, WCAL, RSYN,  TX2 , TX2 , TX1, WCAL, SSYN,   RX,   RX,  TX1, WCAL, RSYN,   RX,  TX2,   RX, WCAL, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, DSYN,  DEB,  DEB, DSYN,  DEB,  DEB, DSYN,  DEB,  DEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB},
		{RSYN,   RX,   RX,  TX2, WCAL, RSYN,   RX,   RX,  TX2, WCAL, RSYN,  TX2,  TX2,  TX2, WCAL, SSYN,   RX,   RX,  TX2, WCAL, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, RSYN, NDEB, NDEB, DSYN,  DEB,  DEB, DSYN,  DEB,  DEB, DSYN,  DEB,  DEB}
	};
#elif MEASURE_TYPE == PHASEMAP_TEST_13
	#define  NUMBER_OF_INFRAST_NODES 13
	#define NUMBER_OF_SLOTS 24
	#define NUMBER_OF_RX 1
	const_uint8_t motesettings[NUMBER_OF_INFRAST_NODES][NUMBER_OF_SLOTS] = {
		{ DSYN, TX1, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN, TX2, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, SSYN,  DEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, RSYN, NDEB, SSYN,  DEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, RSYN, NDEB, RSYN, NDEB, SSYN,  DEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, SSYN,  DEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, SSYN,  DEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, SSYN,  DEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, SSYN,  DEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, SSYN,  DEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, SSYN,  DEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, SSYN,  DEB, RSYN, NDEB},
		{ RSYN,  RX, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, SSYN,  DEB}
	};
#elif MEASURE_TYPE == PHASEMAP_TEST_18
	#define  NUMBER_OF_INFRAST_NODES 18
	#define NUMBER_OF_SLOTS 34
	#define NUMBER_OF_RX 1	
	const_uint8_t motesettings[NUMBER_OF_INFRAST_NODES][NUMBER_OF_SLOTS] = {
		{ DSYN, TX1, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN, TX2, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, SSYN,  DEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, RSYN, NDEB, SSYN,  DEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, RSYN, NDEB, RSYN, NDEB, SSYN,  DEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, SSYN,  DEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, SSYN,  DEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, SSYN,  DEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, SSYN,  DEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, SSYN,  DEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, SSYN,  DEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, SSYN,  DEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, SSYN,  DEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, SSYN,  DEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, SSYN,  DEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, SSYN,  DEB, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, SSYN,  DEB, RSYN, NDEB},
		{ RSYN,  RX, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, SSYN,  DEB}
	};
#elif MEASURE_TYPE == PROCESSING_DEBUG
	//for processing debug it falls out of sync!
	#define  NUMBER_OF_INFRAST_NODES 4
	#define NUMBER_OF_SLOTS 7
	#define NUMBER_OF_RX 1
	const_uint8_t motesettings[NUMBER_OF_INFRAST_NODES][NUMBER_OF_SLOTS] = {
		//  0     1     2     3     4     5     6     7     8     9    10    11    12    13    14    15    16    17    18    19
		{SSYN,   RX,  W10,  W10,  DEB,  W10,  W10},
		{RSYN,  TX1,  W10,  W10, NDEB,  W10,  W10},
		{RSYN,  TX2,  W10,  W10, NDEB,  W10,  W10},
		{RSYN, NTRX,  W10,  W10, NDEB,  W10,  W10}
	};
#else
	#error "Unknown MEASURE_TYPE"
#endif

#endif
