int trigPin =9 , echoPin = 10;
int kirmizi = 2, yesil = 3, sari =4, mavi=5;

long sure , uzaklik ;




void setup() {
  pinMode(trigPin, OUTPUT); pinMode(echoPin, INPUT);
  pinMode(kirmizi, OUTPUT); pinMode(yesil, OUTPUT);
  pinMode(sari, OUTPUT); pinMode(mavi, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trigPin,LOW); delayMicroseconds(2);
  digitalWrite(trigPin,HIGH); delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  sure = pulseIn(echoPin , HIGH);
  uzaklik = (sure /2) /29.154; // uzaklik = (sure/2) * 0.0343
  Serial.print("Mesafe :");
  Serial.print(uzaklik);
  Serial.println(" CM");
  if(uzaklik <= 50){
    digitalWrite(kirmizi ,HIGH);
    digitalWrite(yesil ,LOW);
    digitalWrite(sari ,LOW);
    digitalWrite(mavi ,LOW);
    
  }else if(uzaklik <= 100){
    digitalWrite(kirmizi ,LOW);
    digitalWrite(yesil ,HIGH);
    digitalWrite(sari ,LOW);
    digitalWrite(mavi ,LOW);
  }else if(uzaklik <= 150){
    digitalWrite(kirmizi ,LOW);
    digitalWrite(yesil ,LOW);
    digitalWrite(sari ,HIGH);
    digitalWrite(mavi ,LOW);
  }else if(uzaklik <= 100){
    digitalWrite(kirmizi ,LOW);
    digitalWrite(yesil ,LOW);
    digitalWrite(sari ,LOW);
    digitalWrite(mavi ,HIGH);
  }else {
    digitalWrite(kirmizi ,LOW);
    digitalWrite(yesil ,LOW);
    digitalWrite(sari ,LOW);
    digitalWrite(mavi ,LOW);
  }
  delay(50);


}
