//Task 3: Create an integer array with 5 elements. 
// Write a program that calculates the square of each element in the array and 
// writes the results to a file named "squares.txt", with each result on a new line.
#include <iostream>
#include <fstream>
using namespace std;


int square(int x) {
    return x * x;
}

int main() {
    int arr[5] = { 3, 5, 9, 7, 10 };

    ofstream file("squares.txt");
    if (file.is_open()) {
        cout << "Squares of array elements:\n";
        for (int i = 0; i < 5; i++) {
            int sq = square(arr[i]);
            cout << arr[i] << "^2 = " << sq << endl;
            file << sq << endl;
        }
        file.close();
        cout << "Data successfully written to squares.txt" << endl;
    }
    else {
        cout << "Error: Unable to open file." << endl;
    }

    return 0;
}
