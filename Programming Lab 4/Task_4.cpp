//Task 4: Develop a program that asks the user for their first name and last name. 
// The prgram should then append this information to a file called "names.log".
// Each new entry(file name and last name) should be on a new line .

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

string userInfo(string lastName, string firstName) {
    cout << "Please enter the lastName" << endl;
    cin >> lastName;
    cout << "Please enter the firstName" << endl;
    cin >> firstName;
    return firstName + " " + lastName;
}


int main(){
    string ln, fn;
    string fullName = userInfo(ln,fn);
    ofstream file("names.log",ios::app);
    if (file.is_open()) {
        file << fullName << endl;
        file.close();
        cout << "Name successfully appended to names.log." << endl;
    }
    else {
        cout << "Error: Unable to open file." << endl;
    }

    return 0;
}
