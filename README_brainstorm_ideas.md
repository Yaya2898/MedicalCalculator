
Yaphet Yosief - Dec 2023 - Medical Calculator in C++ on Visual Studio

Personal BrainStorming Doc to serve as a railguard/guidline in this project and to avoid scope creep.


Medical Calculator Project (BMI, BMR, Daily Calorie Requirements)

//////////////////////////////////////////////////////////////////////////////////////////////
Project Description

This Medical Calculator is a C++ application designed to calculate essential health metrics such as Body Mass Index (BMI), Basal Metabolic Rate (BMR), and Daily Calorie Requirements. The application will take user input including age, height, gender, and activity level to provide accurate and personalized health information.


///////////////////////////////////////////////////////////////////////////////////////////
Features

User Inputs: Taking the following parameters (Weight, Age, Height, Gender, Activity Level) Imperial and Metric measurments will be accepted
BMI Calculator: Computes the Body Mass Index, indicating if a user is underweight, normal weight, overweight, or obese based on their height and weight.
BMR Calculator: Estimates the Basal Metabolic Rate, showing the number of calories the body needs at rest.
Daily Calorie Requirement Calculator: Calculates the total number of calories a user should consume in a day, based on their BMR and activity level.


Age: Used in BMR and daily calorie calculations.
Height: Required for BMI calculations.
Weight: Essential for both BMI and BMR calculations.
Gender: Impacts BMR calculation as metabolic rates differ between genders.
Activity Level: Determines the daily calorie needs. Activity levels can be categorized as sedentary, lightly active, moderately active, very active, or extra active.
How to Use

The user will be prompted to enter their age, height, weight, gender, and activity level.
Based on these inputs, the application will calculate and display the BMI, BMR, and daily calorie requirements.
The results will include interpretations, like BMI category or if the daily calorie intake is suitable for weight maintenance, loss, or gain.

////////////////////////////////////////////////////////////////////////////////////////////////
Development Plan

Phase 1: Setting Up the Environment
Install necessary tools (C++ compiler, IDE).
Create a basic structure for the project.

Phase 2: Implementing Basic Calculators
Develop functions to calculate BMI, BMR, and daily calorie requirements.
Implement basic user input handling and validation.

Phase 3: Enhancing User Experience
Develop a user-friendly interface for input and output.
Include detailed instructions and explanations for users.

Phase 4: Testing and Debugging
Perform unit testing on each calculator function.
Debug and refine based on test results.

Phase 5: Documentation and Final Touches
Create comprehensive documentation, including how to use the application and interpret the results.
Finalize and clean the code for readability and efficiency.
Possible Extensions

//////////////////////////////////////////////////////////////////////////////////////////
Future Phases: Goal Weight and Timeframe Features
Implement the feature to input goal weight and calculate the necessary caloric adjustments.
Develop algorithms to estimate the timeframe for reaching the goal weight based on activity intensity.


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Possible Extensions

GUI implementation for a more interactive experience.
Saving user history for tracking changes over time.
Incorporating more health metrics or personalized health recommendations.

GUI implementation for a more interactive experience.
Saving user history for tracking changes over time.
Incorporating more health metrics or personalized health recommendations.
Skills and Concepts Practiced

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Basic C++ programming (variables, loops, functions).
User input handling and validation.
Arithmetic operations and conditional logic.
Basic concepts of software development lifecycle.



////////////////////////////////////////////////////// Nice to Have ///////////////////////////////////////////////////////////////////////////////////////////////
Future Enhancements

Goal Weight Input: Allow users to input their goal weight.
Caloric Deficit/Surplus Calculation: Determine how many calories need to be burned or consumed to reach the goal weight.
Timeframe Estimation: Calculate an estimated timeframe (weeks/days) to achieve the goal weight based on the user's current calorie intake and activity intensity.


/////////////////////////////////////////////////////////////////////// Design Patterns to Keep in Mind & Other Things ///////////////////////////////////////////////////////////////

Single Responsibility Principle (SRP) - One responsibilty for each Class to reduce complexity 

Code Reusability: Aim to write reusable code. For example, if you have similar validation logic for user inputs across different calculators, consider creating a shared utility function.
Modularity: Keep your code modular - each module/class/file should handle its part of the functionality.
Readability and Maintainability: Write clean code with proper naming conventions, and maintain consistent coding styles. Comments and documentation are also important.


/*Project Overview:

The Medical Calculator is a simple yet practical tool that computes various health-related metrics. This can include calculations like Body Mass Index (BMI), Basal Metabolic Rate (BMR), daily calorie requirements, or drug dosage based on weight and age.
Key Concepts to Learn and Apply:

Basic arithmetic operations and conditional statements in C++.
Handling user input and output.
Data validation to ensure that the user inputs are in a valid range or format.
Developing a user-friendly console interface.
Potential Features and Enhancements:

Adding various calculators in one application and allowing the user to choose which one to use.
Implementing a graphical user interface (GUI) using libraries like Qt or wxWidgets, if you want to go beyond console-based applications.
Storing user history and providing recommendations based on previous inputs.
Challenges:

Ensuring accuracy in calculations.
Designing an intuitive user interface if opting for a GUI.
Handling exceptional cases and errors gracefully (like invalid inputs).*/


/////////////////////////// WHat Im doing/////////////////

Start with User_Input Class
bmi calculator
bmr calculator
calorie requirment calculator



