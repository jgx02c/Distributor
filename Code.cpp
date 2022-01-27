//Note: The first half of this code was written by Wesley Kagan
//Project: Freevalve Harbor Freight


const int hall = 2;
int hallcounter = 0;
int hallstate = 0;
int lasthallstate = 0;
int cycle = 0;
unsigned long triggerTime;
unsigned long last_triggerTime;
unsigned long timeGap;
unsigned long last_timeGap;
unsigned int degree;

void setup() {
  pinMode(hall, INPUT);
  Serial.begin(115200);
  pinMode(7, OUTPUT);
  attachInterrupt(0, magnet_detect, RISING);
  digitalWrite(7, HIGH);
  degree = 0;
}

 void loop()
 {
   //Has to be kept here
 }

void magnet_detect() {
      hallcounter ++;
      triggerTime = millis();
      timeGap = triggerTime - last_triggerTime;
      last_triggerTime = triggerTime;

      if (timeGap >= last_timeGap + last_timeGap / 2)
      {
        Serial.println("missing tooth");
        hallcounter = 1;
        cycle++;
      }

      last_timeGap = timeGap;
      Serial.println(hallcounter);

     degree = hallcounter * 22.5;


        if (degree == 45 && cycle >= 3) {
        Serial.println(degree);
        digitalWrite(7, LOW);
        delay (10);
        digitalWrite(7, HIGH);
        }

       else if (degree == 135 && cycle >= 3) {
        Serial.println(degree);
        digitalWrite(7, LOW);
        delay (10);
        digitalWrite(7, HIGH);
        }

       else if (degree == 225 && cycle >= 3) {
        Serial.println(degree);
        digitalWrite(7, LOW);
        delay (10);
        digitalWrite(7, HIGH);
        }

        else if (degree == 315 && cycle >= 3){
        Serial.println(degree);
        digitalWrite(7, LOW);
        delay (10);
        digitalWrite(7, HIGH);
        }
  lasthallstate = hallstate;
}
