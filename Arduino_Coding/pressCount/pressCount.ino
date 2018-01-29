int switchPin = 2;              // switch is connected to pin 2
int val;                        // variable for reading the pin status
int buttonState;                // variable to hold the button state
int buttonPresses = 0;          // how many times the button has been pressed
   
    void setup() {
      pinMode(switchPin, INPUT);    // Set the switch pin as input

      Serial.begin(9600);           // Set up serial communication at 9600bps
      buttonState = digitalRead(switchPin);   // read the initial state
      Serial.println(buttonPresses);
      
    }


    void loop(){
      val = digitalRead(switchPin);      
      
      if (val != buttonState) {         
        if (val == LOW) {               
          buttonPresses++;               
          delay(1);
          Serial.println(buttonPresses);
          //this is were the code for input/output code for the pins would go(like turning on an led etc).
        }
      }
      buttonState = val;                
    }
   
