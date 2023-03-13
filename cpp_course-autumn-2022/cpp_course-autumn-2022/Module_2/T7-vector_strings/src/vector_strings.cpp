#include "vector_strings.hpp"

#include <iostream>
#include <vector>

void Adder(std::vector<std::string>& names) {
    std::string name;
    std::cout << "Enter a name:" << std::endl;
    std::cin >> name;
    names.push_back(name);
    std::cout << "Number of names in the vector:" << std::endl;
    std::cout << names.size() << std::endl;
}

void Remover(std::vector<std::string>& names) {
    int index = names.size() - 1;
    std::cout << "Removing the last element:" << std::endl;
    std::cout << names[index] << std::endl;
    names.pop_back();
}

void Printer(std::vector<std::string>& names) {
  for (unsigned int i = 0; i < names.size(); i++){
    std::cout << names[i] << std::endl;
  }
}

void CMDReader() {
  std::cout << "Commands: ADD, PRINT, REMOVE, QUIT" << std::endl;
  int i = 0;
  std::vector<std::string> vector;
  while (i == 0){
    std::string command;
    std::cout << "Enter a command:" << std::endl;
    std::cin >> command;
    if (command == "ADD"){
        Adder(vector);
    }
    else if (command == "PRINT"){
        Printer(vector);
    }
    else if (command == "REMOVE"){
        Remover(vector);
    }
    else i = 1;
  }
}
