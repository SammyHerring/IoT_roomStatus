//Any earlier values are required for optimal operation, but may be discounted from this test.

/* ================ SETUP CODE (RUNS ONCE) ==================== */

void setup() {

}

/* ================ MAIN CODE (RUN REPEATEDLY) ================= */

void loop() {
  //The main algorithm calls the 'notify()' function at appropriate intervals.
  //This will be tested later in the integration tests.
}

void notify(char type[], char data[]) {

  if ( type == "boot" ) {
    Particle.publish("IoTRoomSensor-Boot-G16", data, PRIVATE);
  } else if ( !periodNotified || periodStateChange ) {
      if (periodStateChange && !periodChangeNotified) {
        Serial.println("Notification: New Reservation");
        Particle.publish("IoTRoomSensor-StateRed-G16", "G16 has been reserved.", PRIVATE);
        periodChangeNotified = true;
      } else if ( type == "reserved" ) {
        Serial.println("Notification: Reserved");
        Serial.println(periodNotified);
        Serial.println(periodStateChange);
        Particle.publish("IoTRoomSensor-StateRed-G16", data, PRIVATE);
        periodNotified = true;
      } else if ( type == "vacant" ) {
        Serial.println("Notification: Vacant");
        Serial.println(periodNotified);
        Serial.println(periodStateChange);
        Particle.publish("IoTRoomSensor-StateGreen-G16", data, PRIVATE);
        periodNotified = true;
      }
    } else {
      Serial.println("Notification Pushed. Type unknown.");
      Serial.println(type);
      Serial.println(data);
    }
}
