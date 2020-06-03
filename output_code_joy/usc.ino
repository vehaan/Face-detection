#define LED1 13
#define LED2 7

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;
// Flags


void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
}

void loop() {

    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance= duration*0.034/2;
    // Serial.print("Distance: ");
    // Serial.println(distance);
    if (distance < 6)
    {
        digitalWrite(LED2, HIGH);
    }
    else
    {
    digitalWrite(LED2, LOW);
    }

    if (Serial.available()) {
        char serialListener = Serial.read();
        if (serialListener == 'H') {
                digitalWrite(LED1, HIGH);
                // delayMicroseconds(2);
                // // Sets the trigPin on HIGH state for 10 micro seconds
                // digitalWrite(trigPin, HIGH);
                // delayMicroseconds(10);
                // digitalWrite(trigPin, LOW);
                // Reads the echoPin, returns the sound wave travel time in microseconds
                // duration = pulseIn(echoPin, HIGH);
                // // Calculating the distance
                // distance= duration*0.034/2;
                // Prints the distance on the Serial Monitor
                // Serial.print("Distance: ");
                // Serial.println(distance);
                // if (distance < 6)
                // {
                //     digitalWrite(LED2, HIGH);
                // }
                //  else
                //  {
                //     digitalWrite(LED2, LOW);
                //  }
                 
                
        }
        else if (serialListener == 'L') {
            digitalWrite(LED1, LOW);
            digitalWrite(trigPin, LOW);
            pulseIn(echoPin, LOW);
            Serial.println("NOT READING");
        }
    }
  
}