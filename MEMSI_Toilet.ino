#include<SoftwareSerial.h>;

SoftwareSerial BT(2, 3);

int ledPin = 13;
int sensorIn = 0;
int conRead;
int serialRead;
int currentStatus = 0;
int lastStatus = 0;


void setup() {
  Serial.begin(9600);
  BT.begin(9600);

  Serial.println("Enter AT commands:");
  pinMode(13, OUTPUT);
}


void loop() {
  BTcom();

  conRead = analogRead(sensorIn);
 // Serial.println(conRead);
  //BT.println(conRead);
  
  Message();

  if (conRead < 200) {
    digitalWrite(ledPin, HIGH);
    currentStatus = 0;
  }
  else {
    digitalWrite(ledPin, LOW);
    currentStatus = 1;
  }
  delay(500);

  lastStatus = currentStatus;
}

void BTcom() {
  if (BT.available())
    Serial.write(BT.read());

  if (Serial.available())
    BT.write(Serial.read());
}

void Message() {
  if (lastStatus != currentStatus) {
    if (currentStatus = 1) {
      BT.println("Water Detected");
    }
    if (currentStatus = 0){
      BT.println("Water Not Detected");
    }
  }

}

