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

  if (check_switch == 1)
  { analogWrite (LED,512);
   if (runstate != ON)
    { runstate = ON;
      Serial.println("ON");
    }
  }
  else
   { digitalWrite (LED,LOW);
      if (runstate != OFF)
      { Serial.println("OFF");
        runstate = OFF;
      }
   }

}


