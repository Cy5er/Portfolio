#include "book.hpp"

#include <ctime>
#include <iostream>


Book::Book(std::string const& name, std::string const& author, std::string const& isbn, bool loaned, Date due_date) {
    name_ = name, author_ = author, isbn_ = isbn, loaned_ = loaned, due_date_ = due_date;
}

std::string Book::GetName() const {
    return name_;
}

std::string Book::GetAuthor() const {
    return author_;
}

std::string Book::GetISBN() const {
    return isbn_;
}

bool Book::GetStatus() const {
    return loaned_;
}

Date Book::GetDueDate() const {
    return due_date_;
}

bool Book::Loan(void) {
    bool asdf = false;
    if(loaned_ == false) {
        due_date_ = Date::Today();
        due_date_.month++;
        loaned_ = true;
        asdf = true;
    }
    return asdf;
}

void Book::Restore(void) {
    loaned_ = false;
    due_date_ = {0, 0, 0};
}

void Book::Print(void) const {
    std::cout << "Book: " << GetName() << ", author: " << GetAuthor() << ", ISBN: " << GetISBN() << ", loaned " << (GetStatus() ? "true" : "false") << ", due date: " << due_date_.day << "." << due_date_.month << "." << due_date_.year << std::endl;
}