#include <iostream>
using namespace std;

//parent class
class human {
    //for inheritence we have to use protected access specifier
    protected :
    string name;
    int age;

    public :
    human( string name,int age){
        this->name = name;
        this->age = age;
    }
};
//child class
class customer : public human{
    int acc_number;
    double balance;

    public : 
    customer(string name ,int age, int acc_number , double balance) 
    : human(name,age)           //calling base constructor
    {           
        this->acc_number = acc_number;
        this->balance = balance;
    }
    void display_balance(){
        cout<<balance<<endl;
    }
    void display_details(){
        cout<<"Name is : "<<name<<endl;
        cout<<"age is : " <<age<<endl;
        cout<<"account number is : "<<acc_number<<endl;
        cout<<"Balance is : " <<balance<< endl;
     }
};
int main(){
    customer A1("YASH",18,7416,200);
    A1.display_balance();
    A1.display_details();
    
}
