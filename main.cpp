#include <iostream>
#include <Windows.h>
class Людина {
public:
    virtual ~Людина() {} 
    virtual void info() const {
        std::cout << "Це об'єкт класу Людина\n";
    }
};

class Працівник : public Людина {
public:
    void info() const override {
        std::cout << "Це об'єкт класу Працівник\n";
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Працівник worker;
    Людина* humanPtr = &worker; 
    Працівник* workerPtr = dynamic_cast<Працівник*>(humanPtr);  

    if (workerPtr) {
        std::cout << "Успішно приведено Людина& до Працівник& через dynamic_cast\n";
    }
    else {
        std::cout << "dynamic_cast не вдалося привести Людина& до Працівник&\n";
    }
    Людина& humanRef = worker;
    Працівник& workerRef = dynamic_cast<Працівник&>(humanRef);

    workerRef.info();

    return 0;
}
