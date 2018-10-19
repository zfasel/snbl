
#include "../system.h"

typedef void (*anim_list)(void *data);
void RunnignLightsParty();
uint8_t challengeLine[] = {
  0, 0, 255, //001
  255, 255, 0, //110
  255, 0, 0, //100
  0, 255, 0, //010
  255, 0, 0, //100
  255, 0, 0, //100
  255, 0, 0, //100
  0, 0, 0, //000
  0, 255, 255, //011
  255, 0, 255, //101
  0, 255, 0, //010
  255, 255, 255, //111
  0, 0, 255, //001
  0, 0, 255, //001
  255, 0, 0, //100
  0, 255, 0, //010
  0, 255, 255, //011
  0, 0, 0, //000
  0, 255, 0, //010
  0, 255, 0, //010
  255, 255, 255, //111
  0, 0, 255, //001
  255, 0, 255, //101
  255, 255, 0, //110
  0, 255, 255, //011
  0, 0, 255, //001
  0, 255, 0, //010
  0, 255, 0, //010
  255, 255, 255, //111
  255, 0, 255, //101
  255, 0, 0, //100
  255, 0, 0, //100
  0, 255, 255, //011
  0, 0, 0, //000
  255, 255, 0, //110
  0, 255, 255, //011
  0, 0, 255, //001
  0, 0, 0, //000
  255, 255, 0,//110
  255, 255, 0,//110
  0, 255, 0, //010
  0, 255, 255,//011
  0, 0, 0, //000
  255, 255, 0, //110
  0, 0, 0, //000
  255, 0, 255, //101
  255, 0, 255, //101
  255, 255, 0, //110
  0, 255, 255, //011
  255, 255, 0,//110
  0, 255, 0, //010
  255, 255, 0, //110
  0, 0, 0, //000
  255, 0, 255, //101
  255, 255, 0, //110
  0, 255, 0, //010
  0, 255, 255, //011
  0, 0, 255, //001
  0, 0, 0 //000
};
static uint16_t challengeLen = sizeof(challengeLine);

anim_list anim_array[] = {
  meteorPartyStart,
  scrollLED,
  fadePartyStart
};

anim_list bleAnims[] = {
  rainbowPartyBLE,
  rainbowPartyBLE2,
  meteorPartyBLE,
  meteorPartyStart,
  fadePartyStart
};

anim_list sub_anim_array[] = {
  meteorPartyNext,
  scrollLEDNext,
  fadePartyNext
};

static uint8_t anim_count = 3;

uint8_t anim_pos, sub_anim_pos = 0;

void *p_timer_data = 0;

// Timer Definitions
APP_TIMER_DEF(m_led_timer);
APP_TIMER_DEF(m_autoshow_timer);
APP_TIMER_DEF(m_autoanim_timer);

uint16_t animCount1, animCount2;
uint8_t animDelay, animSpeed, animRed, animGreen, animBlue, animRed2, animGreen2, animBlue2, animVar1, animVar2 = 0;
bool animBool1, animBool2, animBool3;


// ****************************
// Automation
// ****************************

void resetTrackers() {
  animCount1 = animCount2 = 0;
  animRed = animGreen = animBlue = animRed2 = animGreen2 = animBlue2 = animVar1 = animVar2 = 0;
  animBool1 = animBool2 = animBool3 = false;
  animDelay = animSpeed = 0;
}

void startShow() {
  app_timer_stop(m_led_timer);
  app_timer_stop(m_autoshow_timer);
  app_timer_create(&m_autoshow_timer, APP_TIMER_MODE_REPEATED, nextAnim);
  app_timer_start(m_autoshow_timer, APP_TIMER_TICKS(1000*SHOW_DURATION), p_timer_data);
  anim_array[anim_pos](NULL);
}

void stopShow() {
  app_timer_stop(m_led_timer);
  util_led_clear();
}

