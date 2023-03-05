/*
  Display "flicker free" scrolling text and updating number

  Example for library:
  https://github.com/Bodmer/TFT_eSPI

  The sketch has been tested on a 320x240 ILI9341 based TFT, it
  could be adapted for other screen sizes.

  A Sprite is notionally an invisible graphics screen that is
  kept in the processors RAM. Graphics can be drawn into the
  Sprite just as it can be drawn directly to the screen. Once
  the Sprite is completed it can be plotted onto the screen in
  any position. If there is sufficient RAM then the Sprite can
  be the same size as the screen and used as a frame buffer.

  The Sprite occupies (2 * width * height) bytes.

  On a ESP8266 Sprite sizes up to 128 x 160 can be accommodated,
  this size requires 128*160*2 bytes (40kBytes) of RAM, this must be
  available or the processor will crash. You need to make the sprite
  small enough to fit, with RAM spare for any "local variables" that
  may be needed by your sketch and libraries.

  Created by Bodmer 15/11/17

  #########################################################################
  ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
  #########################################################################
*/

// Size of sprite image for the scrolling text, this requires ~14 Kbytes of RAM
#define IWIDTH  240
#define IHEIGHT 200

// Pause in milliseconds to set scroll speed
#define WAIT 0

#include <TFT_eSPI.h>                 // Include the graphics library (this includes the sprite functions)

TFT_eSPI    tft = TFT_eSPI();         // Create object "tft"

TFT_eSprite img = TFT_eSprite(&tft);  // Create Sprite object "img" with pointer to "tft" object
//                                    // the pointer is used by pushSprite() to push it onto the TFT

// -------------------------------------------------------------------------
// Setup
// -------------------------------------------------------------------------
void setup(void) {
  tft.init();
  tft.setRotation(1);

  tft.fillScreen(TFT_WHITE);
}

// -------------------------------------------------------------------------
// Main loop
// -------------------------------------------------------------------------
void loop() {

  tft.drawString(" My commute to uni:     ", 0, 0, 4);

  while (1)
  {
    // Create the sprite and clear background to black
    img.createSprite(IWIDTH, IHEIGHT);

    for (int pos = IWIDTH; pos > -4870 ; pos--)
    {
      build_banner("My commute: startInG-->MyrtleWilloughby--->Bedford-NostrandAvs--->ClassonAv--->Clinton-WashingtonAvs"
                  "--->FultonSt--->HoytSchermerhornSts--transferToA-->JaySt-MetroTech--->HighSt--->FultonSt--->ChambersSt"
                  "--->CanalSt--->W4St-WashSq--->14St/8Av--->34StPennStation--->42StPortAuthority--->59StColumbusCircle--"
                  "transferTo1-->66StLincolnCenter--->72St--->96St--->103St--->110St--->116StColumbiaUniversity--Arrive!!", pos);
      img.pushSprite(0, 67);

      delay(WAIT);
    }

    // Delete sprite to free up the memory
    img.deleteSprite();

  }
}

// #########################################################################
// Build the scrolling sprite image from scratch, draw text at x = xpos
// #########################################################################

void build_banner(String msg, int xpos)
{
  int h = IHEIGHT;

  // We could just use fillSprite(color) but lets be a bit more creative...
  img.fillSprite(TFT_WHITE);


  img.setTextSize(1);           // Font size scaling is x1
  img.setTextFont(4);           // Font 4 selected
  img.setTextColor(TFT_BLACK);  // Black text, no background colour
  img.setTextWrap(false);       // Turn of wrap so we can print past end of sprite

  // Need to print msg
  img.setCursor(xpos, 2);  // Print text at xpos
  img.print(msg);

}

