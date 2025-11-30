//CS210 Project 3  Luke Rickert

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class EmployeeClass {  
    public:
    
    EmployeeClass() {}
    
    EmployeeClass(string name1, string name2, int idNum, int salaryNum) {
        firstName = name1;
        lastName = name2;
        employeeId = idNum;
        monthlySalary = salaryNum;
    }
    
    //getter functions
    string employeeFirstName() {
        return firstName;
    }
    string employeeLastName() {
        return lastName;
    }
    int employeeIdNum() {
        return employeeId;
    }
    int employeeSalary() {
        return monthlySalary;
    }
    
    //setter functions
    void employeeFirstName(string updatedName) {
        firstName = updatedName;
    }
    void employeeLastName(string updatedLName) {
        lastName = updatedLName;
    }
    void employeeIdNum(int updatedId) {
        employeeId = updatedId;
    }
    void employeeSalary(int updatedSalary) {
        monthlySalary = updatedSalary;
    }
    
    
    void printEmployeeInfo() {   //prints first and last name and ID
        cout << "First name: " << firstName << endl;
        cout << "Last name: " << lastName << endl;
        cout << "Employee Id: " << employeeId << endl;
    }
    
    void printMonthlySalary() {  //prints monthly salary
        cout << "Monthly salary: $" << monthlySalary << endl;
    }
    
    void printMonthlySalary(double bonus) {   //prints monthly salary with a bonus
        cout << "Salary with bonus: $" << monthlySalary + bonus << endl;
    }
    
    
    private:
        string firstName;
        string lastName;
        int employeeId;
        int monthlySalary;
};

int main()
{
    vector<EmployeeClass> employeeVector; //holds all employee objects
    
    string userSearchName;   //holds name to search
    
    EmployeeClass e1, e2, e3, e4, e5;
    
    e1 = EmployeeClass("John", "Doe", 1001, 3000);   //These set information of the employee objects using the
    e2 = EmployeeClass("Sally", "Smith", 1002, 4000); // parameterized constructor
    e3 = EmployeeClass("Bob", "Williams", 1003, 2600);
    e4 = EmployeeClass("Mary", "Ramos", 1004, 3200);
    
    
    //Set information of object with setter functions -- in this case not as convenient
    e5.employeeFirstName("Andrew");
    e5.employeeLastName("Anderson");
    e5.employeeIdNum(1005);
    e5.employeeSalary(3500);
    
    employeeVector.push_back(e1);  //Adds all employees to the employeeVector
    employeeVector.push_back(e2);
    employeeVector.push_back(e3);
    employeeVector.push_back(e4);
    employeeVector.push_back(e5);
    
    for (int i = 0; i < employeeVector.size(); ++i) {  //prints all employee's information
        employeeVector.at(i).printEmployeeInfo();
        employeeVector.at(i).printMonthlySalary();
        cout << endl;
    }
    
    for (int i = 0; i < employeeVector.size(); ++i) {   //Gives all employees a 10% raise 
        employeeVector.at(i).employeeSalary((employeeVector.at(i).employeeSalary()) * 1.1);
    }
    
    cout << "Enter an employee name: ";
    cin >> userSearchName;
    cout << endl;
    
    for (int i = 0; i < employeeVector.size(); ++i) {   //Searches for an employee with the input user name. 
        if (employeeVector.at(i).employeeFirstName() == userSearchName || employeeVector.at(i).employeeLastName() == userSearchName) {
            employeeVector.at(i).printEmployeeInfo();      //If found, prints employee info and salary with $1000 bonus
            employeeVector.at(i).printMonthlySalary(1000);
            return 0;  //after printing information, exits the program
        }           
    }
    
    cout << "No employee found" << endl;  //If employee not found, prints this line, then exits the program
    
    return 0;
}

