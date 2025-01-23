// Pin assignments
const int rainSensorPin = A0; // Raindrop sensor connected to analog pin A0
const int motorPin = 3;      // Air motor connected to digital pin 3

// Threshold value
const int rainThreshold = 500; // Adjust based on the sensor value for detecting water

void setup() {
  pinMode(rainSensorPin, INPUT);
  pinMode(motorPin, OUTPUT);

  digitalWrite(motorPin, LOW); // Ensure the motor is off initially

  Serial.begin(9600); // For debugging
}

void loop() {
  // Read the raindrop sensor value
  int rainValue = analogRead(rainSensorPin);
  Serial.print("Rain Sensor Value: ");
  Serial.println(rainValue);

  // Control the motor based on the sensor reading
  if (rainValue < rainThreshold) {
    digitalWrite(motorPin, HIGH); // Turn on the motor if water is detected
    Serial.println("Water detected. Motor ON.");
  } else {
    digitalWrite(motorPin, LOW); // Turn off the motor if no water is detected
    Serial.println("No water detected. Motor OFF.");
  }

  delay(100); // Small delay to stabilize readings
}
