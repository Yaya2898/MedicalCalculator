
//The entry point of your application. This file will create instances of your calculator classes and manage the application flow.
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "math.h" 
#include "User_Input.h"
#include "BMI_Calculator.h"

int main() {
    //std::cout << "Hello, World!" << std::endl; // boilerplate so that i can compile my other files to check for errors 

    User_Input userInput;

    userInput.collectUserInputs();


    BMI_Calculator bmiCalculator(&userInput);


    float bmi = bmiCalculator.calculateBMI();
    std::cout << "Your BMI is: " << bmi << std::endl;


    return 0;
}
