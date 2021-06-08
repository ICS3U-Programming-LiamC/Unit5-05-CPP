// Copyright (c) 2021 Liam Csiffary All rights reserved.
//
// Created by: Liam Csiffary
// Date: May June, 2021
// This program STUFF STUFF

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string.h>


std::string Capper(std::string lowerCase) {
    std::string lowerCaseNew;
    // This gets the length of the string
    int strLen = lowerCase.length();
    char char_array[strLen + 1];
    strcpy (char_array, lowerCase.c_str());
    
    for (int counter = 0; counter < strLen; counter++) {
        lowerCaseNew += std::toupper(char_array[counter]);
    }
    
    return lowerCaseNew;
}


std::string FormatAddress(std::string addresseeFunc, std::string strNumFunc,
    std::string strNameFunc, std::string postalFunc, std::string cityFunc,
    std::string provFunc, std::string aptNumFunc = "") {

    // declare new varaibles
    std::string newPostalFunc;
    std::string addresseeFuncUpper;
    int each;

    // turns everything into caps
    addresseeFuncUpper = Capper(addresseeFunc);
    strNumFunc = Capper(strNumFunc);
    strNameFunc = Capper(strNameFunc);
    postalFunc = Capper(postalFunc);
    cityFunc = Capper(cityFunc);
    provFunc = Capper(provFunc);
    aptNumFunc = Capper(aptNumFunc);

    std::string text;

    for (each = 0; each < 7; each++) {
        if (each == 3) {
            newPostalFunc = (newPostalFunc + " " + postalFunc[each]);
        } else {
            newPostalFunc = (newPostalFunc + postalFunc[each]);
        }
    }
    // std::cout << "this" << aptNumFunc << "this";
    if (aptNumFunc == "") {
        text = addresseeFuncUpper + "\n" + strNumFunc + " " + strNameFunc + "\n" +
        cityFunc + " " + provFunc + "  " + newPostalFunc;
    } else {
        text = addresseeFuncUpper + "\n" + aptNumFunc + "-" + strNumFunc + " " +
        strNameFunc + "\n" + cityFunc + " " + provFunc + "  " + newPostalFunc;
    }

    return text;
}


int main() {
    // variables
    std::string addressee;
    std::string strNum;
    std::string strName;
    std::string aptOrNo;
    std::string aptNum;
    std::string city;
    std::string prov;
    std::string postal;

    std::string result;

    std::cout << "Who are you sending this to: ";
    getline(std::cin, addressee);

    std::cout << "What is the street number: ";
    getline(std::cin, strNum);

    std::cout << "What is the street name: ";
    getline(std::cin, strName);

    std::cout << "Do you have an apartment(y/n): ";
    getline(std::cin, aptOrNo);
    if (aptOrNo == "y" || aptOrNo == "Y") {
        std::cout << "What is the apartment number: ";
        getline(std::cin, aptNum);;
    }

    std::cout << "What is the City: ";
    getline(std::cin, city);
    std::cout << "What is the Province: ";
    getline(std::cin, prov);
    std::cout << "What is the postal code: ";
    getline(std::cin, postal);

    if (aptOrNo == "y" || aptOrNo == "Y") {
        result = FormatAddress(addressee, strNum, strName,
        postal, city, prov, aptNum);
    } else {
        result = FormatAddress(addressee, strNum, strName, postal, city, prov);
    }

    std::cout << result;
}
