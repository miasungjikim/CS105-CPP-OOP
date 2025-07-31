//
// Created by MiaKim on 31/07/2025.
//
// Haven't made .h file yet . 
#include <iostream>
#include <set>
using namespace std;

class Pangram {
private:
    string letter;
public:
    //constructor
    Pangram(string l) {
        letter = l;
    }

    int letter_count() {
        set<char>alphabet;
        for (char c:letter) {
            if (isalpha(c)) {
                alphabet.insert(tolower(c));
            }
        }
        return alphabet.size();
    }

    bool is_pangram() {
        return letter_count() == 26;
    }

    void reason() {
        set<char>alphabet;
        for (char c: letter) {
            if (isalpha(c)) {
                alphabet.insert(tolower(c));
            }
        }
        cout << "Missing letters: ";
        for (char c = 'a'; c<='z'; c++) {
            if (alphabet.find(c)==alphabet.end()) {
                cout << c << " ";
            }
        }
        cout << endl;
    }


};


int main() {
    Pangram p("Two driven jocks help fax my big quiz");

    if (p.is_pangram()) {
        cout << "This sentence is a pangram!" << endl;
    } else {
        cout << "This sentence is NOT a pangram." << endl;
        p.reason();
    }


    return 0;
}




