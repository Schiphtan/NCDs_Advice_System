/* The header file that contains the structure and funtions of patient.c */
#ifndef PATIENT_H
#define PATIENT_H

struct Patient
{
    char id[10];
    char username[20];
    char password[20];
    char firstName[20];
    char lastName[20];
    int age;
    char disease[20];
    float weight, height;
    char sex;
};

void registerPatient(struct Patient *patient);
int loginPatient(struct Patient *patient);

#endif