void buttonNextAnim() {
  stopAutoShow();
  nextAnim();
}

void buttonNextSubAnim() {
  stopAutoShow();
  nextSubAnim();
}

void stopAutoShow() {
  app_timer_stop(m_autoshow_timer);
  app_timer_stop(m_autoanim_timer);
  app_timer_stop(m_led_timer);
}

void clearAnims() {
  util_led_set_all(0,0,0);
  util_led_set_all_l2(0,0,0);
}

void resetAnims() {
  sub_anim_pos = 0;
  stopAutoShow();
}

void nextAnim() {
  anim_pos++;
  if (anim_pos == anim_count) {
    anim_pos = 0;
  }
  sub_anim_pos = 0;
  util_led_clear();
  app_timer_stop(m_autoanim_timer);
  anim_array[anim_pos](NULL);
}

void nextSubAnim() {
  sub_anim_array[anim_pos](NULL);
}

void bleAnim(uint8_t whichOne) {
    util_led_clear();
    resetTrackers();
    bleAnims[whichOne](NULL);
}


// ****************************
// Color Fades
// ****************************

void fadePartyStart() {
  //resetAnims();
  app_timer_create(&m_autoanim_timer, APP_TIMER_MODE_REPEATED, fadePartyNext);
  app_timer_start(m_autoanim_timer, APP_TIMER_TICKS(2500), p_timer_data);
  fadePartyNext();
}

void fadePartyNext() {
  sub_anim_pos++;
  switch (sub_anim_pos) {
    case 1:
      FadeInOut(255,0,0,10);
      break;
    case 2:
      FadeInOut(0,0,255,10);
      break;
    case 3:
      FadeInOut(0,255,0,10);
      break;
    case 4:
      FadeInOut(255,0,255,10);
      break;
    default:
      sub_anim_pos = 0;
      fadePartyNext();
      break;
  }

}

void FadeInOutCallback() {

  util_led_set_all((animCount1/256.0)*animRed,(animCount1/256.0)*animGreen,(animCount1/256.0)*animBlue);
  util_led_show();
  if (animCount1 == 256) {
    animBool1 = true;
  } else if (animCount1 == 0) {
    animBool1 = false;
  }

  if (animBool1) {
    animCount1--;
  } else {
    animCount1++;
  }
}

void FadeInOut(uint8_t red, uint8_t green, uint8_t blue, int SpeedDelay){
  resetTrackers();
  animRed = red;
  animGreen = green;
  animBlue = blue;

  app_timer_stop(m_led_timer);
  app_timer_create(&m_led_timer, APP_TIMER_MODE_REPEATED, FadeInOutCallback);
  app_timer_start(m_led_timer, APP_TIMER_TICKS(5), p_timer_data);

 }

void FadeRed() {
  FadeInOut(255,0,0,20);
}

void FadeUrple() {
  FadeInOut(180,180,180,20);
}

// ****************************
// Strobe
// ****************************

void StrobeCallback(void *p_data) {
  if (animBool1) {
    animBool1 = false;
    util_led_set_all(0,0,0);
  } else {
    animBool1 = true;
    util_led_set_all(animRed, animGreen, animBlue);
  }
  util_led_show();
}

void StrobeBlue() {
  resetTrackers();
  animBlue = 255;
  app_timer_stop(m_led_timer);
  app_timer_create(&m_led_timer, APP_TIMER_MODE_REPEATED, StrobeCallback);
  app_timer_start(m_led_timer, APP_TIMER_TICKS(75), p_timer_data);

}

// ****************************
// SEKURITAI
// ****************************

