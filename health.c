#include <stdio.h>
#include "health.h"
#include "patient.h"

void inputHealthData(struct Patient *patient, struct HealthMeasurement *measurement)
{
    int choice;
    printf("To know interpretation of your measurements:\n");
    printf("1.BMI Enter 1\n");
    printf("2.Diabetes Enter 2\n");
    printf("3.Heart rate Enter 3\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter you weight: ");
        scanf("%f", &measurement->weight);

        printf("Enter your height: ");
        scanf("%f", &measurement->height);
        measurement->height /= 100; /*Converts hight to meters*/

        /*Calculate BMI*/
        measurement->bmi = measurement->weight / (measurement->height * measurement->height);
        printf("Your BMI is: %.2f\n", measurement->bmi);
        break;

    case 2:
        printf("Enter your Blood sugar level: ");
        scanf("%f", &measurement->bloodSugar);
        break;

    case 3:
        printf("Enter your heart rate: ");
        scanf("%f", &measurement->bloodPressure);
        break;

    case 0:
        printf("Exited");
        /*codes to take me back to main menu*/
        break;        
    default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
}

void analyzeHealthData(struct HealthMeasurement *measurement)
{
    /*Interpret BMI*/
    if (measurement->bmi < 18.5)
    {
        printf("Underweight\n");
    } else if (measurement->bmi >= 18.5 && measurement->bmi < 25) {
        printf("Normal weight\n");
    } else if (measurement->bmi >= 25 && measurement->bmi < 30) {
        printf("Overweight\n");
    } else {
        printf("Obese\n");
    }


    /* Interpret Blood Sugar */
    if (measurement->bloodSugar < 70) {
        printf("Low blood sugar (Hypoglycemia)\n");
    } else if (measurement->bloodSugar >= 70 && measurement->bloodSugar <= 99) {
        printf("Normal blood sugar\n");
    } else if (measurement->bloodSugar >= 100 && measurement->bloodSugar <= 125) {
        printf("Prediabetes (Impaired Fasting Glucose)\n");
    } else {
        printf("High blood sugar (Diabetes)\n");
    }


    /*Interpret Heart rate*/
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);

    int maxHeartRate = 220 - age;

    if (measurement->bloodPressure >= 0.5 * maxHeartRate && measurement->bloodPressure <= 0.85 * maxHeartRate) {
        printf("Normal heart rate\n");
    } else if (measurement->bloodPressure > 0.85 * maxHeartRate) {
        printf("High heart rate (Hypertension)\n");
    } else {
        printf("Low heart rate (Hypotension)\n");
    }
}
void generateAdvice(struct HealthMeasurement *measurement) {
    /*Implementation for generating advice*/
    printf("Advice based your BMI:\n");

    if (measurement->bmi < 18.5) {
        printf("You are underweight. Consider gaining weight through a balanced diet and regular exercise.\n\n\n");
    } else if (measurement->bmi >= 18.5 && measurement->bmi < 25) {
        printf("Your weight is normal. Maintain a balanced diet and regular exercise for overall health.\n\n\n");
    } else if (measurement->bmi >= 25 && measurement->bmi < 30) {
        printf("You are overweight. Consider losing weight through a balanced diet and regular exercise to improve health.\n\n\n");
    } else {
        printf("You are obese. Consult with a healthcare professional for guidance on weight management and overall health.\n\n\n");
    }


    /*Advise based on Blood Sugar*/
    printf("Advice based on Blood Sugar:\n");

    if (measurement->bloodSugar < 70) {
        printf("Your blood sugar is low. Consume some carbohydrates to raise your blood sugar level.\n\n\n");
    } else if (measurement->bloodSugar >= 70 && measurement->bloodSugar <= 99) {
        printf("Your blood sugar is normal. Maintain a balanced diet to keep it within this range.\n\n\n");
    } else if (measurement->bloodSugar >= 100 && measurement->bloodSugar <= 125) {
        printf("Your blood sugar is in the prediabetes range.\nFocus on a healthier lifestyle, including diet and exercise, to prevent diabetes.\n\n\n");
    } else {
        printf("Your blood sugar is high. Consult with a healthcare professional for further evaluation and guidance.\n\n\n");
    }

     /*Advise based on Blood Pressure*/
    printf("Advice based on Blood Pressure:\n");

    if (measurement->bloodPressure < 90) {
        printf("Your blood pressure is low. Consider consulting with a healthcare professional for further evaluation.\n\n\n");
    } else if (measurement->bloodPressure >= 90 && measurement->bloodPressure < 120) {
        printf("Your blood pressure is normal. Maintain a healthy lifestyle to keep it within this range.\n\n\n");
    } else if (measurement->bloodPressure >= 120 && measurement->bloodPressure < 130) {
        printf("Your blood pressure is elevated. Focus on lifestyle changes,\nincluding diet and exercise, to prevent hypertension.\n\n\n");
    } else if (measurement->bloodPressure >= 130 && measurement->bloodPressure < 140) {
        printf("You have stage 1 hypertension. Consult with a healthcare professional for further evaluation and guidance.\n\n\n");
    } else {
        printf("You have stage 2 hypertension. Urgently consult with a healthcare professional for evaluation and treatment.\n\n\n");
    }
}
