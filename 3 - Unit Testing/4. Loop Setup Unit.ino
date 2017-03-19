//Any earlier values are required for optimal operation, but may be discounted from this test.

/* ================ SETUP CODE (RUNS ONCE) ==================== */

void setup() {
  Serial.begin(9600); //Open Serial Transmission Port at BAUD Rate of 9600

  pinMode(pir, INPUT); //Set pinMode of D2 (pir) to INPUT

  //If DEBUG_MODE 'true' then enable on-board Status LED else disable on-board Status LED.
  if (!DEBUG_MODE) {
    RGB.control(true);
    RGB.color(0, 0, 0);
  } else {
    RGB.control(false);
  }

  WiFi.connect(); //Connect to Wi-Fi network
  int DBG = 0;
  while (!WiFi.ready()) {
    //Print Wi-Fi not connected yet once to serial if Wi-Fi not ready
    if (DBG == 0) {Serial.println("Wi-Fi Antenna Not Ready."); DBG = 1;}
    } while (WiFi.ready()) {
    Serial.println("Wi-Fi Antenna Ready.");
    Serial.println("W-Fi Connecting.");
    Particle.connect();
    //Continue once connected to Particle Cloud
    while (Particle.connected()) {
      Serial.println("W-Fi Connected."); //Print connected to Wi-Fi on serial
      Particle.syncTime(); //Sync RTC to Particle Cloud time value
      setPeriodTimes(); //Function not considered in this test, but required for setup.
      updateTime(); //Function not considered in this test, but required for setup.
      break;
    }
    break;
  }
}

/* ================ MAIN CODE (RUN REPEATEDLY) ================= */

void loop() {

}
