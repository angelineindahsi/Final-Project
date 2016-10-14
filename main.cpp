//  main.cpp
//  Hangman
//
//  Created by Angeline Indahsi on 10/13/16.
//  Copyright © 2016 Angeline Indahsi. All rights reserved.


#include <iostream>
#include <string>
using namespace std;

int main () {
    char letter;
    string word;
    string wrongWord;
    string underscore;
    int numberOfWrong;
    
    for (int i=0; i!=word.length(); i++) {
        if (word.at(i) == '') {
            underscore += "_";
        } else {
            underscore += "_";
        }
    }
    
    for (int i=0; i!=50; ++i) {
        cout << endl;
    }
    
    if (numberOfWrong == 6) {
        cout << "Sorry, you lose! The word is " << word << endl;
    }
    
    cout << "This word has " << word.length() << "letters." << endl;
    cout << "You have " << 6 - wrongWord << "tries left." << endl;
    
    if (underscore == word) {
        cout << "Congratulations! You are correct!" << endl;
    }
    
    return 0;
}


