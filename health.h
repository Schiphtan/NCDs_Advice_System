/*The header file that contain structure and functions*/
#ifndef HEALTH_H
#define HEALTH_H

#include "patient.h"

struct HealthMeasurement {
    float bloodPressure;
    float bloodSugar;
    float weight;
    float height;
    float bmi;
};

void inputHealthData(struct Patient *patient, struct HealthMeasurement *measurement);
void analyzeHealthData(struct HealthMeasurement *measurement);
void generateAdvice(struct HealthMeasurement *measurement);

#endif
