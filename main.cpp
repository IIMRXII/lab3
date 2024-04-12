#include <iostream>
#include "bookcontainer.h"
#include "Book.h"
#include "windows.h"



using namespace std;
using namespace BookContainer;

int main() {
    BookContainer::BookList library;

    int choice;
    bool continueMenu = true;

    while (continueMenu) {
        std::cout << "File is named books.txt :)";
        std::cout << "Main:\n";
        std::cout << "1. Add book\n";
        std::cout << "2. Remove book\n";
        std::cout << "3. Edit book\n";
        std::cout << "4. Search By Author\n";
        std::cout << "5. Display all books\n";
        std::cout << "6. Exit\n";



        std::cout << "Select an action: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
        {
            Book newBook;

            library.addBook();
            break;
        }
        case 2: {
            std::string id;
            std::string filename;
            cout << "Enter name of file: ";
            cin >> filename;
            cout << "Enter ID of the book for remove: ";
            cin >> id;
            library.removeBook(filename, id);
            break;
        }
        case 3: {
            std::string idToUpdate;
            std::string filename;
            std::string newAuthor;
            std::string newTitle;
            std::string newId;
            std::cout << "Enter filename: ";
            std::cin >> filename;
            std::cout << "Enter ID of the book for edit: ";
            std::cin >> idToUpdate;
            std::cout << "Enter new ID: ";
            std::cin >> newId;
            std::cout << "Enter new Title: ";
            std::cin >> newTitle;
            std::cout << "Enter Author: ";
            std::cin >> newAuthor;
            library.editBook(filename,idToUpdate, newId, newTitle, newAuthor);
            break;
        }
        case 4: {
            std::string authorToSearch;
            std::cout << "Enter author for search: ";
            std::cin >> authorToSearch;
            library.searchByAuthor(authorToSearch);
            break;
        }
        case 5: {
            library.displayAllBooks();
            break;
        }
        case 6:
            cout << "Goodbye!\n";
            return 0;
            break;
        default:
            cout << "Incorrect input. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}