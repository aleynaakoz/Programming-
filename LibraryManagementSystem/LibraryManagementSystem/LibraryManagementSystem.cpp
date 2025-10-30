#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>

using namespace std;

	class Book {
			private:
				int bookId;
				string bookTitle;
				string author;
				bool isBorrowed;

			public:
				Book() {
					bookId = 0;
					bookTitle = " ";
					author = " ";
					isBorrowed = false;
						}

	void setBookDetails(int id, string title, string authorName, bool status) {
					bookId = id;
					bookTitle = title;
					author = authorName;
					isBorrowed = status;
						}

	void display() {
			cout << "--------------------Information of Book: ------------------" << endl;
			cout << "ID: " << bookId << " | Title: " << bookTitle << " | Author: " << author<< " [" << (isBorrowed ? "Borrowed" : "Available") << "]" << endl;
						}

	void borrowBook() { 
		isBorrowed = true;
	}

	void returnBook() { 
		isBorrowed = false; 
	}

	bool isAvailable() {
		return !isBorrowed;
	}

	int getID() { 
		return bookId;
	}

	string getSaveFormat() {
		return to_string(bookId) + "," + bookTitle + "," + author + "," + (isBorrowed ? "1" : "0");
	}
};

	class Library {
			private:
					Book bookCatalog[50];
					int bookCount;
					string bookFileName;

			public:
				    Library(string filename) {
					bookFileName = filename;
					bookCount = 0;
					loadBooksFromFile();
				}

	void loadBooksFromFile() {
			ifstream file(bookFileName);
					if (!file) {
						cout << "Error: Could not open file " << bookFileName << endl;
								return;
					}

					string line;
					while (getline(file, line)) {
					stringstream sstr(line);
					string idStr, titleStr, authorStr, statusStr;
					getline(sstr, idStr, ',');
					getline(sstr, titleStr, ',');
					getline(sstr, authorStr, ',');
					getline(sstr, statusStr, ',');

					int bookId = stoi(idStr); // stringi inte çeviriyoruz burada
					bool status = (statusStr == "1");
					bookCatalog[bookCount].setBookDetails(bookId, titleStr, authorStr, status);
					bookCount++;
				}
			file.close();
	}

	void saveBooksFromFile() {
			 ofstream file(bookFileName);
					if (!file) {
						cout << "Error: Could not open file " << bookFileName << endl;
								return;
					}

						for (int i = 0; i < bookCount; i++) {
							file << bookCatalog[i].getSaveFormat() << endl; 
					}

			file.close();
					}

	void listAllBooks() {
				cout << "-------------------Books-------------------" << endl;
						for (int i = 0; i < bookCount; i++) {
								bookCatalog[i].display();
							}
				cout << "-------------------------------------------" << endl;
						}

	void borrowBook(int bookId) {
						for (int i = 0; i < bookCount; i++) {
							if (bookCatalog[i].getID() == bookId) {
								if (bookCatalog[i].isAvailable()) {
									bookCatalog[i].borrowBook();
										cout << "Book borrowed successfully!" << endl;
									}
								else {
										cout << "Error: Book is already borrowed" << endl;
									}
									return; 
								}
							}
							cout << "Book not found!" << endl;
						}

	void returnBook(int bookId) {
						for (int i = 0; i < bookCount; i++) {
							if (bookCatalog[i].getID() == bookId) {
								if (!bookCatalog[i].isAvailable()) {
										bookCatalog[i].returnBook();
										cout << "Book returned successfully!" << endl;
								}
								else {
										cout << "Error: Book is already available" << endl;
									}
									return;
								}
							}
							cout << "Book not found!" << endl;
						}
					};

	int main() {
			Library myLibrary("books.txt");

			int choiceCase;
				do {
					cout << "---------------------Library Management System---------------------" << endl;
					cout << "1. List All Books" << endl;
					cout << "2. Borrow a Book" << endl;
					cout << "3. Return a Book" << endl;
					cout << "4. Save and Exit" << endl;
					cout << "Enter your choice: ";
					cin >> choiceCase;

					switch (choiceCase) {
						case 1: {
							myLibrary.listAllBooks();
								break;
						}
						case 2: {
							int id;
							cout << "Enter book ID to borrow: ";
							cin >> id;
							myLibrary.borrowBook(id);
								break;
							}
						case 3: {
							int id;
							cout << "Enter book ID to return: ";
							cin >> id;
							myLibrary.returnBook(id);
								break;
							}
						case 4: {
							myLibrary.saveBooksFromFile();
							cout << "Saving changes... Goodbye!" << endl;
								break;
							}
						default: {
								cout << "Invalid choice! Please try again." << endl;
							}
						}
					} while (choiceCase != 4);

						return 0;
					}

					