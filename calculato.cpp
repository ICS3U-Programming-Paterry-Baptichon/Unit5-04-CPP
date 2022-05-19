// Copyright (c) 2022 Paterry Baptichon All rights reserved

// Created by Paterry Baptichon
// Created on 2022-05-18
// this program t has a function that accepts the operation as well as the 
// two decimals
// It asks for 3 parameters: the sign of the operation 
// as a char and the two numbers as floats

#include <iostream>
#include <string>


float Calculate(std::string sign, float number1, float number2) {
    float answer;

    // check what the operator is and then calculate the answer
    if (sign == "-") {
        answer = number1 - number2;
    } else if (sign == "+") {
        answer = number1 + number2;
    } else if (sign == "*") {
        answer = number1 * number2;
    } else if (sign == "/") {
        answer = number1 / number2;
    } else if (sign == "%") {
        try {
            int number1B = (int)number1;
            int number2B = (int)number2;
            answer = (float)(number1B % number2B);
        } catch  (std::invalid_argument) {
            std::cout << "Must be a number!";
        }
    } else {
        std::cout << "invalid";
    }
    return answer;
}


int main() {
    // declare variables
    std::string sign, number1AsString, number2AsString;
    float number1, number2;
    float answer;

    // get the user input
    std::cout << "Enter the operation you want to perform (+, -, /, *, %): ";
    std::cin >> sign;
    std::cout << "Enter the first number: ";
    std::cin >> number1AsString;
    std::cout << "Enter the second number: ";
    std::cin >> number2AsString;


    // error check the operator and then the numbers
    if (sign == "+" || sign == "-" || sign == "/" ||
sign == "*" || sign == "%") {
        try {
            // cast the numbers to a float
            number1 = std::stof(number1AsString);
            number2 = std::stof(number2AsString);

            // call the function
            answer = Calculate(sign, number1, number2);

            // display the answer
            std::cout << "The result of " << number1 << " " << sign <<
" " << number2 << " is " << answer << "\n";
        } catch  (std::invalid_argument) {
            std::cout << "Must be a valid number!";
}
    } else {
        std::cout << sign << " is not a recognized operater\n";
    }
}

