/*
Title: Chapter 6 Ex 24 - Rock Paper Scissors
File Name: Chapter6_Ex24_Cody_Drumheller
Programmer: Cody Drumheller
Date:20241207
Requirements:
Write a program that lets the user play the game of Rock, Paper, Scissors against the computer. The program should work as follows:
1. When the program begins, a random number in the range of 1 through 3 is generated. If the number is 1, then the computer has chosen rock. 
If the number is 2, then the computer has chosen paper. 
If the number is 3, then the computer has chosen scissors. (Don’t display the computer’s choice yet.)
2. The user enters his or her choice of “rock”, “paper”, or “scissors” at the keyboard. (You can use a menu if you prefer.)
3. The computer’s choice is displayed.
*/

#include <iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;


int getComputerChoice();
int getUserChoice();
void displayChoice(int choice);
void determineWinner(int userChoice, int computerChoice);

int main() {
    srand(static_cast<unsigned>(time(0))); 

    int computerChoice, userChoice;

    do {
        computerChoice = getComputerChoice(); 
        userChoice = getUserChoice();  

        cout << "Computer chose: ";
        displayChoice(computerChoice);
        cout << "You chose: ";
        displayChoice(userChoice);

        determineWinner(userChoice, computerChoice);

    } while (userChoice == computerChoice); 

    return 0;
}

int getComputerChoice() {
    return rand() % 3 + 1; 
}

int getUserChoice() {
    int choice;
    cout << "Enter your choice:\n";
    cout << "1. Rock\n2. Paper\n3. Scissors\n";
    cout << "Your choice: ";
    cin >> choice;

    while (choice < 1 || choice > 3) {
        cout << "Invalid choice. Please enter 1 (Rock), 2 (Paper), or 3 (Scissors): ";
        cin >> choice;
    }

    return choice;
}

void displayChoice(int choice) {
    switch (choice) {
    case 1:
        cout << "Rock\n";
        break;
    case 2:
        cout << "Paper\n";
        break;
    case 3:
        cout << "Scissors\n";
        break;
    }
}

void determineWinner(int userChoice, int computerChoice) {
    if (userChoice == computerChoice) {
        cout << "It's a tie! Play again.\n";
    }
    else if ((userChoice == 1 && computerChoice == 3) || 
        (userChoice == 3 && computerChoice == 2) || 
        (userChoice == 2 && computerChoice == 1)) { 
        cout << "You win!\n";
    }
    else {
        cout << "Computer wins!\n";
    }
}











