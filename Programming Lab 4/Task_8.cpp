//Task 8: Develop a program that reads numerical data from a file named "numbers.txt"(assuming one number per line),
// calculates the average of these numbers, and writes the final average to a new file named "average.txt".
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    int numbers[6] = { 4, 24, 6, 87, 90, 41 };

    ofstream numFile("numbers.txt");
    if (numFile.is_open()) {
        for (int i = 0; i < 6; i++) {
            numFile << numbers[i] << endl;
        }
        numFile.close();
        cout << "numbers.txt olusturuldu ve sayilar yazildi." << endl;
    }
    else {
        cout << "numbers.txt olusturulamadi!" << endl;
        return 1;
    }

    ifstream input("numbers.txt");
    if (!input.is_open()) {
        cout << "numbers.txt acilamadi!" << endl;
        return 1;
    }

    int count = 0;
    int num;
    int sum = 0;


    while (input >> num) {
        sum += num;
        count++;
    }
    input.close();

    float average = (count > 0) ? (sum / count) : 0;

    cout << "Ortalama: " << average << endl;

    ofstream avgFile("average.txt");
    if (avgFile.is_open()) {
        avgFile << average << endl;
        avgFile.close();
        cout << "average.txt dosyasina ortalama yazildi." << endl;
    }
    else {
        cout << "average.txt olusturulamadi!" << endl;
    }

    return 0;
}