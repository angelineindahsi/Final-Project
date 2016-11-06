//  main.cpp
//  Hangman
//
//  Created by Angeline Indahsi on 10/13/16.
//  Copyright © 2016 Angeline Indahsi. All rights reserved.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> //Using csdtdlib and ctime so that the words will always be randomized
using namespace std;


int letterFill (char wordGuess, string unknownWord, string &guessword); // The function that will be used after the main function

int main()
{
    string start;
    const int numberOfTries = 6; // The maximum number of tries
    char letter;
    int wrongLetter;
    int remainingTries;
    string guessWord;
    //The words that the player needs to guess was inside the array
    string wordArr[23] =
    {
        "alpaca",
        "butterfly",
        "crocodile",
        "crow",
        "gazelle",
        "hamster",
        "lizard",
        "hippopotamus",
        "kangaroo",
        "leopard",
        "mongoose",
        "tiger",
        "lion",
        "cheetah",
        "panther",
        "mouse",
        "armadillo",
        "rhinoceros",
        "giraffe",
        "sloth",
        "otter",
        "hyena"
    };
    
    //To randomize the words that the player needs to guess
    srand(time(0));
    int n=rand()% 23;
    guessWord=wordArr[n];
    
    //The letters will be replaced with _
    string unknownWord(guessWord.length(),'_');
    
    
    cout << "                       HANGMAN                     " << endl;
    cout << "                 By: Angeline Indahsi             " << endl;
    cout << "===================================================" << endl;
    cout << endl;
    cout << "Welcome to Hangman! Now try to guess the name of an animal!" << endl;
    cout << "You have 6 chances to guess the word. If you have reached 0 chances, you lose!" <<endl;
    cout << "Press any key then press enter to start the game!" << endl;
    cin >> start;
    
    cout << "Guess the name of the animal by entering the letter! Good luck & have fun!" << endl;
    
    while (wrongLetter < numberOfTries) //Loop until the player win or lose
    {
        cout << unknownWord << endl; //The unknown word represented with underscores will be shown
        cout << "Enter a letter: ";
        cin >> letter; //So that the player can input a letter
        
        if (letterFill(letter, guessWord, unknownWord)==0) //If the letter guessed is wrong
        {
            cout << endl << "Sorry, wrong letter!" << endl;
            wrongLetter++;
        }
        else
        {
            cout << endl << "Yay you found a letter! Keep it up!" << endl;
        }
        
        // Remind the user of the remaining chances left before losing
        remainingTries = numberOfTries - wrongLetter;
        cout << "You have " << remainingTries << " guesses left." << endl;
        
        if (guessWord==unknownWord) //If the player had guessed all of the word right
        {
            cout << guessWord << endl;
            cout << "Congratulations, you won!" << endl;
            cout << "Thank you for playing hangman!" << endl;
        }
    }
    if(wrongLetter == numberOfTries) //If there's no chances left
    {
        cout << "You have been hanged! You lose..." << endl;
        cout << "The word was : " << guessWord << endl;
        cout << "Thank you for playing hangman!" << endl;
    }
    cin.get();
    cin.ignore();
    return 0;
}

//This function is to determine whether the letter that the player had input is the same or not
int letterFill (char wordGuess, string unknownWord, string &guessword)
{
    int i;
    int matched=0;
    int length=unknownWord.length();
    for (i = 0; i< length; i++)
    {
        if (wordGuess == guessword[i])
            return 0;
        if (wordGuess == unknownWord[i])
        {
            guessword[i] = wordGuess;
            matched++;
        }
    }
    return matched;
}
