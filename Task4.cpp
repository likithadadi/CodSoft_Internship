#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100;

struct Book {
    int id;
    string title;
    string author;
    bool isIssued;
};

void addBook(Book books[], int &bookCount) {
    if (bookCount < MAX_BOOKS) {
        cout << "Enter Book ID: ";
        cin >> books[bookCount].id;
        cin.ignore(); 
        cout << "Enter Book Title: ";
        getline(cin, books[bookCount].title);
        cout << "Enter Author Name: ";
        getline(cin, books[bookCount].author);
        books[bookCount].isIssued = false;
        bookCount++;
        cout << "Book added successfully!" << endl;
    } else {
        cout << "Library is full!" << endl;
    }
}

void issueBook(Book books[], int bookCount) {
    int id;
    cout << "Enter Book ID to issue: ";
    cin >> id;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            if (!books[i].isIssued) {
                books[i].isIssued = true;
                cout << "Book issued successfully!" << endl;
            } else {
                cout << "Book is already issued!" << endl;
            }
            return;
        }
    }
    cout << "Book not found!" << endl;
}

void returnBook(Book books[], int bookCount) {
    int id;
    cout << "Enter Book ID to return: ";
    cin >> id;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            if (books[i].isIssued) {
                books[i].isIssued = false;
                cout << "Book returned successfully!" << endl;
            } else {
                cout << "This book wasn't issued!" << endl;
            }
            return;
        }
    }
    cout << "Book not found!" << endl;
}

void displayBooks(Book books[], int bookCount) {
    cout << "Books in Library:" << endl;
    for (int i = 0; i < bookCount; i++) {
        cout << " ID: " << books[i].id<<"\n" 
             << " Title: " << books[i].title <<"\n"
             << " Author: " << books[i].author<<"\n" 
             << " Issued: " << (books[i].isIssued ? "Yes" : "No") << "\n\n";
    }
}

int main() {
    Book books[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    do {
        cout << "\nLibrary Management System Menu:" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Issue Book" << endl;
        cout << "3. Return Book" << endl;
        cout << "4. Display Books" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(books, bookCount);
                break;
            case 2:
                issueBook(books, bookCount);
                break;
            case 3:
                returnBook(books, bookCount);
                break;
            case 4:
                displayBooks(books, bookCount);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}