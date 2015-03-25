
//Ghost code based on the following
// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

// Which pin on the Arduino is connected to the Neostrip?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many Neostrip are attached to the Arduino?
#define NUMPIXELS      7

// When we setup the NeoPixel library, we tell it how many strip, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


//Colors
uint32_t red = strip.Color(255, 0, 0);
uint32_t blue = strip.Color(0, 0, 255);
uint32_t green = strip.Color(0, 255, 0);
uint32_t black = strip.Color(0, 0, 0);

int delayval = 1000; // delay for second
int delayBetweenHunt = 4000;

void setup() {
  strip.begin(); // This initializes the NeoPixel library.
  strip.show(); // Initialize all strip to 'off'
}

void loop() {
  strip.setBrightness(255);
  hunting(red, 50);
  delay(delayBetweenHunt);
  beingHunted(blue, delayval);
  delay(delayval/2);
}

// When hunting stay on normal color
void hunting(uint32_t c, uint8_t wait) {
    for (int i=0; i < strip.numPixels(); i=i+1) {
      strip.setPixelColor(i, c); 
    }
    strip.show();
    delay(wait);
}


//When Being Hunted
void beingHunted(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of blinking
    for (int i=0; i < strip.numPixels(); i=i+1) {
      strip.setPixelColor(i, c);    //turn every pixel on
    }
    strip.show();
   
    delay(wait);
    strip.setBrightness(5);
    strip.show();
    delay(wait);
    strip.setBrightness(250);
    strip.show();
  }
}
