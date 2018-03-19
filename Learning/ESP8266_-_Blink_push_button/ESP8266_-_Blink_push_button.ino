//This code reads a button switch.  if theswith is toggled changes state from blinking to not blinking



#define LED  D1     //ESP is set so can define pins by Dxx
#define Switch D2
#define ON 1
#define OFF 0
int runstate;

void setup() {
  // put your setup code here, to run once:

Serial.begin(115200);  
pinMode (LED,OUTPUT);   //set mode of the pin
pinMode (Switch, INPUT);
analogWriteFreq (20);   //set the frequency to 20hz
//runstate = String("ON");

}

void loop() {
  // put your main code here, to run repeatedly:
 int check_switch;
  check_switch = digitalRead (Switch);

  if (check_switch == 0)
  { if (runstate == ON)
    { runstate = OFF;
      stopLED();
      delay(200);
    }
      
    else if (runstate == OFF)
    { runstate = ON;
      blinkLED();
      delay (200);
    }
  }
}

void blinkLED ()
{   analogWrite (LED,512);
    Serial.println("ON");
}

void stopLED ()  
{ digitalWrite (LED,LOW);
  Serial.println("OFF");
}


