//  main.cpp
//  Hangman
//
//  Created by Angeline Indahsi on 10/13/16.
//  Copyright © 2016 Angeline Indahsi. All rights reserved.

#include <iostream>
#include <string>
using namespace std;

const int maxTries = 6;
int letterFill (char, string, string&);

int main()
{
    string start;
    char letter = '\0';
    string correctWord;
    string wrongWord;
    int numberOfWrongGuess = 0;
    string words[] =
    {
        "Alpaca",
        "Butterfly",
        "Crocodile",
        "Crow",
        "Gazelle",
        "Hamster",
        "Lizard",
        "Hippopotamus",
        "Kangaroo",
        "Leopard",
        "Mongoose",
        "Tiger",
        "Lion",
        "Cheetah",
        "Panther",
        "Mouse",
        "Armadillo",
        "Rhinoceros",
        "Giraffe",
        "Sloth",
        "Otter",
        "Hyena"
    };
    
    int n=rand()%10; //The words appear will be random
    correctWord=words[n];
    string unknownWord(correctWord.length(), '_' ); //To replace the unkown words with _
    
    cout << "                       HANGMAN                     " << endl;
    cout << "                 By: Angeline Indahsi             " << endl;
    cout << "===================================================" << endl;
    cout << endl;
    cout << "Welcome to Hangman! Now try to guess the name of an animal!" << endl;
    cout << "Type start to start the game" << endl;
    cin >> start;
    
    while(numberOfWrongGuess < maxTries)
    {
        cout << "Guess the letter: " << endl;
        cout << unknownWord << endl;
        cin >> letter;
    }
    
    if (letterFill(letter, correctWord, unknownWord)==0)
    {
        cout << endl << "Sorry, wrong letter!" << endl;
        numberOfWrongGuess++;
    }
    else
    {
        cout << endl << "You found a letter! Keep it up!" << endl;
    }

    
    cout << "You have " << maxTries - numberOfWrongGuess << " guessess left!" << endl;
    //To count the number of chances left
    
    if (correctWord == unknownWord)
    {
        cout << correctWord << endl;
        cout << "Congratulations! You win the game!" << endl;
    }
    
    if (numberOfWrongGuess == maxTries)
    {
        cout << "You have been hanged!" << endl;
        cout << "Sorry you lose!" << endl;
        cout << "The word is: " << correctWord << endl;
    }
    cin.get();
    return 0;
}

int letterFill (char guess, string secretWord, string &wordGuessed)
{
    int i;
    int matched=0;
    int wordLength=secretWord.length();
    for (i = 0; i< wordLength; i++)
    {
        if (guess == wordGuessed[i])
            return 0;
        if (guess == secretWord[i])
        {
            wordGuessed[i] = guess;
            matched++;
        }
    }
    return matched;
}
