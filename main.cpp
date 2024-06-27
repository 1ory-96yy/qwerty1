#include <iostream>

class Human {
public:
    virtual ~Human() {}
    virtual void info() const {
        std::cout << "This is an object of class Human." << std::endl;
    }
};

class Employee : public Human {
public:
    void info() const override {
        std::cout << "This is an object of class Employee." << std::endl;
    }

    void employeeWork() {
        std::cout << "I work as an Employee." << std::endl;
    }
};

int main() {
    Human human;
    Employee employee;
    Human* humanPtr = &employee;
    Employee* employeePtr = dynamic_cast<Employee*>(humanPtr);

    if (employeePtr) {
        std::cout << "Successfully casted Human& to Employee&." << std::endl;
        employeePtr->employeeWork();
    }
    else {
        std::cout << "Failed to cast Human& to Employee&." << std::endl;
    }

    Employee employee2;
    Human& humanRef = employee2;
    Employee& employeeRef = dynamic_cast<Employee&>(humanRef);
    humanPtr->info(); 
    employeePtr->info(); 
    employeeRef.info();

    return 0;
}
