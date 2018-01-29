unsigned long time=0;
unsigned long counter=0;

void setup(){
  Serial.begin(9600);
}
void loop(){
  //Serial.print("Time: ");
  time = millis();
  if(time == counter){
    Serial.print("Time: ");
    Serial.println(time);    //prints time since program started
    counter = counter +1000;
   // Serial.println(counter); 
    //delay(500);
  }
  if(time==5000){
    time = millis()-time;
    counter=0;
    Serial.println(time); 
    //Serial.println(time);
  }
  //delay(1000);
  //delay(1000);             // wait a second so as not to send massive amounts of data
}
