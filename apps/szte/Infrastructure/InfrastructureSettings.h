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

#define FOUR_MOTE 2
#define FOUR_MOTE_WF 3
#define PHASEMAP_TEST_13 4
#define PHASEMAP_TEST_18 5
#define PROCESSING_DEBUG 6
#define PHASEMAP_TEST_4 7
#define FOURTEEN_MOTE_WF 8
#define PHASEMAP_TEST_6 9

#ifndef MEASURE_TYPE
#error "Please define MEASURE_TYPE"
#endif

#if MEASURE_TYPE == FOUR_MOTE
	#define  NUMBER_OF_INFRAST_NODES 4
	#define NUMBER_OF_SLOTS 16
	#define NUMBER_OF_RX 6
	const_uint8_t motesettings[NUMBER_OF_INFRAST_NODES][NUMBER_OF_SLOTS] = {
		//  0     1     2     3     4     5     6     7     8     9    10    11    12    13    14    15 
		{SSYN,  TX1,   RX,   RX, RSYN,  TX1,   RX,   RX, RSYN,  TX1,   RX,   RX, RSYN,  TX1,  TX1,  TX1},
		{RSYN,  TX2,  TX1,  TX1, SSYN,   RX,  TX1,   RX, RSYN,   RX,  TX1,   RX, RSYN,  TX2,   RX,   RX},
		{RSYN,   RX,  TX2,   RX, RSYN,  TX2 , TX2 , TX1, SSYN,   RX,   RX,  TX1, RSYN,   RX,  TX2,   RX},
		{RSYN,   RX,   RX,  TX2, RSYN,   RX,   RX,  TX2, RSYN,  TX2,  TX2,  TX2, SSYN,   RX,   RX,  TX2}
	};
