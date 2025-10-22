#include <iostream>
#include <fstream>

#pragma region task 1 


//Task 1 : Create a program that asks the user for a filename. 
// The program should then create a file with that name and 
// write the text "Hello, World!" into it.


//#include <iostream>
//#include <fstream>
//int main() {
//	std::ofstream file("sample.txt");
//	if (file.is_open()) {
//		file << "Hello, World!" << std::endl;
//		file << "This is the second line." << std::endl;
//		file.close();
//		std::cout << "File created and written successfully." << std::endl;
//	}
//	else {
//		std::cout << "Error: Unable to create file." << std::endl;
//	}
//	return 0;
//}
#pragma endregion 


//Task 1 Example:Kullanıcıdan ad alınıp dosyaya yazdırma 
/*
#include <string>
using namespace std;
int main() {
	string name;
	ofstream file("user_data.txt", ios::app);
	cout << "Enter your name: " << endl;
	getline(cin, name);
	file << name << '\n';
	return 0;
}*/ 
//Task 1 Example: 
/*
#include <string>
using namespace std;

int main() {
	string text;
	cout << "Dosyaya yazılacak metni girin: ";
	getline(cin, text);

	ofstream file("task1.txt"); // Yeni dosya oluştur
	if (file.is_open()) {
		file << text << endl;
		file.close();
		cout << "Metin başarıyla dosyaya yazıldı!" << endl;
	}
	else {
		cout << "Dosya oluşturulamadı!" << endl;
	}
	return 0;
}
*/

//Task 2
/*
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {
	ifstream file("sample.txt");
	string line;

	if (file.is_open()) {
		while (getline(file, line)) {
			cout << line << endl;
		}
		file.close();
	}
	else {
		cout << "Error: Unable to open file." << endl;
	}
	return 0;
}*/
//Task 2 Example:
/*
#include <string>
using namespace std;

void readFile(const string& filename) {
	ifstream file(filename);
	string line;

	if (file.is_open()) {
		cout << "📂 " << filename << " içeriği:\n";
		while (getline(file, line)) {
			cout << line << endl;
		}
		file.close();
	}
	else {
		cout << "Dosya açılamadı!" << endl;
	}
}

int main() {
	readFile("task1.txt");
	return 0;
}
*/

//Task 3
/*
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream file("sample.txt", ios::app);
	if (file.is_open()) {
		file << "This is an appended line." << endl;
		file.close();
		cout << "Data successfully appended to the file." << endl;
	}
	else {
		cout << "Error: Unable to open file." << endl;
	}
	return 0;
}
*/
//Task 3 Example: 
/*
#include <string>
using namespace std;

void appendToFile(const string& filename) {
	ofstream file(filename, ios::app);
	string newLine;

	if (file.is_open()) {
		cout << "Dosyaya eklenecek satırı girin: ";
		getline(cin, newLine);
		file << newLine << endl;
		file.close();
		cout << "Yeni satır eklendi!" << endl;
	}
	else {
		cout << "Dosya bulunamadı veya açılamadı!" << endl;
	}
}

int main() {
	appendToFile("task1.txt");
	return 0;
}
*/
//Task 4 sor :
/*

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string text = "Hello";
	ofstream file("chars.txt");

	if (file.is_open()) {
		for (char c : text) {
			file.put(c);
		}
		file.close();
		cout << "Characters successfully written to the file." << endl;
	}
	else {
		cout << "Error: Unable to open file for writing." << endl;
	}

	return 0;
}*/ 
//Task 4 Example: 
/*
#include <string>
using namespace std;

void writeChars(const string& filename, const string& text) {
	ofstream file(filename);
	if (file.is_open()) {
		for (char c : text)
			file.put(c);
		file.close();
		cout << "Karakterler dosyaya yazildi.\n";
	}
}

void readChars(const string& filename) {
	ifstream file(filename);
	char ch;
	cout << "Dosya icerigi: ";
	if (file.is_open()) {
		while (file.get(ch))
			cout << ch;
		file.close();
		cout << endl;
	}
}

int main() {
	string input;
	cout << "Bir kelime girin: ";
	getline(cin, input);

	writeChars("task4.txt", input);
	readChars("task4.txt");

	return 0;
}
*/

