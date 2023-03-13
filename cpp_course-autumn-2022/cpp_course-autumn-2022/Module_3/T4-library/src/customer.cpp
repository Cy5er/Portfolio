#include "customer.hpp"
#include <iostream>

Customer::Customer(std::string const& name, std::string const& c_id) {
    name_ = name, c_id_ = c_id;
}

std::string Customer::GetName(void) const {
    return name_;
}

std::string Customer::GetID(void) const {
    return c_id_;
}

int Customer::GetLoanAmount() const {
    return l_books_.size();
}

std::vector<Book> Customer::GetLoans(void) const {
    return l_books_;
}

bool Customer::LoanBook(Book& book) {
    bool asdf = false;
    if(book.Loan()) {
        l_books_.emplace_back(book);
        asdf = true;
    }
    return asdf;
}

void Customer::ReturnBook(Book& book) {
    int counter = 0;
    for(auto i: l_books_) {
        if(i.GetName() == book.GetName()) {
            l_books_.erase(l_books_.begin() + counter);
            break;
        }
        counter++;
    }
    book.Restore();
}

void Customer::Print(void) const {
    std::cout << "Customer: " << GetName() << ", " << GetID() << ", has " << GetLoanAmount() << " books on loan:" << std::endl;
    for(auto& i: l_books_) {
        std::cout << "- ";
        i.Print();
    }
}

