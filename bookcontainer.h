#ifndef BOOK_CONTAINER_H
#define BOOK_CONTAINER_H

#include "Book.h"

namespace BookContainer {
    class BookList {
    private:

    public:
        BookList();
        ~BookList();
        void addBook();
        void displayInfo(int id, const std::string& title, const std::string& author) const;
        void removeBook(const std::string& filename, const std::string& id);
        void editBook(const std::string& filename, const std::string& idToUpdate, const std::string& newAuthor, const std::string& newTitle, const std::string& newId);
        void searchByAuthor(const std::string& author);
        void displayAllBooks();
        void saveToFile(const Book& book);
    };
}

#endif

