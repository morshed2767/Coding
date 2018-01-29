int ledPin = 13;
int ldrVal;
int Ack_tx = 2;
int rec;
int ldr = A7;
unsigned long time=0;
unsigned long counter=0;

void setup()
{
  Serial.begin(9600);      // start serial communication at 9600bps
  Serial1.begin(9600);     // start serial1 communication at 9600bps
 
  pinMode(ledPin, OUTPUT);
  pinMode(ldr, INPUT);

  Serial.flush();
  Serial1.flush();
  
}


void loop()
{
  
  time = millis();
  if(time == counter){
    ldrVal = analogRead(ldr);
    Serial.println(ldrVal);
  
   Serial1.write(ldrVal/256); //Send the Quotient or "how many times" value
   Serial1.write(ldrVal%256); //Send the Modulo or Remainder.
   //delay(5); //Wait for the serial port.
   counter = counter+5000;
  }
  
}


