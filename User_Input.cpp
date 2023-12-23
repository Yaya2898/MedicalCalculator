//Implementation of user input handling and validation logic

#include "User_Input.h"


/*int validateHeight(int inputHeight);
	std::string validateGender(const std::string& inputGender);
	std::string validateActivityLevel(const std::string& inputActivityLevel);*/



//int User_Input::validateHeight(int inputHeight) { // do height research than implement limits


//defining a reasonable height

    //const int minHeight = IDK // research little people heights
    //const int maxHeight = IDK // research big people heights


//ensuring height userinput is within defined limits

    /*if (inputHeight > minHeight || inputHeight < maxHeight) {
    
        std::cerr << "Invalid Height. Please enter a value between " << minHeight << " and " << maxHeight << " Height " << std::endl;

    }*/




 //returning user height if adhered to properly

   //return inputHeight;


//};



int User_Input::validateAge(int inputAge) {

//whats a reasonable Age Limit

    const int minAge = 0;
    const int maxAge = 100;

//check if the Age is within the range
    
    if (inputAge < minAge || inputAge > maxAge) {
        std::cerr << "Invalid Age. Please enter a value between " << minAge << " and " << maxAge << " Age. " << std::endl;
    
    }
    //If Age is withi Age return it
    return inputAge;
};



float User_Input::validateWeight(float inputWeight) {
    //defined the acceptable range for weight
    const float minWeight = 0.0;  // Minimum reasonable weight in kilograms
    const float maxWeight = 635.0; // Maximum reasonable weight in kilograms (approx. 1400 pounds)

    //check if the weight is within the range
    if (inputWeight < minWeight || inputWeight > maxWeight) {
        std::cerr << "Invalid weight. Please enter a value between " << minWeight << " and " << maxWeight << " kilograms." << std::endl;
        return -1; // Returning -1 or another sentinel value to indicate an error
    }

    //if the weight is valid, return it
    return inputWeight;
}


float User_Input::convertWeightToMetric(float weightInPounds) {
    return weightInPounds * 0.453592;
}


int User_Input::convertHeightToMetric(int heightInInches) {
    return heightInInches * 2.54;
}