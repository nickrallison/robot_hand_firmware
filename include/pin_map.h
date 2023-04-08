#define FLEX_MIN 150 // This is the 'minimum' pulse length count (out of 4096)
#define FLEX_MAX 500 // This is the 'maximum' pulse length count (out of 4096)
#define PINKY_FLEX_MAX 520 // This is the 'maximum' pulse length count (out of 4096)

#define FLEX_MAX_THUMB 600
#define FLEX_MIN_THUMB 170

#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

#define INDEX_S2S 0
#define INDEX_FLEX 1
#define MIDDLE_FLEX 2
#define THUMB_S2S 3
#define THUMB_FLEX 4
#define MIDDLE_S2S 5
#define RING_FLEX 6
#define RING_S2S 7
#define PINKY_S2S 8
#define PINKY_FLEX 9

#define PINKY_NEUTRAL 240
#define PINKY_L (PINKY_NEUTRAL - 10)
#define PINKY_R (PINKY_NEUTRAL + 10)

#define RING_NEUTRAL 263
#define RING_L (RING_NEUTRAL - 10)
#define RING_R (RING_NEUTRAL + 10)

#define MIDDLE_NEUTRAL 245
#define MIDDLE_L (MIDDLE_NEUTRAL - 10)
#define MIDDLE_R (MIDDLE_NEUTRAL + 10)

#define INDEX_NEUTRAL 230
#define INDEX_L (INDEX_NEUTRAL - 10)
#define INDEX_R (INDEX_NEUTRAL + 10)

#define THUMB_R 290
#define THUMB_L 210