#include <FlexCAN_T4.h>
FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> can1;
CAN_message_t msg;

void setup(void) {
  Serial.begin(115200);
  Serial.println("Hello World");
  delay(400);
  pinMode(6, OUTPUT); digitalWrite(6, LOW); /* optional tranceiver enable pin */
  can1.begin();
  can1.setBaudRate(500000);
  can1.setMaxMB(16);
  can1.enableFIFO();
  can1.enableFIFOInterrupt();
  can1.onReceive(canSniff);
  can1.mailboxStatus();
  delay(2000);
  sendtoMC();
}

void canSniff(const CAN_message_t &msg) {
  Serial.print("MB "); Serial.print(msg.mb);
  Serial.print("  OVERRUN: "); Serial.print(msg.flags.overrun);
  Serial.print("  LEN: "); Serial.print(msg.len);
  Serial.print(" EXT: "); Serial.print(msg.flags.extended);
  Serial.print(" TS: "); Serial.print(msg.timestamp);
  Serial.print(" ID: "); Serial.print(msg.id, HEX);
  Serial.print(" Buffer: ");
  for ( uint8_t i = 0; i < msg.len; i++ ) {
    Serial.print(msg.buf[i], HEX); Serial.print(" ");
  } Serial.println();
}

void loop() {
  can1.events();
  delay(100);
}

void sendtoMC()
{
  msg.id = 0x210 ;
  msg.len = 3;

  msg.buf[0] = 0x3D;
  msg.buf[1] = 0x30;
  msg.buf[2] = 0x64;
  can1.write(msg);
  delay(100);
  msg.buf[0] = 0x3D;
  msg.buf[1] = 0xCE;
  msg.buf[2] = 0x64;
  can1.write(msg);
  delay(100);
  msg.buf[0] = 0x3D;
  msg.buf[1] = 0xA3;
  msg.buf[2] = 0x64;
  
  can1.write(msg);
  delay(100);
  msg.buf[0] = 0x3D;
  msg.buf[1] = 0x4f;
  msg.buf[2] = 0x64;
  can1.write(msg);
  delay(100);
  msg.buf[0] = 0x3D;
  msg.buf[1] = 0xa5;
  msg.buf[2] = 0x64;
  can1.write(msg);
  delay(100);
  msg.buf[0] = 0x3D;
  msg.buf[1] = 0x62;
  msg.buf[2] = 0x64;
  can1.write(msg);
  delay(100);
  msg.buf[0] = 0x3D;
  msg.buf[1] = 0x4e;
  msg.buf[2] = 0x64;
  can1.write(msg);
  delay(100);
  msg.buf[0] = 0x3D;
  msg.buf[1] = 0x59;
  msg.buf[2] = 0x64;
  can1.write(msg);
  delay(100);
  
}
