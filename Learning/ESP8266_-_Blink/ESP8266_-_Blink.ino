#define LED  D1     //ESP is set so can define pins by Dxx
#define Switch D2

void setup() {
  // put your setup code here, to run once:
  
pinMode (LED,OUTPUT);   //set mode of the pin
pinMode (Switch, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 int check_switch;
  check_switch = digitalRead (Switch);

  if (check_switch == 1)
  { digitalWrite (LED,HIGH);
    t_delay(1000);
    digitalWrite (LED,LOW);
    t_delay(1000);
  }
  else
    digitalWrite (LED,LOW);

}

void t_delay (int x)
{
  delay (x);
}

