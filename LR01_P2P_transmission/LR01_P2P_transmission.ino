#include <SoftwareSerial.h>

// Define the pins used by the serial port of the software: RX = 10, TX = 11
SoftwareSerial LoraSerial(10, 11);


const String mac = "0102";          // set mac address in String
const String channel = "00";        // set channel in String
const String msg = "Hello,Lora!";   // set message in String

void setup() {
  // Initializes the hardware serial port and software serial port at 9600 baud
  Serial.begin(9600);
  while (!Serial);
  
  LoraSerial.begin(9600);

  // Output the initialization success message to the serial port monitor
  Serial.println("Setup complete. Enter data to send to LoRa:");
}


void loop() {
// Example: Send data
// The MAC address is 3132 (hexadecimal representation), the channel is 03 (hexadecimal), and the message is "Hello,Lora!".
  sendHexData(mac, channel, msg);
  delay(1000); 
}


void sendHexData(String mac, String channel, String message) {
  
  // Converts MAC address and channel to bytes and sends
  unsigned long macBytes = strtoul(mac.c_str(), NULL, 16);
  unsigned long channelByte = strtoul(channel.c_str(), NULL, 16);
  
  LoraSerial.write(macBytes >> 8);    // Send the high byte of the MAC address
  LoraSerial.write(macBytes & 0xFF);  // Send the low byte of the MAC address
  LoraSerial.write(channelByte);      // Send channel
  
  // Send a message
  for (unsigned int i = 0; i < message.length(); i++) {
    LoraSerial.write(message[i]);
  }
  
  // Send a return and a newline
  LoraSerial.write('\r');
  LoraSerial.write('\n');
}

