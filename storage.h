#ifndef STORAGE_H
#define STORAGE_H

#include "patient.h"
#include "health.h"


void loadData(struct Patient *patient, struct HealthMeasurement *measurement);
void saveData(const struct Patient *patient, const struct HealthMeasurement *measurement);

#endif