void SecurityCallback(void *p_data) {
  animCount1++;
  if (animCount1 > 48) {
    if (animCount1%2 == 0) {
      util_led_set_all(0,0,0);
    } else if (animCount1%2 == 1) {
      util_led_set_all(200,200,200);
    }
    if (animCount1 > 63) {
      animCount1 = 0;
    }
  } else if (animCount1%2 == 0) {
    util_led_set_all(0,0,0);
  } else if (animCount1%4 == 1) {
    //util_led_set_all(0,0,0);
    util_led_set_blocks(0, 0, 255, 0, 5);
    util_led_set_blocks(255, 0, 0, 5, 5);
  } else if (animCount1%4 == 3) {
    util_led_set_blocks(255, 0, 0, 0, 5);
    util_led_set_blocks(0, 0, 255, 5, 5);
    //util_led_set_all(animRed, animGreen, animBlue);
  }
  util_led_show();
}


void Security() {
  //resetAnims();
  resetTrackers();
  animBlue = 255;
  app_timer_stop(m_led_timer);
  app_timer_create(&m_led_timer, APP_TIMER_MODE_REPEATED, SecurityCallback);
  app_timer_start(m_led_timer, APP_TIMER_TICKS(75), p_timer_data);

}


// ****************************
// Scroll LED arary
// ****************************

void scrollLEDCallback(void *p_data) {

  // TODO fix bug of zero position not printing for LED
  // check max leng
  util_led_clear();

  if (animCount1 > challengeLen/2) {
    animCount1 = 0;
  }

  uint32_t offset = 0; //index * 3;
  for (uint16_t i=animCount1; i > 0; i--) {
    if (offset < challengeLen ) {
      util_led_set_mirror(i, challengeLine[offset], challengeLine[offset+1], challengeLine[offset+2]);
    }
    offset += 3;
  }
  animCount1++;
  util_led_show();

}


void scrollLED() {
  resetTrackers();
  app_timer_stop(m_led_timer);
  app_timer_stop(m_autoanim_timer);
  app_timer_create(&m_led_timer, APP_TIMER_MODE_REPEATED, scrollLEDCallback);
  app_timer_start(m_led_timer, APP_TIMER_TICKS(50), p_timer_data);
}

void scrollLEDNext() {
  //do nothing.
  scrollLED();
}

// ****************************
// Challenge
// ****************************

void challengeStart() {
  if (challengeLen > 100) {

  }// hodler
}

// ****************************
// Rainbow Party
// ****************************

void rainbowPartyStart() {
  //stopAutoShow();
  app_timer_create(&m_autoanim_timer, APP_TIMER_MODE_REPEATED, rainbowPartyNext);
  app_timer_start(m_autoanim_timer, APP_TIMER_TICKS(2000), p_timer_data);
  rainbowPartyNext();
}

void rainbowPartyBLE() {
  rainbowCycle(15);
}
void rainbowPartyBLE2() {
  rainbowCycleSplit(15);
}

void rainbowPartyNext() {
  sub_anim_pos++;
  uint32_t speed = APP_TIMER_TICKS(1000/200);
  switch (sub_anim_pos) {
    case 1:
      rainbowCycleSplit(speed);
      break;
    case 2:
      rainbowCycle(speed);
      break;
    default:
      sub_anim_pos = 0;
      rainbowPartyNext();
      break;
  }

}

uint16_t * Wheel(uint16_t WheelPos) {
  static uint16_t c[3];
  if(WheelPos < 85) {
   c[0]=WheelPos * 3;
   c[1]=255 - WheelPos * 3;
   c[2]=0;
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   c[0]=255 - WheelPos * 3;
   c[1]=0;
   c[2]=WheelPos * 3;
  } else {
   WheelPos -= 170;
   c[0]=0;
   c[1]=WheelPos * 3;
   c[2]=255 - WheelPos * 3;
  }
  return c;
}

