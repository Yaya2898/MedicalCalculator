//Implementation of user input handling and validation logic

#include "User_Input.h"
#include <cctype>
#include <locale>


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

int User_Input::getGender() {
    return this->gender;  
}

int User_Input::getActivityLevel() {
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
    collectIntegerInput("Enter your gender (1 For Male, 2 For Female 3 For NA): ", &User_Input::validateGender, this->gender);

    // Collect activity level
    collectIntegerInput("Enter your activity level based on intensity (1 For sedentary, 2 For Lightly Active, 3 For Moderatly Active, 4 For Very Active, 5 For Extra Active ): ", &User_Input::validateActivityLevel, this->activityLevel);
}


//////////////////////////////////////////// VALIDATION METHODS ////////////////////////////////////////////

//activity level for users to choose
int User_Input::validateActivityLevel(int inputActivityLevel) {

    if (inputActivityLevel == 1 || inputActivityLevel == 2 || inputActivityLevel == 3 || inputActivityLevel == 4 || inputActivityLevel == 5)

        return inputActivityLevel;
    else {   
        return -1; //"Invalid Activity Level";
    }
};


int User_Input::validateGender(int inputGender) {



    if (inputGender == 1 || inputGender == 2 || inputGender == 3)
    {
        return inputGender; //valid input
    }
        
    else {
        
        return -1; //invalid input
    }
};


float User_Input::validateHeight(float inputHeight) { // do height research than implement limits


//defining a reasonable height

    const float minHeight = 0.0; // made it 0feet for babies
    const float maxHeight = 10.0; // made it 10 feet tall for any giants that want to use this program

//ensuring height userinput is within defined limits

    if (inputHeight < minHeight || inputHeight > maxHeight) {
    
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