/////////////////////////////////////////////Issues I have Run Into////////////////////////////////////////////////

- Determining an acceptable Height range between users. I settled on 0 feet to 10 feet for simplicity purposes considerng babies and freakishly tall people.
- Currently stumbled upon an issue where taking user height the Inches has not been accounted for. As a soloution I changed the data type from INT to Float to 
  accomdate users who are 5 feet and 3 inches input can be recieved as 5.3(feet) in the feet section.  

  - Encountered another issue in the ValidateActivitylevel function description: the issue was deciding how many activity levels there should be 
    after researching other BMI calclators on the internet i decded to implement the 5 differnt activity levels. The calculations and how the affect caloric intake and expedenture
  - will be determined later to ensure accuracy for users.



  - I adjusted collectUserInputs() to use validateAge() for age validation and handle the case where the age input is invalid. I will do the sae for the remaining 4
  parameters (weight, height, gender, activity level).


  explain changes here:

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


Whats Been Done:

User_Input Class:
I have created relevant methods to collect user input and validate the input. 
I have also created a method to display the user input and a method to clear the user input.

CalorieCalculator Class:

Calculators Class:

BMR Calculator Class:

BMI Calculator Class:

Med_Calc_Main Class:



Problems Faced: 

User_Input Class:
Currenlty has 5 responsibilities = 1. Collect User Input 2. Validate User Input 3. Conversion of User Input  4. Get User Input 5. Store User Input
Solution: I will create 3 new classes to handle the 3 responsibilities that are not related to the User_Input Class. UserInputCollecor, InputValidator, UnitConverter

CalorieCalculator Class:

Calculators Class:

BMR Calculator Class:

BMI Calculator Class:

Problem 1:
    - Currently experiencing an issue with the BMI calculator where when the user attempts to input their height within the accepted 
    range an error pops up saying that the height is invalid.

  I have tried to fix this issue by changing the data type from int to float but the issue still persists.
  I will continue to work on this issue and update the read me once the issue is resolved.

  Solution:
  - The issue identifed turned out to be an operator issue:
    the problem if statment was -- if (inputHeight > minHeight || inputHeight < maxHeight) 
    the solution was to change the if statement to -- if (inputHeight < minHeight || inputHeight > maxHeight)
  - In conclusion the issue was that the operator was incorrect and the if statement was not checking for the correct range of values.
 
 Problem 2:
 - Currently experiencing a problem with the Gender Input: When the user is prompted to input their Gender which is Male/Female or NA the error message pops up.
 -   I will continue to work on this issue and update the read me once the issue is resolved.
 
 Solution: After numerous attempts to circumvente the issue I decided to change the data type from string to int and changed the prompting message
 by assigning Male the Value 1 , Female the Value 2 and NA the Value 3, as shown here: if (inputGender == 1 || inputGender == 2 || inputGender == 3)
 I also updated the else return statement to an int in this case -1 instead of the previous string to accomodate the change in data type.
  These changes resulted in the issue being resolved and the program now runs as intended in that regard.

Problem 3:
- Currently experiencing an issue with the Activity Level Input: When the user is prompted to input their Activity Level which is
- Sedentary, Lightly Active, Moderately Active, Very Active, Extra Active the error message pops up. I suspect the issue is related to the data type as before.
- I will continue to work on this issue and update the read me once the issue is resolved.

Solution:
- The issue was related to the data type as suspected. I changed the data type from string to int and changed the prompting message
 by assigning Sedentary the Value 1 , Lightly Active the Value 2, Moderately Active the Value 3, Very Active the Value 4, Extra Active the Value 5
 as shown here: if (inputActivityLevel == 1 || inputActivityLevel == 2 || inputActivityLevel == 3 || inputActivityLevel == 4 || inputActivityLevel == 5)
 I also updated the else return statement to an int in this case -1 instead of the previous string to accomodate the change in data type.
  These changes resulted in the issue being resolved and the program now runs as intended in that regard.

  Problem 4:
  - Currently experiencing an issue with the Weight Input: When the user is prompted to input their Weight which is in the range of 0 to 1000 the error message pops up.
  - I will continue to work on this issue and update the read me once the issue is resolved.

  Solution:
  - The issue was related to the data type as suspected. I changed the data type from int to float and changed the prompting message
 by assigning 0 as the minimum weight and 1000 as the maximum weight as shown here: if (inputWeight < minWeight || inputWeight > maxWeight)
 I also updated the else return statement to an int in this case -1 instead of the previous string to accomodate the change in data type.
  These changes resulted in the issue being resolved and the program now runs as intended in that regard.

  Problem 5:
  - Currently experiencing an issue with the Age Input: When the user is prompted to input their Age which is in the range of 0 to 120 the error message pops up.
  - I will continue to work on this issue and update the read me once the issue is resolved.

  Solution:
  - The issue was related to the data type as suspected. I changed the data type from int to float and changed the prompting message
 by assigning 0 as the minimum age and 120 as the maximum age as shown here: if (inputAge < minAge || inputAge > maxAge)
 I also updated the else return statement to an int in this case -1 instead of the previous string to accomodate the change in data type.
 These changes resulted in the issue being resolved and the program now runs as intended in that regard.

  Problem 6:
 - Currently experiencing an "issue" with the BMI Calculator. I think i just need to define the formula for the BMI calculation and the rest should be fine.
 
 Solution:
 WIll EXPLAIN TMRW!!


Med_Calc_Main Class: