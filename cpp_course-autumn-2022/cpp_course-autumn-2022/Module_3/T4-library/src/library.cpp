#include <iostream>
#include "book.hpp"
#include "customer.hpp"
#include "library.hpp"

Library::Library(std::string const& lib_name) {
    lib_name_ = lib_name;
}

std::string Library::GetName(void) const {
    return lib_name_;
}

std::vector<Book>& Library::GetBooks(void) {
    return name_;
}

std::vector<Customer>& Library::GetCustomers(void) {
    return c_id_;
}

Book Library::FindBookByName(std::string const& name)
{
    Book FoundBook("", "", "");
    for(auto i: name_) {
        if(i.GetName() == name) {
            FoundBook = i;
        }
    }
    return FoundBook;
}

std::vector<Book> Library::FindBooksByAuthor(std::string const& author)
{
    std::vector<Book> FoundBooks;
    for(auto i: name_) {
        if(i.GetAuthor() == author) {
            FoundBooks.emplace_back(i);
        }
    }
    return FoundBooks;
}

std::vector<Book> Library::FindAllLoanedBooks() {
    std::vector<Book> FoundBooks;
    for(auto i: name_) {
        if(i.GetStatus()) {
            FoundBooks.emplace_back(i);
        }
    }
    return FoundBooks;
}

Customer Library::FindCustomer(std::string const& c_id) {
    Customer FoundCustomer("", "");
    for(auto i: c_id_) {
        if(i.GetID() == c_id) {
            FoundCustomer = i;
        }
    }
    return FoundCustomer;
}