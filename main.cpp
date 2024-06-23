#include <iostream>
#include <Windows.h>
class ������ {
public:
    virtual ~������() {} 
    virtual void info() const {
        std::cout << "�� ��'��� ����� ������\n";
    }
};

class ��������� : public ������ {
public:
    void info() const override {
        std::cout << "�� ��'��� ����� ���������\n";
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ��������� worker;
    ������* humanPtr = &worker; 
    ���������* workerPtr = dynamic_cast<���������*>(humanPtr);  

    if (workerPtr) {
        std::cout << "������ ��������� ������& �� ���������& ����� dynamic_cast\n";
    }
    else {
        std::cout << "dynamic_cast �� ������� �������� ������& �� ���������&\n";
    }
    ������& humanRef = worker;
    ���������& workerRef = dynamic_cast<���������&>(humanRef);

    workerRef.info();

    return 0;
}
