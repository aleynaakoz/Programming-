//Task 5: Write a program that reads the content from the "sample.txt" file character by character using the get() function and counts the total number of characters.The program should then display the total count in the console
#include <string>  
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    char sp;
    int count = 0;
    ifstream file("sample.txt");

    if (file.is_open()) {
        cout << "Reading characters from file: ";

        while (file.get(sp)) {
            cout << sp;
            count++;
        }
        cout << "\nTotal number of characters: " << count << endl;
        file.close();
    }
    else {
        cout << "Error: Unable to open file for reading." << endl;
    }

    return 0;
}