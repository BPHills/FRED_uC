int led = 13;

void setup() {
  pinMode(led,OUTPUT); // initialize pin 13 as output
}

void loop () {

  // runs loop three times
  for(int i=0 ; i<9 ; i++){
    digitalWrite(led,HIGH);  // turn led on

    if (i<3 || i>5) {
      delay(200);             // wait .2 seconds
    }
    else {
      delay(500);            // wait .5 seconds
    }
    digitalWrite(led,LOW);    // turn led off
    delay(300);               // wait .3 seconds
  }

  delay(500);

} // end void loop()