#elif MEASURE_TYPE == FOUR_MOTE_WF
	#define  NUMBER_OF_INFRAST_NODES 4
	#define NUMBER_OF_SLOTS 24
	#define NUMBER_OF_RX 6
	const_uint8_t motesettings[NUMBER_OF_INFRAST_NODES][NUMBER_OF_SLOTS] = {
		//  0     1     2     3     4     5     6     7     8     9    10    11    12    13    14    15    16    17    18    19    20    21    22    23  
		{SSYN,  TX1,   RX,   RX, RSYN,  TX1,   RX,   RX, RSYN,  TX1,   RX,   RX, RSYN,  TX1,  TX1,  TX1, DSYN,  DEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{RSYN,  TX2,  TX1,  TX1, SSYN,   RX,  TX1,   RX, RSYN,   RX,  TX1,   RX, RSYN,  TX2,   RX,   RX, RSYN, NDEB, DSYN,  DEB, RSYN, NDEB, RSYN, NDEB},
		{RSYN,   RX,  TX2,   RX, RSYN,  TX2 , TX2 , TX1, SSYN,   RX,   RX,  TX1, RSYN,   RX,  TX2,   RX, RSYN, NDEB, RSYN, NDEB, DSYN,  DEB, RSYN, NDEB},
		{RSYN,   RX,   RX,  TX2, RSYN,   RX,   RX,  TX2, RSYN,  TX2,  TX2,  TX2, SSYN,   RX,   RX,  TX2, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, DSYN,  DEB}
	};
#elif MEASURE_TYPE == SIX_MOTE_WF
	#define  NUMBER_OF_INFRAST_NODES 6
	#define NUMBER_OF_SLOTS 48
	#define NUMBER_OF_RX 20
	const_uint8_t motesettings[NUMBER_OF_INFRAST_NODES][NUMBER_OF_SLOTS] = {
		//    0     1     2     3     4     5     6     7     8     9    10    11    12    13    14    15    16    17    18    19    20    21    22    23    24    25    26    27    28    29    30    31    32    33    34    35    36    37    38    39    40    41    42    43    44    45    46    47 
		{  SSYN,  TX1,   RX,   RX,   RX,   RX, RSYN,  TX1,   RX,   RX,   RX,   RX, RSYN,  TX1,   RX,   RX,   RX,   RX, RSYN,  TX1,   RX,   RX,   RX,   RX, RSYN,  TX1,   RX,   RX,   RX,   RX, RSYN,  TX2,  TX2,  TX2,  TX2,  TX2, DSYN,  DEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{  RSYN,  TX2,  TX1,  TX1,  TX1,  TX1, SSYN,   RX,  TX2,   RX,   RX,   RX, RSYN,   RX,  TX2,   RX,   RX,   RX, RSYN,   RX,  TX2,   RX,   RX,   RX, RSYN,   RX,  TX2,   RX,   RX,   RX, RSYN,  TX1,   RX,   RX,   RX,   RX, RSYN, NDEB, DSYN,  DEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{  RSYN,   RX,  TX2,   RX,   RX,   RX, RSYN,  TX2,  TX1,  TX1,  TX1,  TX1, SSYN,   RX,   RX,  TX2,   RX,   RX, RSYN,   RX,   RX,  TX2,   RX,   RX, RSYN,   RX,   RX,  TX2,   RX,   RX, RSYN,   RX,  TX1,   RX,   RX,   RX, RSYN, NDEB, RSYN, NDEB, DSYN,  DEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB},
		{  RSYN,   RX,   RX,  TX2,   RX,   RX, RSYN,   RX,   RX,  TX2,   RX,   RX, RSYN,  TX2,  TX1,  TX1,  TX1,  TX1, SSYN,   RX,   RX,   RX,  TX2,   RX, RSYN,   RX,   RX,   RX,  TX2,   RX, RSYN,   RX,   RX,  TX1,   RX,   RX, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, DSYN,  DEB, RSYN, NDEB, RSYN, NDEB},
		{  RSYN,   RX,   RX,   RX,  TX2,   RX, RSYN,   RX,   RX,   RX,  TX2,   RX, RSYN,   RX,   RX,   RX,  TX2,   RX, RSYN,  TX2,  TX1,  TX1,  TX1,  TX1, SSYN,   RX,   RX,   RX,   RX,  TX2, RSYN,   RX,   RX,   RX,  TX1,   RX, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, DSYN,  DEB, RSYN, NDEB},
		{  RSYN,   RX,   RX,   RX,   RX,  TX2, RSYN,   RX,   RX,   RX,   RX,  TX2, RSYN,   RX,   RX,   RX,   RX,  TX2, RSYN,   RX,   RX,   RX,   RX,  TX2, RSYN,  TX2,  TX1,  TX1,  TX1,  TX1, SSYN,   RX,   RX,   RX,   RX,  TX1, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, RSYN, NDEB, DSYN,  DEB}
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
	#define NUMBER_OF_SLOTS 19
	#define NUMBER_OF_RX 1	
	const_uint8_t motesettings[NUMBER_OF_INFRAST_NODES][NUMBER_OF_SLOTS] = {
		{ DSYN, TX1, W100, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN},
		{ RSYN, TX2, W100, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN},
		{ RSYN,  RX, W100, SSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN},
		{ RSYN,  RX, W100, RSYN, SSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN},
		{ RSYN,  RX, W100, RSYN, RSYN, SSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN},
		{ RSYN,  RX, W100, RSYN, RSYN, RSYN, SSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN},
		{ RSYN,  RX, W100, RSYN, RSYN, RSYN, RSYN, SSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN},
		{ RSYN,  RX, W100, RSYN, RSYN, RSYN, RSYN, RSYN, SSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN},
		{ RSYN,  RX, W100, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, SSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN},
		{ RSYN,  RX, W100, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, SSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN},
		{ RSYN,  RX, W100, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, SSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN},
		{ RSYN,  RX, W100, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, SSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN},
		{ RSYN,  RX, W100, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, SSYN, RSYN, RSYN, RSYN, RSYN, RSYN},
		{ RSYN,  RX, W100, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, SSYN, RSYN, RSYN, RSYN, RSYN},
		{ RSYN,  RX, W100, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, SSYN, RSYN, RSYN, RSYN},
		{ RSYN,  RX, W100, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, SSYN, RSYN, RSYN},
		{ RSYN,  RX, W100, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, SSYN, RSYN},
		{ RSYN,  RX, W100, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, RSYN, SSYN}
	};
#elif MEASURE_TYPE == PHASEMAP_TEST_6
	#define  NUMBER_OF_INFRAST_NODES 6
	#define NUMBER_OF_SLOTS 7
	#define NUMBER_OF_RX 1
	const_uint8_t motesettings[NUMBER_OF_INFRAST_NODES][NUMBER_OF_SLOTS] = {	
    { DSYN, TX1, W100, RSYN, RSYN, RSYN, RSYN},
    { RSYN, TX2, W100, RSYN, RSYN, RSYN, RSYN},
    { RSYN,  RX, W100, SSYN, RSYN, RSYN, RSYN},
    { RSYN,  RX, W100, RSYN, SSYN, RSYN, RSYN},
    { RSYN,  RX, W100, RSYN, RSYN, SSYN, RSYN},
    { RSYN,  RX, W100, RSYN, RSYN, RSYN, SSYN}
	};
#elif MEASURE_TYPE == PHASEMAP_TEST_4
	#define  NUMBER_OF_INFRAST_NODES 4
	#define NUMBER_OF_SLOTS 7
	#define NUMBER_OF_RX 1
	const_uint8_t motesettings[NUMBER_OF_INFRAST_NODES][NUMBER_OF_SLOTS] = {	
		{ DSYN, TX1, W100, RSYN, NDEB, RSYN, NDEB},
		{ RSYN, TX2, W100, RSYN, NDEB, RSYN, NDEB},
		{ RSYN,  RX, W100, SSYN,  DEB, RSYN, NDEB},
		{ RSYN,  RX, W100, RSYN, NDEB, SSYN,  DEB}
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