void rainbowCycle(uint32_t speed) {
  resetTrackers();
  app_timer_stop(m_led_timer);
  app_timer_create(&m_led_timer, APP_TIMER_MODE_REPEATED, rainbowCycleCallback);
  app_timer_start(m_led_timer, speed, p_timer_data);

  //rainbowCycleCallback(0, SpeedDelay, invert);
}
void rainbowCycleSplit(uint32_t speed) {
  resetTrackers();
  app_timer_stop(m_led_timer);
  app_timer_create(&m_led_timer, APP_TIMER_MODE_REPEATED, rainbowCycleSplitCallback);
  app_timer_start(m_led_timer, speed, p_timer_data);

  //rainbowCycleCallback(0, SpeedDelay, invert);
}

void rainbowCycleSplitCallback(void *p_data) {

  uint16_t *c;
  uint32_t i;

  if (animBool1){
    for(i=0; i< LED_COUNT_SPLIT; i++) {
      c=Wheel(((i * 256 / LED_COUNT_SPLIT) + animCount1) & 255);
        util_led_set_mirror(i, *c, *(c+1), *(c+2));
    }
  } else {
    for(i=0; i< LED_COUNT_SPLIT; i++) {
      c=Wheel(((i * 256 / LED_COUNT_SPLIT) + animCount1) & 255);
        util_led_set_mirror(LED_COUNT_SPLIT-1-i, *c, *(c+1), *(c+2));
    }
  }
  if (animCount1==256) {
    animCount1 = 0;
  }

  util_led_show();
  animCount1++;
}

void rainbowCycleCallback(void *p_data) {

  uint16_t *c;
  uint32_t i;

  if (animBool1){
    for(i=0; i< LED_COUNT; i++) {
      c=Wheel(((i * 256 / LED_COUNT) + animCount1) & 255);
        util_led_set(i, *c, *(c+1), *(c+2));
    }
  } else {
    for(i=0; i< LED_COUNT; i++) {
      c=Wheel(((i * 256 / LED_COUNT) + animCount1) & 255);
        util_led_set(LED_COUNT-1-i, *c, *(c+1), *(c+2));
    }
  }
  if (animCount1==256) {
    animCount1 = 0;
  }

  util_led_show();
  animCount1++;
}

// ****************************
// Meteor
// ****************************


void meteorParty(uint8_t red, uint8_t green, uint8_t blue, uint8_t red2, uint8_t green2, uint8_t blue2, uint8_t tail, uint8_t decay, uint8_t speed) {
  animRed = red;
  animBlue = blue;
  animGreen = green;
  animRed2 = red2;
  animBlue2 = blue2;
  animGreen2 = green2;
  animVar1 = tail;
  animVar2 = decay;
  app_timer_stop(m_led_timer);
  app_timer_create(&m_led_timer, APP_TIMER_MODE_REPEATED, meteorRainCallback);
  app_timer_start(m_led_timer, APP_TIMER_TICKS(speed), p_timer_data);
}

void meteorPartyStart() {
  resetTrackers();
  util_led_clear();
  app_timer_create(&m_autoanim_timer, APP_TIMER_MODE_REPEATED, meteorPartyNext);
  app_timer_start(m_autoanim_timer, APP_TIMER_TICKS(4000), p_timer_data);
  meteorPartyNext();
  //stopAutoShow();
//  meteorPartyStart();
}

void meteorPartyNext() {
  sub_anim_pos++;
  switch (sub_anim_pos) {
    case 1:
      animBool1 = false;
      meteorParty(0,0,255,128,0,0,5,50, 15);
      break;
    case 2:
      animBool1 = true;
      meteorParty(255,0,0,0,0,128,10,50, 15);
      break;
    case 3:
      animBool1 = true;
      meteorParty(200,200,200,120,0,50,5,50,25);
      break;
    case 4:
      animBool1 = true;
      meteorParty(200,200,200,0,128,0,10,50, 15);
      break;
    default:
      sub_anim_pos = 0;
      meteorPartyNext();
      break;
  }
}

void meteorPartyBLE() {
  animBool1 = true;
  meteorParty(200,200,200,120,0,50,5,50,25);
}

