//Will Langas
//Grade Tool
//12/6/2017

#include <iostream>
using namespace std;

int short counter1 = 0; //Global counter variable

int errorMessagesPrint(){ //Function print error messages
    string errorMessages[6]= {"101- Invalid input for honors grade","102- Invalid input for non honors grade", "103- Invalid input for honors or non honors classes", "104-Invalid function choice", "105-Invalid GPA", "106-Computational error within final Grade calculator, check input values"};
    //Array of possible error messages
    for(counter1 = 0; counter1 < 6; counter1++){
        cout << errorMessages[counter1] << endl;
    }
    return 0;
}

int instructions(){ //Function print instructions
     string instructions[13] = {"Instructions for use", "1. Enter the amount of honors and non honors classes you are taking", "2. Precede to type in your letter grade for each class you take. Use capital letters and refer to the class list", "3. Finish entering letter grades and your academic GPA will be displayed","For Cumulative GPA:", "1. Enter total semesters taken", "2. Enter each GPA by semester", "3. Receive cumulative GPA over the chosen amount of semesters", "For Final Need:", "1. Enter a number for the weight of your final (Ex: 20 for 20%","2. Enter your desired grade", "3. Enter your current grade", "4. Receive the grade you must achieve on the final"};
    for(counter1= 0; counter1 < 13; counter1++){
        cout << instructions[counter1] << endl;
        //Loop through and print instructions
    }
    return 0;
}

int cumulativeGPA(){ //Calculate cumulative GPA over semesters
    int short semesters = 0;
    float sumOfNumbers = 0.0; //Sum of GPAs
    float average; //Final value
    
    cout << "How many semesters have you finished?" << endl;
    cin >> semesters; //Number of total semesters
    
    float points[semesters]; //Array of size semesters
    for (counter1 = 0; counter1 < semesters; counter1++)
    {
        cout << "Enter a GPA" << endl;
        cin >> points[counter1];
        sumOfNumbers += points[counter1];
    }
    
    average = sumOfNumbers / semesters; //Find average
    if(average > 5){
        cout << "Error 105" << endl; //Elminates invalid GPAs
    } else if(average > 0 && average <= 5){
        cout << "Your average GPA over " << semesters << " semesters is " << average << endl;
    }
    return 0;
}

int finalNeed(){ //Finds a needed final grade
    
    float finalWorth = 0; //Weight of final, no "%" sign
    cout << "How much is your final worth?" << endl;
    cin >> finalWorth;
    
    float gradeWant = 0; //Semester grade desire
    cout << "What grade are you aiming for?" << endl;
    cin >> gradeWant;
    
    float currentGrade = 0; //Current gpa
    cout << "What is your current grade?" << endl;
    cin >> currentGrade;
    
    float finalNeed = 0; //Final print variable
    finalNeed = (gradeWant - (1 - (finalWorth/100))*currentGrade)/finalWorth;
    finalNeed = finalNeed * 100;
    if(finalNeed > 0){
        cout << "You need to get " << finalNeed << "% or higher to receive a " << gradeWant << " in the class" << endl;
    } else { //Print final message
        cout << "Error 106";
    }
    
    return 0;
}

int currentGPA(){ //Function to calculate GPA
//All Necessary variables
    int short unsigned honors = 0; //# of honors classes
    int short unsigned nonHonors = 0; //# of non Honors classes
    float honorsSum = 0.0; //Sum of honors points
    float nonHonorsSum = 0.0; //Sum of non honors points
    string honorsGrades = " "; //Used to record grades
    string nonHonorsGrades = " ";
    
    cout << "Here are some class possibilities:" << endl;
    
    string classExamples[7] = {"History", "Science", "Foreign Languages", "English", "Math", "Electives"}; //Class List
    
    for(counter1 = 0; counter1 < 7; counter1++){ //Print classes
        cout << classExamples[counter1] << endl;
    }

    //Records num of classes in each category + find total classes
    cout << "How many honors classes do you take?" << endl;
    cin >> honors;
    cout<<"How many non honors classes do you take?" << endl;
    cin >> nonHonors;
    int short totalClasses = honors + nonHonors;
    
    if(honors > 0){ //Honors add to sum
        for(counter1 = 0; counter1 < honors; counter1++){
        
        cout << "Enter an Honors Grade (Capital Letter)" <<endl;
        cin >> honorsGrades;
            
            if(honorsGrades == "A" ){
                honorsSum += 5.0;
            } else if(honorsGrades == "B"){
                honorsSum += 4.0;
            } else if(honorsGrades == "C"){ //Adds based on grade
                honorsSum += 3.0;
            } else if(honorsGrades == "D"){
                honorsSum += 2.0;
            } else if(honorsGrades == "F"){
                honorsSum += 1.0;
            } else{
                cout << "Error 101";
                break;
            } //End conditional for honors
        } //End loop for honors
            
    if(nonHonors > 0){ //Non honors add to sum
        for(counter1 = 0; counter1 < nonHonors; counter1++){
        
        cout << "Enter an non honors Grade (Capital Letter)" <<endl;
        cin >> nonHonorsGrades;
            
            if(nonHonorsGrades == "A" ){
                nonHonorsSum += 4.0;
            } else if(nonHonorsGrades == "B"){
                nonHonorsSum += 3.0;
            } else if(nonHonorsGrades == "C"){
                nonHonorsSum += 2.0;
            } else if(nonHonorsGrades == "D"){
                nonHonorsSum += 1.0;
            } else if(nonHonorsGrades == "F"){
                nonHonorsSum += 0.0;
            } else{
                cout << "Error 102";
                break;
            } //End conditional
        
            float sumOfPoints = honorsSum + nonHonorsSum;
            float gpa = sumOfPoints/totalClasses; //Find GPA
            
            cout << "Your academic gpa is: " << gpa << endl;
            }//End loop non honors
        } //End Honors conditional
    } else if(honors < 0 || nonHonors < 0){
        cout << "Error 103";
    } //End initial conditional
    return 0;
}//End function

int masterCalculator(){ //Main menu and options to function
    cout << "Welcome to the Grade Tool Beta" << endl;
    cout << "Version 2.0" << endl;
    cout << "Enter 1 to use GPA calculator" << endl;
    cout << "Enter 2 to find cumulative GPA" << endl;
    cout << "Enter 3 to find a needed final grade" << endl;
    cout << "Enter 4 to read instructions" << endl;
    cout << "Enter 5 to read error messages" << endl;
    
    int optionFunction = 0;
    cin >> optionFunction;
    
    if(optionFunction == 1){
        currentGPA();
        cout << " " << endl;
        masterCalculator();
    } else if(optionFunction == 2){
        cumulativeGPA();
        cout << " " << endl;
        masterCalculator();
    } else if(optionFunction == 3){ //Based on #, does function
        finalNeed();
        cout << " " << endl;
        masterCalculator();
    } else if(optionFunction == 4){
        instructions();
        cout << " " << endl; //endl important don't delete
        masterCalculator();
    } else if(optionFunction == 5){
        errorMessagesPrint();
        cout << " " << endl;
        masterCalculator();
    } else {
        cout << "Error 104" << endl;
        return 0;
    }
    return 0;
}

int main(){
    masterCalculator();
    }
