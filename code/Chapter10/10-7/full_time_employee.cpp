#include "full_time_employee.h"

FullTimeEmployee::FullTimeEmployee(std::string name,
                                   double basic_salary,
                                   double bonus)
        : Employee(name) {
    this->basic_salary = basic_salary;
    this->bonus = bonus;
}

double FullTimeEmployee::get_salary() {
    return basic_salary + bonus;
}