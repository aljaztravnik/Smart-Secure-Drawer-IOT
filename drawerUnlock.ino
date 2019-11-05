#define knockPin A0
#define drawer1 3
#define drawer2 4
#define drawer3 5
int tImE, lastTime, loopTime = 0;
int pickedDrawer;
int state;
int limit = 350;


void showPickedDrawer();

void setup() {
  pinMode(drawer1, OUTPUT); // LEDs to show picked drawer
  pinMode(drawer2, OUTPUT);
  pinMode(drawer3, OUTPUT);
  pinMode(knockPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int cooldown;
  while(loopTime < 5000)
  {
    tImE = millis();
    loopTime += tImE - lastTime;
    lastTime = tImE;
    state = analogRead(knockPin);
    if((state > limit) && (cooldown == 0))
    {
      cooldown = 150;
      Serial.println("knock");
      pickedDrawer++;   
    }
    if(pickedDrawer > 3)
    {
      pickedDrawer = 3;
    }
    if (cooldown > 0)
       cooldown--;
    delay(1);
  }
  loopTime = 0;
  showPickedDrawer();
}

void showPickedDrawer()
{
  loopTime = 0;
  if(pickedDrawer == 1)
  {
    Serial.println("You picked drawer 1");
  }else if(pickedDrawer == 2)
  {
    Serial.println("You picked drawer 2");
  }else if(pickedDrawer == 3)
  {
    Serial.println("You picked drawer 3");
  }else
  {
    Serial.println("You didn't pick a drawer");
  }
  delay(2000);
  pickedDrawer = 0;
}
