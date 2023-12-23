//Implementation of user input handling and validation logic

#include "User_Input.h"


//User_Input::User_Input() {};

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


//had to optimize the code below to avoid repetion: Will document in read me what the problem was and the solution implemented before i remove this code

/*//this method ensures that in the event a user incorrectly inputs 1 or more parameters but other parameters were correclty inputted the user will not have to restart from scratch 
void User_Input::collectUserInputs() {
    bool ageValid = false, weightValid = false, heightValid = false, genderValid = false, activitylevelValid = false; //flags for every parameters set to false

    while (!(ageValid && weightValid && heightValid && genderValid && activitylevelValid)) {

        //age input loop
        if (!ageValid) {
            while (true) {
                std::cout << "Enter your age: ";
                int inputAge;
                std::cin >> inputAge;

                if (validateAge(inputAge) != -1) {
                    this->age = inputAge;
                    ageValid = true;
                    break;
                }
                else {
                    std::cerr << "Invalid age. Please try again." << std::endl;
                }
            }
        }
    }
}


//this method ensures that in the event a user incorrectly inputs 1 or more parameters but other parameters were correclty inputted the user will not have to restart from scratch 
void User_Input::collectUserInputs() {
    bool ageValid = false, weightValid = false, heightValid = false, genderValid = false, activitylevelValid = false; //flags for every parameters set to false

    while (!(ageValid && weightValid && heightValid && genderValid && activitylevelValid)) {

        //Weight input loop
        if (!weightValid) {
            while (true) {
                std::cout << "Enter your weight: ";
                int inputWeight;
                std::cin >> inputWeight;

                if (validateWeight(inputWeight) != -1) {
                    this->weight = inputWeight;
                    weightValid = true;
                    break;
                }
                else {
                    std::cerr << "Invalid weight. Please try again." << std::endl;
                }
            }
        }
    }
}

void User_Input::collectUserInputs() {
    bool ageValid = false, weightValid = false, heightValid = false, genderValid = false, activitylevelValid = false; //flags for every parameters set to false

    while (!(ageValid && weightValid && heightValid && genderValid && activitylevelValid)) {

        //height input loop
        if (!heightValid) {
            while (true) {
                std::cout << "Enter your height: ";
                int inputHeight;
                std::cin >> inputHeight;

                if (validateHeight(inputHeight) != -1) {
                    this->height = inputHeight;
                    heightValid = true;
                    break;
                }
                else {
                    std::cerr << "Invalid height. Please try again." << std::endl;
                }
            }
        }
    }
}

void User_Input::collectUserInputs() {
    bool ageValid = false, weightValid = false, heightValid = false, genderValid = false, activitylevelValid = false; //flags for every parameters set to false

    while (!(ageValid && weightValid && heightValid && genderValid && activitylevelValid)) {

        //height input loop
        if (!genderValid) {
            while (true) {
                std::cout << "Enter your gender: ";
                std::string inputGender;
                std::getline (std::cin, inputGender);

                if (validateGender(inputGender) == "Valid") {
                    this->gender = inputGender;
                    genderValid = true;
                    break;
                }
                else {
                    std::cerr << "Invalid gender. Please try again." << std::endl;
                }
            }
        }
    }
}



void User_Input::collectUserInputs() {
    bool ageValid = false, weightValid = false, heightValid = false, genderValid = false, activitylevelValid = false; //flags for every parameters set to false

    while (!(ageValid && weightValid && heightValid && genderValid && activitylevelValid)) {

        //height input loop
        if (!activitylevelValid) {
            while (true) {
                std::cout << "Enter your activity level: ";
                std::string inputActivityLevel;
                std::getline (std::cin, inputActivityLevel);

                if (validateActivityLevel(activityLevel) == "Valid") {
                    this->activityLevel = activityLevel;
                    activitylevelValid = true;
                    break;
                }
                else {
                    std::cerr << "Invalid activity. Please try again." << std::endl;
                }
            }
        }
    }
}*/



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

    const float minHeight = 0; // made it 0 for babies
    const float maxHeight = 10; // made it 10 for tall people


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


float User_Input::convertWeightToMetric(float weightInPounds) {
    return weightInPounds * 0.453592;
}


float User_Input::convertHeightToMetric(float heightInInches) {
    return heightInInches * 2.54;
}