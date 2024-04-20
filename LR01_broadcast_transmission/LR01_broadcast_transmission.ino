#include <SoftwareSerial.h>

SoftwareSerial LoraSerial(10, 11); // Define the pins used by the serial port of the software: RX = 10, TX = 11

const String channel = "01";       // set target channel!
const String msg = "To all lora in 01, Hello,Lora!"; // set testing message

void setup() {
  LoraSerial.begin(9600); // Initializes the software serial port at 9600 baud 
}


void loop() {
  // sending message
  sendHexData(channel, msg);
  delay(1000); // delay 1 second
}

void sendHexData(String channel, String message) {
  unsigned long channelByte = strtoul(channel.c_str(), NULL, 16);
  LoraSerial.write(channelByte);      // sending channel in HEX
  
  // sending message in HEX
  for (unsigned int i = 0; i < message.length(); i++) {
    LoraSerial.write(message[i]);
  }
  
  // Send carriage returns and newlines
  LoraSerial.write('\r');
  LoraSerial.write('\n');
}

