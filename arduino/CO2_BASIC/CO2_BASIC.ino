void setup() {
  Serial.begin(9600);
}

void loop() {
   float sensor_volt;
    float R0;
    float RS;
    float ratio; // RS/R0;
    float BAC;
    int sensorValue = analogRead(A0);
    sensor_volt=(float)sensorValue/1024.0*5.0;
    RS = (4.5-sensor_volt)/sensor_volt;
    R0 = 29.03; 
    ratio = RS/R0;    
    BAC = 114.3544*pow(ratio,-2.93599);
    Serial.print("Rs값 : "); 
    Serial.println(RS); 
    Serial.print("PPM : "); 
    Serial.print(BAC); 
    Serial.println("ppm"); 
    Serial.print("Rs/R0 : "); 
    Serial.println(ratio); 
    Serial.println(); 
    delay(1000);
}