void fadeToBlack(uint16_t ledNo, uint8_t fadeValue) {
    // NeoPixel
    led_rgb_t oldColor;
    uint8_t r, g, b;

    oldColor = util_led_get(ledNo);
    r = oldColor.red;
    g = oldColor.green;
    b = oldColor.blue;

    r=(r<=10)? 0 : (int) r-(r*fadeValue/256);
    g=(g<=10)? 0 : (int) g-(g*fadeValue/256);
    b=(b<=10)? 0 : (int) b-(b*fadeValue/256);

    util_led_set(ledNo, r,g,b);

//   leds[ledNo].FBy( fadeValue );

}

void meteorRainCallback() {
  util_led_set_all_l2(animRed2,animGreen2,animBlue2);

  if (animCount1 > LED_COUNT+LED_COUNT) {
    animCount1 = 0;
  }
//  for(int i = 0; i < LED_COUNT+LED_COUNT; i++) {
    // fade brightness all LEDs one step
    for(int j=0; j<LED_COUNT; j++) {
      if( (!animBool2) || (util_math_rand8_max(10)>5) ) {
        fadeToBlack(j, animVar2 );
        if (animBool1) {
          fadeToBlack(LED_COUNT-j-1, animVar2 );
        }
      }
    }

    // draw meteor
    for(int j = 0; j < animVar1; j++) {
      if( ( animCount1-j <LED_COUNT) && (animCount1-j>=0) ) {
          if (animBool1) {
            util_led_set_mirror(animCount1-j, animRed, animGreen, animBlue);
          } else {
            util_led_set(animCount1-j, animRed, animGreen, animBlue);
          }
      }
    }

    animCount1++;
    util_led_show();
    //nrf_delay_ms(SpeedDelay);
//  }
}









// ****************************
// Cylon
// ****************************

void CylonBounce(uint8_t red, uint8_t green, uint8_t blue, int EyeSize, int SpeedDelay, int ReturnDelay) {

  for(int i = 0; i < LED_COUNT-EyeSize-2; i++) {
    util_led_set_all(0,0,0);
    util_led_set(i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      util_led_set(i+j, red, green, blue);
    }
    util_led_set(i+EyeSize+1, red/10, green/10, blue/10);
    util_led_show();
    nrf_delay_ms(SpeedDelay);
  }

  nrf_delay_ms(ReturnDelay);

  for(int i = LED_COUNT-EyeSize-2; i > 0; i--) {
    util_led_set_all(0, 0, 0);
    util_led_set(i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      util_led_set(i+j, red, green, blue);
    }
    util_led_set(i+EyeSize+1, red/10, green/10, blue/10);
    util_led_show();
    nrf_delay_ms(SpeedDelay);
  }

  nrf_delay_ms(ReturnDelay);

}


// ****************************
// Fire
// ****************************


void setPixelHeatColor (uint8_t Pixel, uint8_t temperature) {
  // Scale 'heat' down from 0-255 to 0-191
  uint8_t t192 = temperature-50;

  // calculate ramp up from
  uint8_t heatramp = t192 & 0x3F; // 0..63
  //heatramp <<= 2; // scale up to 0..252

  // figure out which third of the spectrum we're in:
  if( t192 > 0x80) {                     // hottest
    util_led_set(Pixel, 255, 255, heatramp);
  } else if( t192 > 0x40 ) {             // middle
    util_led_set(Pixel, 255, heatramp, 0);
  } else {                               // coolest
    util_led_set(Pixel, heatramp, 0, 0);
  }
}

