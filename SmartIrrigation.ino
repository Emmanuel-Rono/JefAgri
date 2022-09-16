
//bool waterPumb;
int moistureSensor=35;
int RelayPin=34;
#include "thingProperties.h"
  
//int waterPump=35;
//int sensorData;
const char* ssid = "AccessPoint";
const char* password = "INTERNET of things";

//declaring pins to use
void setup() {
  pinMode(moistureSensor,INPUT);
pinMode(RelayPin,OUTPUT);
//pinMode(waterPump,OUTPUT)
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  sensorData=analogRead(moistureSensor);
Serial.println(sensorData);
delay(2000);
onWaterPumpChange();
}

/*
  Since WaterPump is READ_WRITE variable, onWaterPumpChange() is
  executed every time a new value is received from IoT Cloud.
*/
void  onWaterPumpChange() {
 if(waterPump==1)
  {
  Serial.println(waterPump);
    digitalWrite(RelayPin,HIGH);
   //Serial.println(35, RelayPin);
  }
   else if(waterPump==0)
   {
    Serial.println(waterPump);
    digitalWrite(RelayPin,LOW);
   //Serial.println(35, RelayPin);
  }
}
/*
  Since WaterPump is READ_WRITE variable, onWaterPumpChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onWaterPumpChange()  {
  // Add your code here to act upon WaterPump change
}