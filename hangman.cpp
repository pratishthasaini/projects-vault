#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to choose a random word from a predefined list
string chooseRandomWord() {
    vector<string> wordList = {
                    "mango", "table", "apple", "brush", "chair",
                    "clock", "dance", "eagle", "fence", "glove",
                    "horse", "juice", "knife", "lemon", "mouse",
                    "night", "ocean", "paper", "queen", "radio",
                    "snake", "tiger", "uncle", "violin", "whale",
                    "yacht", "zebra", "amber", "bison", "coral",
                    "daisy", "ember", "fairy", "gnome", "happy",
                    "igloo", "joker", "kiosk", "mango", "learn",
                    "nymph", "olive", "panda", "quiet", "raven",
                    "skunk", "tango", "umbra", "vixen", "waltz",
                    "xerox", "yacht", "zesty", "apple", "blade",
                    "candy", "daisy", "eagle", "frost", "glove",
                    "honey", "igloo", "juicy", "kiwi", "lemon",
                    "mango", "nymph", "olive", "panda", "quiet",
                    "raven", "snake", "tango", "uncle", "velvet",
                    "whale", "xerox", "yacht", "zebra", "apple",
                    "blade", "candy", "daisy", "eagle", "frost",
                    "glove", "honey", "igloo", "juicy", "kiwi",
                    "lemon", "mango", "nymph", "olive", "panda",
                    "quiet", "raven", "snake", "tango", "uncle"
    };

    int randomIndex = rand() % wordList.size();
    return wordList[randomIndex];
}

// Function to display the current state of the word with guessed letters
void displayWord(const string& word, const vector<bool>& guessed) {
    for (int i = 0; i < word.length(); ++i) {
        if (guessed[i]) {
            cout << word[i];
        } else {
            cout << "_";
        }
    }
    cout << endl;
}

// Function to check if all letters have been guessed
bool allLettersGuessed(const vector<bool>& guessed) {
    for (bool letterGuessed : guessed) {
        if (!letterGuessed) {
            return false;
        }
    }
    return true;
}

int main() {
    srand(time(0)); // Seed the random number generator with current time

    string secretWord = chooseRandomWord();
    int maxAttempts = 6;
    vector<bool> guessedLetters(secretWord.length(), false);
    int incorrectGuesses = 0;

    cout << "Welcome to Hangman!" << endl;

    while (incorrectGuesses < maxAttempts) {
        cout << "Current word: ";
        displayWord(secretWord, guessedLetters);

        char guess;
        cout << "Guess a letter: ";
        cin >> guess;

        bool found = false;
        for (int i = 0; i < secretWord.length(); ++i) {
            if (secretWord[i] == guess) {
                guessedLetters[i] = true;
                found = true;
            }
        }

        if (!found) {
            ++incorrectGuesses;
            cout << "Incorrect guess. You have " << maxAttempts - incorrectGuesses << " attempts left." << endl;
        }

        // Check if all letters have been guessed
        if (allLettersGuessed(guessedLetters)) {
            cout << "Congratulations! You've guessed the word: " << secretWord << " right!" << endl;
            break;
        }
    }

    if (incorrectGuesses == maxAttempts) {
        cout << "You've run out of attempts. The word was: " << secretWord << endl;
    }

    cout << "Thanks for playing Hangman!" << endl;

    return 0;
}
