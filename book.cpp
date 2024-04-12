#include "Book.h"
#include <string>
#include <iostream>
Book::Book(int id, const std::string& title, const std::string& author): id(id), title(title), author(author){}




    std::istream& operator>>(std::istream & is, Book & book) {
        is >> book.id >> book.title >> book.author;
        return is;
    }

    std::ostream& operator<<(std::ostream & os, const Book & book) {
        os << "ID: " << book.id << "\nTitle: " << book.title << "\nAuthor: " << book.author<< "\n";
        return os;
    };
