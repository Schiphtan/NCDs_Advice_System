#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"

static int patientCounter = 1; /*Counter will increment 1*/

void generatePatientID(struct Patient *patient)
{
    sprintf(patient->id, "H%04d", patientCounter++);
}

void registerPatient(struct Patient *patient)
{
    printf("Patient Registration:\n");

    printf("Enter patient firstname: ");
    scanf("%s", patient->firstName);

    printf("Enter patient last name: ");
    scanf("%s", patient->lastName);

    printf("Enter patient age: ");
    scanf("%d", &patient->age);

    printf("Enter patient disease: ");
    scanf("%s", patient->disease);

    printf("Enter patient weight in Kgs: ");
    scanf("%f", &patient->weight);

    printf("Enter patient height in cm: ");
    scanf("%f", &patient->height);

    printf("Enter patient sex (M/F): ");
    scanf(" %c", &patient->sex);

    /*Function to generate patient ID*/
    generatePatientID(patient);

    /*Set a default username using the patient ID*/

    strcpy(patient->username, patient->id);
    

    /*Ask the patient to set a password*/

    printf("Create a password: ");
    scanf("%s", patient->password);

    printf("Hello %s!\nYou have been registered successfully!\n", patient->firstName);
    printf("Your ID is %s\nSave it well you will use it as a Username\n", patient->username);
}

int loginPatient(struct Patient *Patient)
{
    char enteredUsername[20];
    char enteredPassword[20];

    printf("Login!\n");
    printf("Enter username: ");
    scanf("%s", enteredUsername);

    /*Check if the entered username matches the patient's username*/
    if (strcmp(enteredUsername, Patient->username) != 0)
    {
        printf("Invalid username\n");
        printf("Login unsuccessful\n");
        loginPatient(Patient);
        
        return 0;
    }

    printf("Enter password: ");
    scanf("%s", enteredPassword);

    /*Check if the entered password matches the patient's password*/
    if (strcmp(enteredPassword, Patient->password) != 0)
    {
        printf("Invalid password\n");
        printf("Login unsuccessful\n");
        loginPatient(Patient);

        return 0;
    }

    printf("Login successful!\nWelcome, %s!\n", Patient->firstName);

    return 1;
    
}