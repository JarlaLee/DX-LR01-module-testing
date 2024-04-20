#include <SoftwareSerial.h>

// Define the pins used by the serial port of the software: RX = 10, TX = 11
SoftwareSerial LoraSerial(10, 11);

void setup() {
  // Initializes the hardware serial port and software serial port at 9600 baud
  Serial.begin(9600);
  while (!Serial);
  
  LoraSerial.begin(9600);

  // Output the initialization success message to the serial port monitor
  Serial.println("Setup complete. Enter data to send to LoRa:");
}

void loop() {
  sendDataToLoRa();

  receiveDataFromLoRa();
}


// 处理从PC到LoRa的数据发送
void sendDataToLoRa() {
  if (Serial.available()) {
    char inChar = (char)Serial.read(); // 读取硬件串口数据
    LoraSerial.print(inChar);          // 将读取的数据发送到LoRa模块
    Serial.print(inChar);              // 也在串口监视器上显示发送的数据
  }
}


// 处理从LoRa到PC的数据接收
void receiveDataFromLoRa() {
  if (LoraSerial.available()) {
    char inChar = (char)LoraSerial.read();
    Serial.print(inChar);              // 将LoRa模块接收的数据显示在串口监视器上
  }
}
