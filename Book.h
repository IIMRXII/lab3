#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <fstream>

class Book {
private:
    std::string title;
    std::string author;
    int id;
public:
    void displayInfo() const {
        std::cout << "ID: " << id << std::endl;
        std::cout << "Название: " << title << std::endl;
        std::cout << "Автор: " << author << std::endl;
    }
    Book(int id, const std::string& title, const std::string& author);
    friend std::istream& operator>>(std::istream& is, Book& book);
    friend std::ostream& operator<<(std::ostream& os, const Book& book);
    Book() : title(""), author(""), id(0){}
    int getId() const {
        return id;
    }

    std::string getTitle() const {
        return title;
    }

    std::string getAuthor() const {
        return author;
    }

    void setId(int newId) {
        id = newId;
    }

    void setTitle(const std::string& newTitle) {
        title = newTitle;
    }

    void setAuthor(const std::string& newAuthor) {
        author = newAuthor;
    }
    
};

#endif
