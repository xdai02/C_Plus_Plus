#include "employee.h"

Employee::Employee(std::string name) {
    this->name = name;
}

std::string Employee::get_name() {
    return name;
}