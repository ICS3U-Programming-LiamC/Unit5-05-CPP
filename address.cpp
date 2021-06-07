// Copyright (c) 2021 Liam Csiffary All rights reserved.
//
// Created by: Liam Csiffary
// Date: May June, 2021
// This program STUFF STUFF

#include <iostream>
#include <cmath>


std::string FormatAddress(string addresseeFunc, std::string strNumFunc,
    std::string strNameFunc, std::string postalFunc, std::string cityFunc,
    std::string provFunc, std::string aptNumFunc = "") {

    std::string addresseeFunc;
    std::string strNumFunc;
    std::string strNameFunc;
    std::string aptOrNoFunc;
    std::string aptNumFunc;
    std::string cityFunc;
    std::string provFunc;
    std::string postalFunc;
    std::string newPostalFunc;
    int each;

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
        text = addresseeFunc + "\n" + strNumFunc + " " + strNameFunc + "\n" +
        cityFunc + " " + provFunc + "  " + newPostalFunc;
    } else {
        text = addresseeFunc + "\n" + aptNumFunc + "-" + strNumFunc + " " +
        strNameFunc + "\n" + cityFunc + " " + provFunc + "  " + newPostalFunc;
    }

    return text;
}


int main() {
    // variables
    string addressee;
    std::string strNum;
    std::string strName;
    std::string aptOrNo;
    std::string aptNum;
    std::string city;
    std::string prov;
    std::string postal;

    std::string result;

    std::cout << "Who are you sending this to: ";
    std::cin >> addressee;

    std::cout << "What is the street number: ";
    std::cin >> strNum;

    std::cout << "What is the street name: ";
    std::cin >> strName;

    std::cout << "Do you have an apartment(y/n): ";
    std::cin >> aptOrNo;
    if (aptOrNo == "y" || aptOrNo == "Y") {
        std::cout << "What is the apartment number: ";
        std::cin >> aptNum;
    }

    std::cout << "What is the City: ";
    std::cin >> city;
    std::cout << "What is the Province: ";
    std::cin >> prov;
    std::cout << "What is the postal code: ";
    std::cin >> postal;

    if (aptOrNo == "y" || aptOrNo == "Y") {
        result = FormatAddress(addressee, strNum, strName,
        postal, city, prov, aptNum);
    } else {
        result = FormatAddress(addressee, strNum, strName, postal, city, prov);
    }

    std::cout << result;
}
