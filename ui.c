#include <stdio.h>
#include "patient.h"
#include "health.h"
#include "storage.h"
#include "ui.h"
#include "output.h"
#include <stdlib.h>

void displayMainMenu()
{
    printf("Welcome to NCDs Management system!\n");
    printf("1. To Create account \"Enter 1\"\n");
    printf("2. Login \"Enter 2\"\n");
    printf("3. To Print the stored data Enter 3\n");
    printf("4. To exit the program \"Enter0\"\n");
}

int handleUserInput(struct Patient *patient, struct HealthMeasurement *measurement) {
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            registerPatient(patient);
            loginPatient(patient);
            inputHealthData(patient, measurement);
            break;
        case 2:
            loginPatient(patient);
            inputHealthData(patient, measurement);
            break;
        case 3:
            printData(patient, measurement);
            break;
        case 0:
            printf("Exiting the program. Happy Health!\n");
            // Save data before exiting (if needed)
            saveData(patient, measurement);
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return choice;
}
