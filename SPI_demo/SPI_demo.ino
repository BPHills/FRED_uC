#include <SPI.h>

void setup()
{
  int MISO = 50;    // Correlate pin numbers with SPI
  int MOSI = 51;
  int SCK = 52;
  int SS = 53;

  pinMode(MISO, INPUT);                  // MISO
  pinMode(MOSI, OUTPUT);                 // MOSI
  pinMode(SCK, OUTPUT);                  // SCK
  pinMode(SS, OUTPUT);                   // SS
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);             // Will send MSB first
  SPI.setDataMode(SPI_MODE3);            // Will use Mode3 SPI
  digitalWrite(SS,HIGH);                  // Activate slave device
} // end void setup()

void loop (){

  int value = 1;  // Value being passed
  
  while(value < 256){
    digitalWrite(SS,LOW);
    SPI.transfer(2);
    SPI.transfer(value);
    value++;
    digitalWrite(SS,HIGH);
    delay(500);
  }

} // end void loop()

