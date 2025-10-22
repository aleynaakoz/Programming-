//Task 6: Create a program that copies the content of a file named "source.txt" to a new file named
// "destination.txt" already exists, its content should be overwritten.

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {

    ofstream file("source.txt");
    if (file.is_open()) {
        file << "Bu dosyadaki her seyi kopyaladýn!!" << endl;
        file.close();
        cout << "File created and written successfully." << endl;
    }
    else {
        cout << "Error: Unable to create file." << endl;
    }


    ifstream input("source.txt");
    if (!input.is_open()) {
        cout << "Error! File could not open!" << endl;
        }
    ofstream output("destination.txt");
    if (!output.is_open()) {
        cout << "Error! destination.txt can not created!" << endl;
    }
    string linebyline;
    while (getline(input, linebyline)) {
        output << linebyline << endl;
    }
    cout << "File copied successfully!" << endl;

    input.close();
    output.close();

    return 0;
}
