//Implementation of the BMI calculation logic.
#include "BMI_Calculator.h"

BMI_Calculator::BMI_Calculator(User_Input* userInput) {
    this->userInput = userInput;
}

float BMI_Calculator::calculateBMI() {
    //Get user data
    float weight = userInput->getWeight();
    float height = userInput->getHeight();

    //Convert to metric if necessary
 
    //If the system is Imperial, convert to Metric
    if (userInput->getUnitSystem() == 'I') {
        weight = convertPoundsToKilograms(weight);
        height = convertInchesToMeters(height);
    }

    //Calculate BMI
    return weight / (height * height);
}

float BMI_Calculator::convertInchesToMeters(float inches) {
    return inches * 0.0254;
}

float BMI_Calculator::convertPoundsToKilograms(float pounds) {
    return pounds * 0.453592;
}