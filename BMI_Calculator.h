#pragma once
//Specific header for the BMI calculator functionality.
//A BMI calculator is = (weight in kg / height in meters squared) or (weight in pounds / height in inches squared) x 703

//my job is to implemnt the methods necesry to calculate the input provided by the user to calculate the BMI

#include <iostream>
#include <string>
#include <sstream>
#include <string>
#include "User_Input.h"
#include "math.h"



class BMI_Calculator {

public:

	// constructor
	explicit BMI_Calculator(User_Input* userInput);

	// method to calculate BMI
	float calculateBMI();

private:

	User_Input* userInput;

	float convertInchesToMeters(float Inches);

	float convertPoundsToKilograms(float Pounds);




};

