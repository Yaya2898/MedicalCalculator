//Implementation of user input handling and validation logic

#include "User_Input.h"


//User_Input::User_Input() {}; constructor i need to define later

//user input Getters
float User_Input::getWeight() { 
    return this->weight;  
}

int User_Input::getAge() {
    return this->age;  
}

float User_Input::getHeight() {
    return this->height;  
}

std::string User_Input::getGender() {
    return this->gender;  
}

std::string User_Input::getActivityLevel() {
    return this->activityLevel;
}

// Added this method to get the unit system to help with BMI calculation
char User_Input::getUnitSystem() {
    return this->unitSystem;
}


//////////////////////////////////////////// UTILITY METHODS ////////////////////////////////////////////

//collect int
void User_Input::collectIntegerInput(const std::string& prompt, int (User_Input::* validate)(int), int& member) { 
    while (true) {
        std::cout << prompt;
        int input;
        std::cin >> input;
        if (!std::cin.fail() && (this->*validate)(input) != -1) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            member = input;
            break;
        }
        else {
            std::cerr << "Invalid input. Please try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        }
    }
}


//collect float
void User_Input::collectFloatInput(const std::string& prompt, float (User_Input::* validate)(float), float& member) {
    while (true) {
        std::cout << prompt;
        float input;
        std::cin >> input;
        if (!std::cin.fail() && (this->*validate)(input) != -1) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            member = input;
            break;
        }
        else {
            std::cerr << "Invalid input. Please try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

//collect string
void User_Input::collectStringInput(const std::string& prompt, std::string(User_Input::* validate)(const std::string&), std::string& member) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        if ((this->*validate)(input) == "Valid") {
            member = input;
            break;
        }
        else {
            std::cerr << "Invalid input. Please try again.\n";
        }
    }
}

// this is where user inputs are being collected and validated
void User_Input::collectUserInputs() {
    // Collect age
    collectIntegerInput("Enter your age: ", &User_Input::validateAge, this->age);

    // Collect weight
    collectFloatInput("Enter your weight: ", &User_Input::validateWeight, this->weight);

    // Collect height
    collectFloatInput("Enter your height: ", &User_Input::validateHeight, this->height);

    // Collect gender
    collectStringInput("Enter your gender (M/F): ", &User_Input::validateGender, this->gender);

    // Collect activity level
    collectStringInput("Enter your activity level (e.g., sedentary, active): ", &User_Input::validateActivityLevel, this->activityLevel);
}


//////////////////////////////////////////// VALIDATION METHODS ////////////////////////////////////////////

//activity level for users to choose
std::string User_Input::validateActivityLevel(const std::string& inputActivityLevel) {

    if (inputActivityLevel == "Sedentary" || inputActivityLevel == "Lightly Active" || inputActivityLevel == "Moderatly Active" || inputActivityLevel == "Very Active" || inputActivityLevel == "Extra Active")

        return inputActivityLevel;
    else {   
        return "Invalid Activity Level";
    }
};


std::string User_Input::validateGender(const std::string& inputGender) {

    if (inputGender == "Male" || inputGender == "Female" || inputGender == "NA")
    {
        return inputGender; //valid input
    }
        
    else {
        
        return "Invalid Gender"; //invalid input
    }
};


float User_Input::validateHeight(float inputHeight) { // do height research than implement limits


//defining a reasonable height

    const float minHeight = 0.0; // made it 0 for babies
    const float maxHeight = 10.0; // made it 10 for tall people


//ensuring height userinput is within defined limits

    if (inputHeight > minHeight || inputHeight < maxHeight) {
    
        std::cerr << "Invalid Height. Please enter a value between " << minHeight << " and " << maxHeight << " Height " << std::endl;
        return -1; //error
    }

 //returning user height if adhered to properly

   return inputHeight;

};


//validates age input
int User_Input::validateAge(int inputAge) {

//whats a reasonable Age Limit

    const int minAge = 0;
    const int maxAge = 100;

//check if the Age is within the range
    
    if (inputAge < minAge || inputAge > maxAge) {
        std::cerr << "Invalid Age. Please enter a value between " << minAge << " and " << maxAge << " Age. " << std::endl;
        return -1; //error
    }

    //If Age is within Age return it
    return inputAge;
};



float User_Input::validateWeight(float inputWeight) {
    //defined the acceptable range for weight
    const float minWeight = 0.0;  //minimum reasonable weight in pounds
    const float maxWeight = 1400.0; //maximum reasonable weight in pounds (approx. 635 KG)

    //check if the weight is within the range
    if (inputWeight < minWeight || inputWeight > maxWeight) {
        std::cerr << "Invalid weight. Please enter a value between " << minWeight << " and " << maxWeight << " Pounds." << std::endl;
        return -1; //error
    }

    //if the weight is valid, return it
    return inputWeight;
}


//////////////////////////////////////////// CONVERSION METHODS ////////////////////////////////////////////

float User_Input::convertWeightToMetric(float weightInPounds) {
    return weightInPounds * 0.453592;
}


float User_Input::convertHeightToMetric(float heightInInches) {
    return heightInInches * 2.54;
}