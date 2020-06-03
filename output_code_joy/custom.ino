#define LED 13

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//   incoming = Serial.read();
//   if (Serial.available()>0)
//   {
//       digitalWrite(LED, HIGH);
//   }

    if (Serial.available()) {
        char serialListener = Serial.read();
        if (serialListener == 'H') {
            digitalWrite(LED, HIGH);
        }
        else if (serialListener == 'L') {
            digitalWrite(LED, LOW);
        }
    }
  
}