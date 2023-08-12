// SSBS1_rockpaperscissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<char> RPS{'r', 'p', 's'};
char userAction = '\0';
char pcAction = '\0';

char GetPcAction(std::vector<char> &vec) {
    int randomIndex = rand() % vec.size();
    return vec[randomIndex];
}

bool WinOrLose(char &user, char &pc) {
    if (user == 'r' && pc == 'p' || user == 's' && pc == 'r' || user == 'p' && pc == 's') {
        std::cout <<"\n" << pc << " beats " << user << "! You lost!";
        return false;
    }
    else if (user == 'r' && pc == 's' || user == 'p' || pc == 'r' || user == 's' && pc == 'p') {
        std::cout <<"\n" << user << " beats " << pc << "! You win!";
        return true;
    }
    else {
        std::cout << "\nIts a draw!\n";
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    std::cout << "\tWelcome to Rock, Paper, Scissors!\n";
    
    char playAgain = 'y';
    while (playAgain == 'y') {
    std::cout << "Chose your action to continue(r/p/s): ";
    std::cin >> userAction;

    pcAction = GetPcAction(RPS);
    std::cout << "\nPlayer action: " << userAction << "\nPC action: " << pcAction;
    WinOrLose(userAction, pcAction);
    std::cout << "\nWould you like to play again?('y'/'n'): ";
    std::cin >> playAgain;
    }

}
