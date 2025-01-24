// Pin assignments
const int mq2Pin = A0;       // MQ-2 sensor connected to analog pin A0
//const int buzzerPin = 3;     // Buzzer connected to digital pin 3
const int redLightPin = 4;   // Red LED connected to digital pin 4

// Threshold value
const int smokeThreshold = 300; // Adjust based on the sensor value for detecting smoke

void setup() {
  pinMode(mq2Pin, INPUT);
 // pinMode(buzzerPin, OUTPUT);
  pinMode(redLightPin, OUTPUT);

 // digitalWrite(buzzerPin, LOW); // Ensure the buzzer is off initially
  digitalWrite(redLightPin, LOW); // Ensure the red light is off initially

  Serial.begin(9600); // For debugging
}

void loop() {
  // Read the MQ-2 sensor value
  int smokeValue = analogRead(mq2Pin);
  Serial.print("Smoke Sensor Value: ");
  Serial.println(smokeValue);

  // Trigger alarm if smoke is detected
  if (smokeValue > smokeThreshold) {
   // digitalWrite(buzzerPin, HIGH); // Turn on the buzzer

    // Make the red light blink
    digitalWrite(redLightPin, HIGH);
    delay(250); // Light on for 250ms
    digitalWrite(redLightPin, LOW);
    delay(250); // Light off for 250ms

    Serial.println("Smoke detected! Alarm ON.");
  } else {
   // digitalWrite(buzzerPin, LOW); // Turn off the buzzer
    digitalWrite(redLightPin, LOW); // Turn off the red light
    Serial.println("No smoke detected. Alarm OFF.");
    delay(100); // Small delay to stabilize readings
  }
}
