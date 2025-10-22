
//Task 1: Create a program that asks the user for a filename.
// The program should then create a file with that name and write the text "Hello, World!" into it.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string filename;
	cout << "Enter your filename: ";
	getline(cin, filename);

	ofstream file(filename, ios::app);
	if (file.is_open()) {
		file << "Hello, World!" << endl;
		file.close();
		cout << "File created and written successfully." << endl;
	} else {
		cout << "Error: Unable to create file." << endl;
	}

	return 0;
}