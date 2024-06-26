#include <SPI.h>       
#include <DMD.h>    
#include <TimerOne.h>  
#include "Arial_black_16.h"
#include "Arial_Black_16_ISO_8859_1.h"
#include "Arial14.h"
#include "SystemFont5x7.h"


#define DISPLAYS_ACROSS 2 //-> Number of P10 panels used, side to side.
#define DISPLAYS_DOWN 1
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);

char *Text = "";

void ScanDMD() { 
  dmd.scanDisplayBySPI();
}

void setup(void) {
  Timer1.initialize(1000);          
  Timer1.attachInterrupt(ScanDMD);   
  dmd.clearScreen(true);   
  Serial.begin(115200);
}

void loop(void) {
  //dmd.selectFont(Arial_Black_16_ISO_8859_1);
  //dmd.selectFont(Arial_Black_16);
  dmd.selectFont(Arial_14);
  //dmd.selectFont(SystemFont5x7);

  //-----------------------------------------------------------By using "millis()"
  Text = "CIT WEATHER STATION     TEMPERATURE: 35 C     HUMIDITY: 71%     WIND: 18Km/hr     PRECIPITATION: 20%";
  dmd.drawMarquee(Text,strlen(Text),(32*DISPLAYS_ACROSS)-1,0);
  long start=millis();
  long timer=start;
  boolean ret=false;
  int interval=25;
  while(!ret){
    if ((timer+interval) < millis()) {
      ret=dmd.stepMarquee(-1,0);
      timer=millis();
      Serial.println(ret);
    }
  }
}
