//
// Created by MiaKim on 31/07/2025.
//
#include <iostream>

using namespace std;

//1.longer than 5 characters
//2. contains the @ symbol
//3. Contains a dot "."
// class should return a boolean for success or failure

class EmailValidator {
private:
    string email{};
public:
    //constructor
    EmailValidator(string userEmail) {
        email = userEmail;
    }

    bool isValid() {
        return email.length() > 5 && email.find('@')!=string::npos && email.find('.')!=string::npos;
    }
};


int main() {
string userEmail = "rachel@gmail.com";

EmailValidator checkEmail(userEmail);
if (checkEmail.isValid()) {
    cout << "sweet..." << endl;
}else {
    cout << "try again sucker!" << endl;
}

}