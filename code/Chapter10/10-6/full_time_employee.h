#ifndef _FULL_TIME_EMPLOYEE_H_
#define _FULL_TIME_EMPLOYEE_H_

#include "employee.h"

class FullTimeEmployee : public Employee {
    private:
    double basic_salary;
    double bonus;

    public:
    FullTimeEmployee(std::string name,
                     double basic_salary,
                     double bonus);
    virtual double get_salary() override;
};

#endif