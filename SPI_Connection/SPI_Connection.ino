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
  digitalWrite(SS,HIGH);                 // Activate slave device
} // end void setup()

void loop (){

  char buf[20] = "Testing 12345678";
  printf("\n\nWriting char string \"%s\" to FPGA memory:\n", buf);
  delay(200);
  printf("\n\tFPGA readback:\n", buf);
  delay(200);
  FPGA_consecutive_writes (buf, FPGA_RAM_1, 16);			// write 16 bytes to buffer
  for (int ii = FPGA_RAM_1; ii < FPGA_RAM_1 + 16; ii ++){
    temp = FPGA_read(ii);
    printf("\t\tChar %d = %c \n", (uint16_t)ii, (char)temp);
    delay(10);

  } // end for loop

} // end void loop()


