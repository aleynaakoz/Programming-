//Task 7: Write a function that accepts a filename and a string as arguments. //C++ map sample yaz google a ona göre bak 
// The function should open the specifiedfile and search for all occurences of the given string, 
// then print the number of times the string as found to the console.

#include <map>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void count(string fileName, string searchWord) {
    ifstream file(fileName);
    map<string, int> wordCount;
    string word;

    while (file >> word) {
        wordCount[word]++;
    }

    cout << searchWord << " kelimesi dosyada " << wordCount[searchWord] << " kez bulundu." << endl;
}

int main() {
    count("destination.txt", "Aleyna");
    return 0;
}
