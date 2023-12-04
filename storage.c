#include "storage.h"
#include "patient.h"
#include "health.h"
#include <stdio.h>

void loadData(struct Patient *patient, struct HealthMeasurement *measurement) {
    FILE *file = fopen("data.csv", "r");
    
    if (file != NULL) {
        /*Read patient data*/
        fread(patient, sizeof(struct Patient), 1, file);

        /*Read health measurement data*/
        fread(measurement, sizeof(struct HealthMeasurement), 1, file);

        fclose(file);
        printf("Data loaded successfully.\n");
    } else {
        printf("No existing data found.\n");
    }
}

void saveData(const struct Patient *patient, const struct HealthMeasurement *measurement) {
    FILE *file = fopen("data.csv", "w");

    if (file != NULL) {
        /*Write patient data*/
        fwrite(patient, sizeof(struct Patient), 1, file);

        /*Write health measurement data*/
        fwrite(measurement, sizeof(struct HealthMeasurement), 1, file);

        fclose(file);
        printf("Data saved successfully.\n");
    } else {
        printf("Failed to save data.\n");
    }
}
