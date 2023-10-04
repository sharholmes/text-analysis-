//
//  main.cpp
//  project 2
//
//  Created by Sharlotte Holmes on 9/28/23.
//

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

void PrintMenu () {
    cout << "MENU\n";
    cout << "c - Number of non-whitespace characters" << endl;
    cout << "w - Number of words" << endl;
    cout << "f - Find text" << endl;
    cout << "r - Replace all !'s" << endl;
    cout << "s - Shorten spaces" << endl;
    cout << "q - Quit"<< endl;
}

int GetNumOfNonWSCharacters (const string& text) {
    int count = 0;
    for (char c : text) {
        if(!isspace(c)) {
            count++;
        }
    }
    return count;
}

int GetNumOfWords(string& text) {
    istringstream iss(text);
    int count = 0;
    string word;
    
    while(iss >> word) {
        count++;
    }
    return count;
}

int FindText(const string& text, const string& userInput) {
    int count = 0;
    size_t position = 0;
    while((position = userInput.find(text, position)) != string::npos) {
        count ++;
        position += text.length();
    }
    return count;
}


void ReplaceExclamation(string& text){
    for(char& c : text) {
        if (c== '!') {
            c = '.';
        }
    }
}

void ShortenSpace(string& text) {
    text.erase(unique(text.begin(), text.end(),
                     [](char a, char b) { return a == ' ' && b == ' '; }), text.end());
}

void ExecuteMenu (char menuchoise, string& userInput) {
    switch(menuchoise) {
        case 'c':
            cout << "Number of non-whitespace characters: " <<GetNumOfNonWSCharacters(userInput) << endl;
            break;
            
        case 'w':
            cout <<"Number of words: "<< GetNumOfWords(userInput) << endl;
            break;
            
        case 'f': {
            string text;
            cin.ignore();
            cout <<"Enter a word or phrase to be found:" << endl;
            getline(cin, text);
            int instances = FindText(text, userInput);
            cout<< "\""<< text<< "\" instances: "<< instances<< endl;
        }
            break;
            
        case 'r':
            ReplaceExclamation(userInput);
            cout<< "Edited text: "<< userInput << endl;
            break;
            
        case 's':
            ShortenSpace(userInput);
            cout << "Edited text: "<< userInput << endl;
            break;
    }
}

int main() {
    string userInput;

    cout << "Enter a sample text:\n"<< endl;
    getline(cin, userInput);
    cout << "You entered: " << userInput << endl;
    
    char menuChoise;
    do {
        cout << endl;
        PrintMenu();
        cout << endl << "Choose an option:"<< endl;
        cin >> menuChoise;
        
        ExecuteMenu(menuChoise, userInput);
    } while (menuChoise !='q');
    
    return 0;
}
