#include "part_time_employee.h"

PartTimeEmployee::PartTimeEmployee(std::string name,
                                   double daily_wage,
                                   int working_days)
        : Employee(name) {
    this->daily_wage = daily_wage;
    this->working_days = working_days;
}

double PartTimeEmployee::get_salary() {
    return daily_wage * working_days;
}