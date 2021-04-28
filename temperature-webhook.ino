// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>
#define DHTPIN 2
#define DHTTYPE 11

int led = D7; // onboard LED
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    pinMode(led, OUTPUT);
    dht.begin();
}

void loop() {
    digitalWrite(led, HIGH);
    float temp = dht.getTempCelcius();
    Particle.publish("Temperature", (String)temp, PRIVATE);
    delay(30s);
    digitalWrite(led, LOW);
    delay(5s);
}
