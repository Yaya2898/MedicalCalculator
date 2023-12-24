#pragma once
//Defines a class or functions for handling user input and validation.
#include <iostream>
#include <string>
#include <sstream>
#include <string>

// what do i want other classes to use/access

class User_Input {

public:

	//User_Input(); //Constructor

	//Getters for UserInput
	float getWeight();
	int getAge();
	float getHeight();
	int getGender();
	int getActivityLevel();
	char getUnitSystem();

	//Method to handle all user inputs
	void collectUserInputs();


private:

	//User Inputs
	float weight;
	int age;
	float height;
	int gender;
	int activityLevel;
	char unitSystem; //'M' for Metric 'I' for Imperial

	//Private methods for input validation
	float validateWeight(float inputWeight);
	int validateAge(int inputAge);
	float validateHeight(float inputHeight);
	int validateGender(int inputGender);
	int validateActivityLevel(int inputActivityLevel);


	//Conversion methods
	float convertWeightToMetric(float weightInPounds);
	float convertHeightToMetric(float heightInInches);

	//Utility functions for different types of input
	void collectIntegerInput(const std::string& prompt, int (User_Input::* validate)(int), int& member);
	void collectFloatInput(const std::string& prompt, float (User_Input::* validate)(float), float& member);
	void collectStringInput(const std::string& prompt, std::string(User_Input::* validate)(const std::string&), std::string& member);
};