#include <SoftwareSerial.h>

SoftwareSerial LoraSerial(10, 11); // RX, TX

String loraMsg = "";         
bool stringComplete = false;     // flag for whether a complete line has been received

void setup() {
  Serial.begin(9600);           // hardware serial
  LoraSerial.begin(9600);       // software serial
  
  loraMsg.reserve(200);         // reserve space for the string
  Serial.println("Hardware and Software Serial Setup complete!");
}

void loop() {
  if (Serial.available()) {               // check if there is data in the serial buffer
    char inChar = (char)Serial.read();    // read a character from the hardware serial
    //LoraSerial.write(inChar);           // write the character to the software serial
    LoraSerial.print(inChar);
  }

  if (LoraSerial.available()) {
    char inChar = (char) LoraSerial.read(); // read a character from the software serial
    loraMsg += inChar;                     // append the read character to the end of the string

    if (inChar == '\n') {                  // if the character is a newline
      stringComplete = true;               // mark as complete
    }
  }

  if (stringComplete) {
    Serial.print(loraMsg);                // print the complete string
    loraMsg = "";                         // clear the string for the next reception
    stringComplete = false;               // reset the complete flag
  }
}
