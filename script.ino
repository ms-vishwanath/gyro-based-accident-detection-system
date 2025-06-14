#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MPU6050.h>

#define ACCEL_THRESHOLD 2.0

Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.begin();
  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void loop() {
  sensors_event_t accel;
  mpu.getAccelerometerSensor()->getEvent(&accel);
  
  float accel_mag = sqrt(pow(accel.acceleration.x, 2) + pow(accel.acceleration.y, 2) + pow(accel.acceleration.z, 2));
  
  if (accel_mag > ACCEL_THRESHOLD) {
    Serial.println("Car accident detected!");
    // TODO: Send alert or call emergency services
  }
  
  delay(100);
}
