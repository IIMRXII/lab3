#include "bookcontainer.h"
#include "Book.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>

namespace BookContainer {
    BookList::BookList() : books(new Book[10]), capacity(10), size(0) {

    }

    BookList::~BookList() {
        delete[] books;
    }

    void BookList::addBook() {
        Book newBook;

        std::cout << "Enter ID of the book: ";
        int id;
        std::cin >> (id);
        newBook.setId(id);
        std::cout << "Enter the name of the book: ";
        std::cin.ignore();
        std::string title;
        std::getline(std::cin, title);
        newBook.setTitle(title);
        std::cout << "Enter the author of the book: ";
        std::string author;
        std::getline(std::cin, author);
        newBook.setAuthor(author);

        saveToFile(newBook);
    }
    void BookList::displayInfo(int id, const std::string& title, const std::string& author) const {
        std::cout << "ID: " << id << std::endl;
        std::cout << "Название: " << title << std::endl;
        std::cout << "Автор: " << author << std::endl;
        std::cout << std::endl;
    }

    void BookList::removeBook(const std::string& filename, const std::string& idToReplace) {
        std::ifstream inFile(filename);
        std::ofstream outFile("file.txt");

        std::string line;

        if (inFile.is_open() && outFile.is_open()) {
            while (std::getline(inFile, line)) {
                std::istringstream iss(line);
                std::string id;
                if (std::getline(iss, id, ',') && id == idToReplace) {
                }
                else {
                    outFile << line << std::endl;
                }
            }

            inFile.close();
            outFile.close();

            std::remove(filename.c_str());
            std::rename("file.txt", filename.c_str()); 
            std::cout << "A string with an ID " << idToReplace << " replaced with an empty string." << std::endl;
        }
        else {
            std::cout << "File opening error." << std::endl;
        }
    }

    void BookList::editBook(const std::string& filename, const std::string& idToUpdate, const std::string& newAuthor, const std::string& newTitle, const std::string& newId) {
        std::ifstream inFile(filename);
        std::ofstream outFile("temp.txt");

        std::string line;

        if (inFile.is_open() && outFile.is_open()) {
            while (std::getline(inFile, line)) {
                std::istringstream iss(line);
                std::string id;
                if (std::getline(iss, id, ',') && id == idToUpdate) {
                    outFile << newAuthor << "," << newTitle << "," << newId << std::endl;
                }
                else {
                    outFile << line << std::endl;
                }
            }

            inFile.close();
            outFile.close();

            std::remove(filename.c_str()); 
            std::rename("temp.txt", filename.c_str()); 
            std::cout << "Информация о книге с ID " << idToUpdate << " обновлена." << std::endl;
        }
        else {
            std::cout << "Ошибка открытия файлов." << std::endl;
    }
}
    

    void BookList::searchByAuthor(const std::string& author) {
        std::ifstream file("books.txt");

        if (file.is_open()) {
            std::ifstream file("books.txt");
            std::string line;
            int lineNumber = 1;

            if (file.is_open()) {
                std::cout << "Lines with the author \"" << author << "\":\n";

                while (std::getline(file, line)) {
                    std::stringstream ss(line);
                    std::string token;

                    while (std::getline(ss, token, ',')) {
                        if (token == author) {
                            std::cout << "Line " << lineNumber << ": " << line << std::endl;
                            break;
                        }
                    }

                    lineNumber++;
                }

                file.close();
            }
            else {
                std::cout << "The file could not be opened for reading." << std::endl;
            }
        }
    }

    void BookList::displayAllBooks() {
        std::ifstream file("books.txt");
        std::string line;

        if (file.is_open()) {
            while (std::getline(file, line)) {
                std::cout << line << std::endl;
            }
            file.close();
        }
        else {
            std::cout << "The file could not be opened for reading." << std::endl;
        }
    }
    void BookList::saveToFile(const Book& book) {
        std::ofstream file("books.txt", std::ios::app);
        if (file.is_open()) {
            file << book.getId() << "," << book.getTitle() << "," << book.getAuthor() << "\n";
            file.close();
            std::cout << "The book is saved in a file." << std::endl;
        }
    }
}