//Task 5
/*
#include <iostream>
#include <fstream>
using namespace std;
int main() {
	char ch;
	ifstream file("chars.txt");
	if (file.is_open()) {
		cout << "Reading characters from file: ";
		while (file.get(ch)) {
			cout << ch;
		}
		cout << endl;
		file.close();
	}
	else {
		cout << "Error: Unable to open file for reading." << endl;
	}
	return 0;
}*/
//Task 5 Example:
/*
#include <string>
using namespace std;

void writeNew(const string& filename) {
	string text;
	cout << "Yeni icerik girin (önceki silinir): ";
	getline(cin, text);
	ofstream f(filename);
	f << text << endl;
	f.close();
}

void appendLine(const string& filename) {
	string text;
	cout << "Eklenecek satir: ";
	getline(cin, text);
	ofstream f(filename, ios::app);
	f << text << endl;
	f.close();
}

void readFile(const string& filename) {
	ifstream f(filename);
	string line;
	cout << "\n Dosya icerigi:\n";
	while (getline(f, line))
		cout << line << endl;
	f.close();
}

int main() {
	string filename = "task5.txt";
	int choice;

	do {
		cout << "\n1- Dosyaya yeni veri yaz\n"
			"2- Dosyaya satir ekle\n"
			"3- Dosyayi oku\n"
			"0- Exit\n"
			"Seciminiz: ";
		cin >> choice;
		cin.ignore();

		if (choice == 1) writeNew(filename);
		else if (choice == 2) appendLine(filename);
		else if (choice == 3) readFile(filename);
		else if (choice != 0) cout << "Gecersiz secim!\n";

	} while (choice != 0);

	cout << "Program sonlandirildi.\n";
	return 0;
}
*/

//TASKLAR ÖRNEK:
//1
/*
#include <string>

using namespace std;

// ➤ Kullanıcıdan bilgi alır
void getUserData(string& name, int& age) {
	cout << "Adınızı girin: ";
	getline(cin, name);
	cout << "Yaşınızı girin: ";
	cin >> age;
	cin.ignore(); // input buffer'daki \n karakterini temizler
}

// ➤ Bilgiyi dosyaya kaydeder (append)
void writeToFile(const string& filename, const string& name, int age) {
	ofstream file(filename, ios::app); // ios::app → ekleme modu
	if (file.is_open()) {
		file << name << " - " << age << endl;
		file.close();
		cout << "Veri dosyaya eklendi.\n";
	}
	else {
		cout << "Dosya açılamadı!\n";
	}
}

// ➤ Dosyayı okur ve ekrana basar
void readFromFile(const string& filename) {
	ifstream file(filename);
	string line;
	cout << "\n📂 Dosya içeriği:\n";
	if (file.is_open()) {
		while (getline(file, line)) {
			cout << line << endl;
		}
		file.close();
	}
	else {
		cout << "Dosya okunamıyor!\n";
	}
}

int main() {
	string name;
	int age;

	getUserData(name, age);
	writeToFile("data.txt", name, age);
	readFromFile("data.txt");

	return 0;
}
*/
//2
/*
#include <string>
using namespace std;

void addGrade(const string& filename) {
	string name;
	double grade;

	cout << "Öğrenci adı: ";
	getline(cin, name);
	cout << "Notu: ";
	cin >> grade;
	cin.ignore();

	ofstream file(filename, ios::app);
	if (file.is_open()) {
		file << name << " " << grade << endl;
		cout << "Not kaydedildi.\n";
		file.close();
	}
	else {
		cout << "Dosya yazma hatası!\n";
	}
}

void listGrades(const string& filename) {
	ifstream file(filename);
	string name;
	double grade;
	cout << "\n📜 Kayıtlı öğrenciler:\n";
	if (file.is_open()) {
		while (file >> name >> grade) {
			cout << name << " - " << grade << endl;
		}
		file.close();
	}
	else {
		cout << "Dosya okunamıyor!\n";
	}
}

void calcAverage(const string& filename) {
	ifstream file(filename);
	string name;
	double grade, sum = 0;
	int count = 0;

	if (file.is_open()) {
		while (file >> name >> grade) {
			sum += grade;
			count++;
		}
		file.close();

		if (count > 0)
			cout << "\n📈 Ortalama not: " << (sum / count) << endl;
		else
			cout << "Henüz kayıt yok.\n";
	}
	else {
		cout << "Dosya açılamadı!\n";
	}
}

int main() {
	string filename = "grades.txt";
	int choice;

	do {
		cout << "\n1- Not ekle\n2- Listele\n3- Ortalama hesapla\n0- Çıkış\nSeçiminiz: ";
		cin >> choice;
		cin.ignore(); // Enter karakterini temizle

		switch (choice) {
		case 1: addGrade(filename); break;
		case 2: listGrades(filename); break;
		case 3: calcAverage(filename); break;
		case 0: cout << "Çıkış yapılıyor...\n"; break;
		default: cout << "Geçersiz seçim!\n"; break;
		}
	} while (choice != 0);

	return 0;
}
*/
