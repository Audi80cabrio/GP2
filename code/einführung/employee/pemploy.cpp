#include <iostream>
#include <string>
#include <vector>
#include <ctime>

void print(std::string n, std::string fn, std::vector<int> dob, float sal){
    std::cout << "Name: " << n << '\n';
    std::cout << "First Name: " << fn << '\n';
    std::cout.width(4);
    std::cout << "Year of Birth: " << dob[0] << '\n';
    std::cout.width(2);
    std::cout << "Month of Birth: " << dob[1] << '\n';
    std::cout.width(2);
    std::cout << "Day of Birth: " << dob[2] << '\n';
    std::cout << "Salary: " << sal << '\n';
}

void riseSalary(float& sal, int incr){

}

int age(std::vector<int> dob){
    time_t now = time(nullptr);
    tm* t = localtime(&now);
    int year = t->tm_year + 1900;
    int month = t->tm_mon + 1;
    int day = t->tm_mday;
    int res = year - dob[0] - 2 ; //wenn geburtstag noch nicht war
    if(month < dob[1] || month == dob[1] && day >= dob[2])
    {
        res++;
    }
    return res;
}

int main(){
    std::string name = "Weinlich";
    std::string firstName = "Louis";
    std::vector<int> dateOfBirth{2005, 25, 9};
    float salary = 2528.0;

    print(name, firstName, dateOfBirth, salary);
    std::cout << "Age: " << age(dateOfBirth) << '\n';
    riseSalary(salary, 5);

}