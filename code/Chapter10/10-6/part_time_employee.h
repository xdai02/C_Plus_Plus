#ifndef _PART_TIME_EMPLOYEE_H_
#define _PART_TIME_EMPLOYEE_H_

#include "employee.h"

class PartTimeEmployee : public Employee {
    private:
    double daily_wage;
    int working_days;

    public:
    PartTimeEmployee(std::string name,
                     double daily_wage,
                     int working_days);
    virtual double get_salary() override;
};

#endif