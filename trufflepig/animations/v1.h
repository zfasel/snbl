
#include "../system.h"

#ifndef ANIMATIONS_V1_H_
#define ANIMATIONS_V1_H_

extern void FadeInOut(uint8_t red, uint8_t green, uint8_t blue, int SpeedDelay);
extern void FadeInOutCallback();
extern void CylonBounce(uint8_t red, uint8_t green, uint8_t blue, int EyeSize, int SpeedDelay, int ReturnDelay);
extern uint16_t * Wheel(uint16_t WheelPos);
extern void rainbowCycle();
extern void rainbowCycleCallback(void *p_data);
extern void stopShow();
extern void startShow();
extern void FadeRed();
extern void nextAnim();
extern void nextSubAnim();
extern void resetTrackers();
extern void FadeUrple();
extern void buttonNextAnim();
extern void buttonNextSubAnim();
extern void StrobeBlue();
extern void Security();
extern void stopAutoShow();
extern void rainbowCycleSplitCallback(void *p_data);
extern void rainbowCycleSplit();
extern void testAnim();
extern void rainbowPartyStart();
extern void rainbowPartyNext();
extern void fadePartyStart();
extern void fadePartyNext();
extern void resetAnims();
extern void scrollLED();
extern void scrollLEDNext();
extern void meteorPartyStart();
extern void meteorPartyNext();
extern void bleAnim(uint8_t whichOne);
extern void rainbowPartyBLE();
extern void meteorRainCallback();
extern void meteorParty(uint8_t red, uint8_t green, uint8_t blue, uint8_t red2, uint8_t green2, uint8_t blue2, uint8_t tail, uint8_t decay, uint8_t speed);
extern void FireParty();
extern void rainbowPartyBLE();
extern void rainbowPartyBLE2();
extern void meteorPartyBLE();
#endif
