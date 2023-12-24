//Implementation of the BMI calculation logic.
#include "BMI_Calculator.h"

BMI_Calculator::BMI_Calculator(User_Input* userInput) {
    this->userInput = userInput;
}

//explain solution code below in the README
float BMI_Calculator::calculateBMI() {
    float weight = userInput->getWeight(); // Weight in pounds
    float heightInFeet = userInput->getHeight(); // Height in feet
    float heightInInches = heightInFeet * 12; // Convert feet to inches

    // Now calculate the BMI for Imperial units
    float bmi = (weight / (heightInInches * heightInInches)) * 703;
    return bmi;
}

// explain the problem code below in the README then delete this code below
/*float BMI_Calculator::calculateBMI() {
    //Get user data
    float weight = userInput->getWeight();
    float height = userInput->getHeight();
 
    //If the system is Imperial, convert to Metric
    if (userInput->getUnitSystem() == 'I') {
        weight = convertPoundsToKilograms(weight);
        height = convertInchesToMeters(height);
    }

    //Calculate BMI
    float bmi = weight / (height * height);
    return bmi;
}*/

std::string BMI_Calculator::getBMICategory(float bmi) {
    if (bmi < 18.5) {
        return "Underweight";
    } else if (bmi >= 18.5 && bmi <= 24.9) {
        return "Normal weight";
    } else if (bmi >= 25 && bmi <= 29.9) {
        return "Overweight";
    } else if (bmi >= 30) {
        return "Obesity";
    } else {
        return "Unknown category";
    }
}

float BMI_Calculator::convertInchesToMeters(float inches) {
    return inches * 0.0254;
}

float BMI_Calculator::convertPoundsToKilograms(float pounds) {
    return pounds * 0.453592;
}