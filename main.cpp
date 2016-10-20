//  main.cpp
//  Hangman
//
//  Created by Angeline Indahsi on 10/13/16.
//  Copyright © 2016 Angeline Indahsi. All rights reserved.


#include <iostream>
#include <string>
using namespace std;

int main () {
    int chancesLeft;
    char letter;
    string word;
    string wrongWord;
    string underscore;
    int numberOfWrong;
    string words[] =
    {
        "Alpaca", "Butterfly", "Crocodile", "Crow", "Gazelle", "Hamster", "Lizard", "Hippopotamus", "Kangaroo", "Leopard", "Mongoose"
    };
    int n=rand()%10;
    
    cout << "Welcome to Hangman! Now try to guess a name of an animal!" << endl;
    cin >> letter;
    
    
    
    for (int i=0; i!=word.length(); i++) {
        if (word.at(i) == ' ') {
            underscore += "_";
        } else {
            underscore += "_";
        }
    }
    
    for (int i=0; i!=50; ++i) {
        cout << endl;
    }
    
    if (numberOfWrong == 6) {
        numberOfWrong = 6 - chancesLeft;
        cout << "Sorry, you lose! The word is " << words << endl;
    }
    
    
    
    cout << "You have " << chancesLeft << " tries left." << endl;
    
    if (underscore == word) {
        cout << "Congratulations! You are correct!" << endl;
    }
    
    return 0;
}


