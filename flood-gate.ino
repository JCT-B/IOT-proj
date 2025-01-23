
// Define the pin numbers for the water sensor, motor, and photosensor
int waterSensorPin = A0; //analog pin 
int motorPin = 3;
int photoSensorPin = A1; //analog pin
 
// Define the threshold values for triggering the motor action and adjusting the motor position
int rainThreshold = 500; //change the threshold value 
int sunThreshold = 700; //change the threshold value
 
void setup() {
  // Initialize the digital pins for the motor
  pinMode(motorPin, OUTPUT);
  
  // Set up the serial communication for debugging
  Serial.begin(9600);
}
 
void loop() {
  // Read the value from the water sensor and photosensor
  int waterSensorValue = analogRead(waterSensorPin);
  int photoSensorValue = analogRead(photoSensorPin);
  
  // Print the sensor values to the serial monitor for debugging
  Serial.print("Water Sensor Value: ");
  Serial.print(waterSensorValue);
  Serial.print(" | ");
  Serial.print("Photo Sensor Value: ");
  Serial.println(photoSensorValue);
  
  // Check if it's raining based on the water sensor value
  if (waterSensorValue &lt; rainThreshold) {
    // Trigger the motor action by setting the motor pin to high
    digitalWrite(motorPin, HIGH);
  } 
  // Check if it's not raining and the sun intensity is high based on the photosensor value
  else if (waterSensorValue &gt;= rainThreshold &amp;&amp; photoSensorValue &gt; sunThreshold) {
    // Adjust the roof position to create shade by setting the motor pin to high
    digitalWrite(motorPin, HIGH);
  }
  // Stop the motor action by setting the motor pin to low
  else {
    digitalWrite(motorPin, LOW);
  }
  
  // Wait for a short delay before repeating the loop
  delay(1000); //depends on you, you can change it to 5 mins
}
