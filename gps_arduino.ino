#include <math.h>

const float EarthRadius = 6371000;  // Radius of the Earth in meters

float toRadians(float degrees) {
    return degrees * (M_PI / 180.0);
}

float calculateDistance(float lat1, float lon1, float lat2, float lon2) {
    // Convert latitude and longitude from degrees to radians
    float lat1_rad = toRadians(lat1);
    float lon1_rad = toRadians(lon1);
    float lat2_rad = toRadians(lat2);
    float lon2_rad = toRadians(lon2);

    // Haversine formula
    float dlat = lat2_rad - lat1_rad;
    float dlon = lon2_rad - lon1_rad;

    float a = pow(sin(dlat / 2), 2) + cos(lat1_rad) * cos(lat2_rad) * pow(sin(dlon / 2), 2);
    float c = 2 * atan2(sqrt(a), sqrt(1 - a));

    float distance = EarthRadius * c;
    return distance;
}

void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.println("Enter coordinates for point 1 (latitude,longitude):");
    while (!Serial.available()) {
        // Wait for user input
    }
    String data1 = Serial.readStringUntil('\n');
    float lat1 = data1.substring(0, data1.indexOf(',')).toFloat();
    float lon1 = data1.substring(data1.indexOf(',') + 1).toFloat();

    Serial.println("Enter coordinates for point 2 (latitude,longitude):");
    while (!Serial.available()) {
        // Wait for user input
    }
    String data2 = Serial.readStringUntil('\n');
    float lat2 = data2.substring(0, data2.indexOf(',')).toFloat();
    float lon2 = data2.substring(data2.indexOf(',') + 1).toFloat();

    float distance = calculateDistance(lat1, lon1, lat2, lon2);

    // Ask for the time taken for travel in seconds
    Serial.println("Enter time taken for travel (seconds):");
    while (!Serial.available()) {
        // Wait for user input
    }
    String timeData = Serial.readStringUntil('\n');
    float travelTime = timeData.toFloat();

    // Calculate speed in meters per second
    float speed = distance / travelTime;

    Serial.print("Distance between points: ");
    Serial.print(distance);
    Serial.println(" meters");
    Serial.print("Speed: ");
    Serial.print(speed);
    Serial.println(" meters per second");
}
