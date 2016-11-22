/// @file atmega328_mcs12085_V01.ino
/// 
/// @brief Example code to set up and use MCS-12085/12086 optical 
/// mouse IC.
///
/// Tested with Logitech PS/2 mouse (model: SBF-96) using Arduino Uno. 
/// According to Graham-Cumming, who wrote the library, the sensor has 
/// a default accuracy of 1,000 dpi so it will overflow in either 
/// direction if the sensor moves more than 3.2mm in any direction.
///
/// Setup:
/// Ignore the PS/2 connections and solder on directly to the board.
/// Cut away SDIO and SCLK traces connecting MCS-12085 and Logitech
/// controller IC. This way, the Logitech controller IC is bypassed
/// and the Arduino communicates directly with the MCS-12085.
///
/// pin 7 VDD  -> Arduino 5V
/// pin 6 GND  -> Arduino GND
/// pin 3 SDIO -> Arduino pin 7
/// pin 4 SCK  -> Arduino pin 4
///
///
/// MCS-12085 pinout:
///              _______       
/// LED_CNTL 5 =|       |= 4 SCK
///      GND 6 =|       |= 3 SDIO
///      VDD 7 =|       |= 2 OSC_OUT
///     REFA 8 =|_______|= 1 OSC_IN
///
/// References:
/// MCS-12085 data sheet: http://d1.amobbs.com/bbs_upload782111/files_19/ourdev_489767.pdf
/// John Graham-Cumming's blog: http://blog.jgc.org/2012/09/conversion-of-cheap-optical-mouse-to.html
/// Arduino interface for MCS-12085 by John Graham-Cumming: https://github.com/jgrahamc/mcs12085
///
/// Created 21 Nov 2016
///
/// @author Mustafa Ghazi
///
#include "mcs-12085.h"

int xVal, yVal;

void setup() {
  Serial.begin(115200);
  mcs12085_init();

}

void loop() {

  // delay < 28 ms doesn't seem to work
  delay(28);
  // calling these in quick succession seems to work faster
  xVal = mcs12085_dx(); // distance moved in dots (-127 to 128)
  yVal = mcs12085_dy(); // distance moved in dots (-127 to 128)
  Serial.print("dx=");
  Serial.print(xVal);
  Serial.print(", dy=");
  Serial.println(yVal);  

}
