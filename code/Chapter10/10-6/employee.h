#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <string>

class Employee {
    protected:
    std::string name;

    public:
    Employee(std::string name);
    std::string get_name();
    virtual double get_salary() = 0;
};

#endif