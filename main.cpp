#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

string getWord () {
    ifstream file ("words.txt");
    srand(time(0));
    string line;
    vector<string> lines;
    int count = 0;
    while (getline(file, line)) {
        count++;
        lines.push_back(line);
    }
    int random = rand()% count;
    return lines[random];
}


void checkLength (string guess) {
    while (guess.length() != 5) {
        if (guess.length() > 5 || guess.length() < 5) {
            cout << "Error. Enter a 5-letter word." << endl;
            cin >> guess;
        }
    }
}


void checkGuess (string correctWord, string guess) {
    char c[5];
    char g[5];
    char letter;
    vector<char> yellow;
    vector<char> green;
        for (int i = 0; i < 5; i++) {
            c[i] = correctWord[i];
            g[i] = guess[i];
                if (g[i] == c[i]) {
                    green.push_back (g[i]);
                }
                else {
                    green.push_back ('?');
                }
                letter = correctWord.find(g[i]);
                if (g[i] == correctWord[letter]) {
                    yellow.push_back (g[i]);
                }
        }
        for (char f: green) {
            cout << f;
        }
        cout << endl;
        if (!yellow.empty()) {
            cout << "\n(letters in the word: ";
            for (char i: yellow) {
                cout << i << " ";
            }   
            cout << ")" << endl;
        }
}
int main() {
    string correctWord = getWord();
    string guess;
    int numGuesses = 5;
    cout << correctWord << endl;
    cout << "--------------Welcome to Wordle-----------------\n";
    cout << "---You Have 5 Tries to Guess the Correct Word---\n\n";
    cout << "\tEnter a 5-letter word to begin.\n";
    cin >> guess;
    while (numGuesses > 0){
        checkLength (guess);
        checkGuess (correctWord, guess);
        if (correctWord == guess) {
            cout << "\tCorrect!"<< endl;
            break;
        }
        cout << endl;
        cout << numGuesses << " guesses remaining" << endl;
        cin >> guess;
        numGuesses--;
    }
    if (numGuesses == 0) {
        cout << "\tGame over!\n\n";
        cout << "\the word was: " << correctWord << endl;
    }
   
    return 0;
}





