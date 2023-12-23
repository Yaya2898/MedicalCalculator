#pragma once
//Defines a class or functions for handling user input and validation.
#include <iostream>
#include <string>
#include <sstream>
#include <string>

// what do i want other classes to use/access

class User_Input {

public:

	User_Input(); //Constructor

	//Getters for UserInput
	float getWeight();
	int getAge();
	int getHeight();
	std::string getGender();
	std::string getActivityLevel();

	//Method to handle all user inputs
	void collectUserInputs();

private:

	//User Inputs
	float weight;
	int age;
	int height;
	std::string gender;
	std::string activityLevel;
	char unitSystem; //'M' for Metric 'I' for Imperial

	//Private methods for input validation
	float validateWeight(float inputWeight);
	int validateAge(int inputAge);
	int validateHeight(int inputHeight);
	std::string validateGender(const std::string& inputGender);
	std::string validateActivityLevel(const std::string& inputActivityLevel);

	//Conversion methods
	float convertWeightToMetric(float weightInPounds);
	int convertHeightToMetric(int heightInInches);
};