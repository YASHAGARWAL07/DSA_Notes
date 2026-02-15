#include <iostream>
#include <vector>
using namespace std;

/*=====================================================
                BASE CLASS : Employee
=====================================================*/

class Employee {
protected:
    string name;
    int id;
    string department;
    double salary;
    vector<string> projects;   // stores project names

    static int totalEmployees;

public:
    // Constructor
    Employee(string n, int i, string dept, double sal) {
        name = n;
        id = i;
        department = dept;
        salary = sal;
        totalEmployees++;
    }

    // Add project
    void addProject(string projectName) {
        projects.push_back(projectName);
    }

    // Display basic info
    virtual void display() {
        cout << "\n----- Employee Details -----\n";
        cout << "Name       : " << name << endl;
        cout << "ID         : " << id << endl;
        cout << "Department : " << department << endl;
        cout << "Salary     : " << salary << endl;
        cout << "Total Projects: " << projects.size() << endl;

        cout << "Project List:\n";
        for (int i = 0; i < projects.size(); i++) {
            cout << i + 1 << ". " << projects[i] << endl;
        }
    }

    // Static function
    static void showTotalEmployees() {
        cout << "\nTotal Employees in Company: " << totalEmployees << endl;
    }

    virtual ~Employee() {}
};

int Employee::totalEmployees = 0;


/*=====================================================
            DERIVED CLASS : Developer
=====================================================*/

class Developer : public Employee {
private:
    string programmingLanguage;

public:
    Developer(string n, int i, string dept, double sal, string lang)
        : Employee(n, i, dept, sal) {
        programmingLanguage = lang;
    }

    void display() override {
        Employee::display();
        cout << "Role       : Developer\n";
        cout << "Language   : " << programmingLanguage << endl;
    }
};


/*=====================================================
            DERIVED CLASS : Manager
=====================================================*/

class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(string n, int i, string dept, double sal, int team)
        : Employee(n, i, dept, sal) {
        teamSize = team;
    }

    void display() override {
        Employee::display();
        cout << "Role       : Manager\n";
        cout << "Team Size  : " << teamSize << endl;
    }
};


/*=====================================================
                    MAIN FUNCTION
=====================================================*/

int main() {

    // Creating Developer
    Developer dev1("Yash", 101, "IT", 60000, "C++");
    dev1.addProject("Bank Management System");
    dev1.addProject("AI Chatbot");

    // Creating Manager
    Manager mgr1("Rohit", 201, "IT", 90000, 10);
    mgr1.addProject("ERP System");
    mgr1.addProject("Cloud Migration");
    mgr1.addProject("Cyber Security Audit");

    // Display Details
    dev1.display();
    mgr1.display();

    // Show total employees
    Employee::showTotalEmployees();

    return 0;
}
