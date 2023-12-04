#include "patient.h"
#include "health.h"
#include "storage.h"
#include "ui.h"
#include <stdlib.h>

int main() {
    struct Patient patient;
    struct HealthMeasurement measurement;

    /*Load existing data from storage*/
    loadData(&patient, &measurement);

    /*Display the main menu and handle user input*/
    int userChoice;
    while (1) {
        displayMainMenu();
        userChoice = handleUserInput(&patient, &measurement);

        if (userChoice == EXIT)
        {
            break;
        }
        
    }

    /*Save data before exiting*/
    saveData(&patient, &measurement);

    return 0;
}
