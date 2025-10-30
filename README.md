# Programming-

# 📚 Library Management System (C++)

This project implements a simple **Library Management System** in C++ that allows users to **view**, **borrow**, and **return books**, with data persistence handled through a text file (`books.txt`).  
It showcases fundamental **object-oriented programming (OOP)** principles, **file I/O operations**, and **menu-driven user interaction** in a console environment.

---

## 🧩 Project Overview

The system models a basic library where each book can be borrowed or returned.  
Book details are stored in a text file, and all changes (borrowing or returning) are saved upon exit.

Core functionalities include:
- Listing all books  
- Borrowing a book  
- Returning a book  
- Saving updates to the file  

---

## 🧱 Class Structure

### 🧾 `Book` Class
Represents an individual book and its properties.

| Attribute | Type | Description |
|------------|------|-------------|
| `bookId` | `int` | Unique identifier for each book |
| `bookTitle` | `string` | Title of the book |
| `author` | `string` | Author’s name |
| `isBorrowed` | `bool` | Borrow status (`true` = borrowed) |

**Key Methods**
- `setBookDetails(id, title, authorName, status)` — sets book data  
- `display()` — prints book information to console  
- `borrowBook()` — marks the book as borrowed  
- `returnBook()` — marks the book as available  
- `isAvailable()` — checks if the book can be borrowed  
- `getSaveFormat()` — returns CSV format for file saving  

---

### 🏛️ `Library` Class
Manages the book catalog and performs operations on it.

| Attribute | Type | Description |
|------------|------|-------------|
| `bookCatalog[50]` | `Book` | Array holding all book objects |
| `bookCount` | `int` | Number of books in the system |
| `bookFileName` | `string` | Name of the text file storing books |

**Key Methods**
- `loadBooksFromFile()` — loads books from `books.txt`  
- `saveBooksFromFile()` — saves all books back to file  
- `listAllBooks()` — displays all book records  
- `borrowBook(int id)` — borrows a book if available  
- `returnBook(int id)` — returns a borrowed book  

---

## 📂 File Format

All books are stored in a CSV-style text file named `books.txt`:

1,The Great Gatsby,F. Scott Fitzgerald,0
2,To Kill a Mockingbird,Harper Lee,1
3,1984,George Orwell,0
🖥️ Program Menu

When the program starts, it loads all book data and shows this menu:

---------------------Library Management System---------------------
1. List All Books
2. Borrow a Book
3. Return a Book
4. Save and Exit
Enter your choice:

Example Flow:
1
-------------------Books-------------------
ID: 1 | Title: The Great Gatsby | Author: F. Scott Fitzgerald [Available]
ID: 2 | Title: To Kill a Mockingbird | Author: Harper Lee [Borrowed]
-------------------------------------------

2
Enter book ID to borrow: 1
Book borrowed successfully!

⚙️ How to Compile and Run
🪟 On Windows (using g++)
g++ main.cpp -o library.exe
library.exe

🐧 On Linux / macOS
g++ main.cpp -o library
./library


Make sure a books.txt file exists in the same directory as the executable.

🧠 Key Learning Outcomes

Mastering file input/output (I/O) in C++

Applying object-oriented programming (encapsulation, classes, methods)

Implementing data persistence using text files

Handling menu-driven console applications

Understanding how to serialize/deserialize objects manually

🪶 Author

Aleyna Aköz
🎓 Sivas Bilim ve Teknoloji Üniversitesi
✈️ Uçak Mühendisliği • Object-Oriented Programming Project

📅 October 2025

📜 License

This project is open for educational and academic use under the License.
License © 2025 Aleyna Aköz
