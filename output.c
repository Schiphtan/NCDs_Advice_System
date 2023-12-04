#include "patient.h"
#include "health.h"
#include "output.h"
#include <stdio.h>

void printData(const struct Patient *patient, const struct HealthMeasurement *measurement) {
    printf("Patient Data:\n");
    printf("ID: %s\n", patient->id);
    printf("Username: %s\n", patient->username);
    printf("Password: %s\n", patient->password);
    printf("Name: %s %s\n", patient->firstName, patient->lastName);
    printf("Age: %d\n", patient->age);
    printf("Disease: %s\n", patient->disease);
    printf("Weight: %.2f\n", patient->weight);
    printf("Height: %.2f\n", patient->height);
    printf("Sex: %c\n", patient->sex);

    printf("\nHealth Measurement Data:\n");
    printf("BMI: %.2f\n", measurement->bmi);
    printf("Blood Sugar: %.2f\n", measurement->bloodSugar);
    printf("Blood Pressure: %.2f\n", measurement->bloodPressure);
}
