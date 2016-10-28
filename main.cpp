//  main.cpp
//  Hangman
//
//  Created by Angeline Indahsi on 10/13/16.
//  Copyright © 2016 Angeline Indahsi. All rights reserved.

#include <iostream>
#include <string>
using namespace std;

const int maxTries = 6;
int fill (char, string, string&);

int main ()
{
    char letter;
    string correctWord;
    string wrongWord;
    int numberOfWrong = 0;
    string words[] =
    {
        "Alpaca", "Butterfly", "Crocodile", "Crow", "Gazelle", "Hamster", "Lizard", "Hippopotamus", "Kangaroo", "Leopard", "Mongoose", "Tiger", "Lion", "Cheetah", "Panther", "Mouse", "Armadillo", "Rhinoceros", "Giraffe", "Sloth", "Otter", "Hyena"
    };
    int n=rand()%10; //The words appear will be random
    correctWord=words[n];
    string unknownWord(correctWord.length(), '_' ); //To replace the unkown words with _
    
    cout << "Welcome to Hangman! Now try to guess a name of an animal!" << endl;
    cin >> letter;
    
    while(numberOfWrong<maxTries)
    {
        cout << unknownWord;
        cout << "Guess the letter: " << endl;
        cin >> letter;
    }
    
    if (fill(letter, correctWord, unknownWord)==0)
    {
        cout << "Whoops! Wrong letter!" << endl;
        numberOfWrong++;
    }
    else
    {
        cout << endl << "Yay! You got the correct letter! Keep it up!" << endl;
    }
    
    cout << "You have " << maxTries - numberOfWrong << " guessess left!" << endl;
    
    if (correctWord == unknownWord)
    {
        cout << correctWord << endl;
    }
    
    if (numberOfWrong == maxTries)
    {
        cout << "You have been hanged!" << endl;
        cout << "Sorry you lose!" << endl;
        cout << "The word is: " << correctWord << endl;
    }
    return 0;
}


