#include <iostream>
#include "full_time_employee.h"
#include "part_time_employee.h"

using namespace std;

int main() {
    Employee *employees[2] = {
        new FullTimeEmployee("Alice", 5783, 173),
        new PartTimeEmployee("Bob", 150, 15),
    };

    for (Employee *employee : employees) {
        cout << employee->get_name() << ": $"
             << employee->get_salary() << endl;
    }

    return 0;
}