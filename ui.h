// ui.h
#ifndef UI_H
#define UI_H

#define EXIT 0

#include "patient.h"
#include "health.h"

void displayMainMenu();
int handleUserInput(struct Patient *patient, struct HealthMeasurement *measurement);
#endif
