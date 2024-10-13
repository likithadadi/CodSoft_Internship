//CPP program for generating random number
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    cout << "====================== Number Guessing Game ========================\n\n";
    int userNum;

    // To generate random number
    srand(time(0));
    int randomNo = 1 + (rand() % 100);
    cout << "You have 5 chances to guess the correct number\n";
    int chances = 5;

    while (chances>0) {
        cout << "Enter the number to guess between 1 to 100: ";
        cin >> userNum;

        if (userNum < randomNo) {
            cout << "\nThe number you guessed is lower than the actual number.\nBetter luck! Next time.\n";
        } 
        else if (userNum > randomNo) {
            cout << "\nThe number you guessed is higher than the actual number.\nTry again to get it correct!!\n";
        } 
        else {
            cout << "\nWell played!!! You guessed the correct number\n";
            break;
        }

        chances--;  
        cout << "The number of chances left is: " << chances << "\n";
    }

    if (chances == 0) {
        cout << "Your chances are over, try playing again.\n";
        cout << "The random number generated was: " << randomNo << "\n";
    }

    return 0;
}
