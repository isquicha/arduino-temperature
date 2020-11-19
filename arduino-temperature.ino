#define SENSOR_PIN A4
#define ANALOG_CONSTANT ((1.1 / 1024.0) * 100.0)

double temperature;
int counter = 0;
void setup()
{
    pinMode(13, OUTPUT);
    pinMode(SENSOR_PIN, INPUT);
    analogReference(INTERNAL);
    Serial.begin(9600);
}

void loop()
{
    temperature = analogRead(SENSOR_PIN) * ANALOG_CONSTANT;
    Serial.print(counter++);
    Serial.print(": Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");
    digitalWrite(13, !digitalRead(13));
    delay(500);
}