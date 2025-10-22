//Task 2: Write a function that takes the width and height of a rectangle as user input.
// The function should calculate the area of the rectangle,create a file named "rectangle_area.txt",
// and write the calculated arae into the file.

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int rectangleArea(int width, int height) {
    return width * height;
}

int main() {
    int width, height;

    cout << "Enter the width: ";
    cin >> width;
    cout << "Enter the height: ";
    cin >> height;

    int area = rectangleArea(width, height);

    ofstream file("rectangle_area.txt");
    if (file.is_open()) {
        file << "Rectangle Area: " << area << endl;
        file.close();
        cout << "File created and written successfully.\n";
        cout << "Area = " << area << endl;
    }
    else {
        cout << "Error: Unable to create file." << endl;
    }

    return 0;
}