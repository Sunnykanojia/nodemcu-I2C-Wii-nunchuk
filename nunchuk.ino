#include "Wire.h"
#include "ArduinoNunchuk.h"

//#define buzzer D4
ArduinoNunchuk nunchuk = ArduinoNunchuk();
void setup()
{
  //pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
  nunchuk.init();//D1 = SDA D2 = SCL
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop()
{
  nunchuk.update();

  Serial.print(nunchuk.analogX, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.analogY, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelX, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelY, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.accelZ, DEC);
  Serial.print(' ');
  Serial.print(nunchuk.zButton, DEC);
  Serial.print(' ');
  Serial.println(nunchuk.cButton, DEC);
  if(nunchuk.cButton==0)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    //digitalWrite(buzzer, LOW);
    //delay(1000);
  }
  else
  {
   digitalWrite(LED_BUILTIN,LOW);
    //digitalWrite(buzzer, HIGH);//delay(1000); 
  }
  
  
}