void Fire() {

  static uint8_t heat[LED_COUNT];
  uint8_t cooldown;

  // Step 1.  Cool down every cell a little
  for( int i = 0; i < LED_COUNT; i++) {
    cooldown = util_math_rand8_max(((animVar1 * 10) / LED_COUNT) + 2);

    if(cooldown>heat[i]) {
      heat[i]=0;
    } else {
      heat[i]=heat[i]-cooldown;
    }
  }

  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for( int k= LED_COUNT - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
  }

  // Step 3.  Randomly ignite new 'sparks' near the bottom
  if( util_math_rand8_max(255) < animVar2 ) {
    uint8_t y = util_math_rand8_max(7);
    heat[y] = heat[y] + (util_math_rand8_max(160)+95);
    //heat[y] = random(160,255);
  }

  // Step 4.  Convert heat to LED colors
  for( int j = 0; j < LED_COUNT; j++) {
    setPixelHeatColor(j, heat[j] );
  }

  util_led_show();
  //delay(SpeedDelay);
}


void FireParty() {
  uint8_t speed = 15;
  animVar1 = 55;
  animVar2 = 120;
  resetTrackers();
  app_timer_stop(m_led_timer);
  app_timer_create(&m_led_timer, APP_TIMER_MODE_REPEATED, Fire);
  app_timer_start(m_led_timer, APP_TIMER_TICKS(speed), p_timer_data);
}
void FireNext() {

}


// ****************************
// Marquee
// ****************************

static const uint8_t  _sineTable[256] = {
  128,131,134,137,140,143,146,149,152,155,158,162,165,167,170,173,
  176,179,182,185,188,190,193,196,198,201,203,206,208,211,213,215,
  218,220,222,224,226,228,230,232,234,235,237,238,240,241,243,244,
  245,246,248,249,250,250,251,252,253,253,254,254,254,255,255,255,
  255,255,255,255,254,254,254,253,253,252,251,250,250,249,248,246,
  245,244,243,241,240,238,237,235,234,232,230,228,226,224,222,220,
  218,215,213,211,208,206,203,201,198,196,193,190,188,185,182,179,
  176,173,170,167,165,162,158,155,152,149,146,143,140,137,134,131,
  128,124,121,118,115,112,109,106,103,100, 97, 93, 90, 88, 85, 82,
   79, 76, 73, 70, 67, 65, 62, 59, 57, 54, 52, 49, 47, 44, 42, 40,
   37, 35, 33, 31, 29, 27, 25, 23, 21, 20, 18, 17, 15, 14, 12, 11,
   10,  9,  7,  6,  5,  5,  4,  3,  2,  2,  1,  1,  1,  0,  0,  0,
    0,  0,  0,  0,  1,  1,  1,  2,  2,  3,  4,  5,  5,  6,  7,  9,
   10, 11, 12, 14, 15, 17, 18, 20, 21, 23, 25, 27, 29, 31, 33, 35,
   37, 40, 42, 44, 47, 49, 52, 54, 57, 59, 62, 65, 67, 70, 73, 76,
   79, 82, 85, 88, 90, 93, 97,100,103,106,109,112,115,118,121,124
 };

 uint8_t mySin(uint16_t pos) {
   return _sineTable[pos%256];
 }


void RunningLights() {
  uint16_t Position=0;

  for(int j=0; j<LED_COUNT*2; j++)
  {
      Position++; // = 0; //Position + Rate;
      for(int i=0; i<LED_COUNT; i++) {
        // sine wave, 3 offset waves make a rainbow!
        //float level = sin(i+Position) * 127 + 128;
        //setPixel(i,level,0,0);
        //float level = sin(i+Position) * 127 + 128;
        util_led_set(i,(int)((mySin(i+Position) * 127 + 128)/255)*animRed,
                   (int)((mySin(Position) * 127 + 128)/255)*animGreen,
                   (int)((mySin(i+Position) * 127 + 128)/255)*animBlue);
      }
      util_led_show();
  }
}


void RunnignLightsParty() {
  resetTrackers();
  animRed=255;
  animSpeed=30;
  app_timer_stop(m_led_timer);
  app_timer_create(&m_led_timer, APP_TIMER_MODE_REPEATED, RunningLights);
  app_timer_start(m_led_timer, APP_TIMER_TICKS(animSpeed), p_timer_data);
}
