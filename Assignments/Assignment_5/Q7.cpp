#include <iostream>
using namespace std;

#define MAX_OPS 10 // maximum operators we can store

// Structure to hold operator info
struct Operator
{
    char symbol;
    int precedence;
    string associativity;
};

// Structure for Operator Table
struct OperatorTable
{
private:
    Operator ops[MAX_OPS];
    int count;

public:
    // Constructor
    OperatorTable()
    {
        count = 0;
        cout << "Operator Table created." << endl;
    }

    // a. Add a new operator
    void addOperator(char symbol, int prec, string assoc)
    {
        if (count == MAX_OPS)
        {
            cout << "Table is full! Cannot add more operators." << endl;
            return;
        }
        ops[count].symbol = symbol;
        ops[count].precedence = prec;
        ops[count].associativity = assoc;
        count++;
        cout << "Operator " << symbol << " added." << endl;
    }

    // b. Check if given character is an operator
    bool isOperator(char symbol)
    {
        for (int i = 0; i < count; i++)
        {
            if (ops[i].symbol == symbol)
                return true;
        }
        return false;
    }

    // c. Find precedence and associativity of operator
    void getOperatorInfo(char symbol)
    {
        for (int i = 0; i < count; i++)
        {
            if (ops[i].symbol == symbol)
            {
                cout << "Operator: " << symbol
                     << " | Precedence: " << ops[i].precedence
                     << " | Associativity: " << ops[i].associativity << endl;
                return;
            }
        }
        cout << symbol << " is not an operator." << endl;
    }

    // d. Display the complete operator table
    void displayTable()
    {
        cout << "\nOperator\tPrecedence\tAssociativity\n";
        cout << "------------------------------------------\n";
        for (int i = 0; i < count; i++)
        {
            cout << "   " << ops[i].symbol << "\t\t"
                 << ops[i].precedence << "\t\t"
                 << ops[i].associativity << endl;
        }
    }
};

// Main function
int main()
{
    OperatorTable table;

    // Add some predefined operators
    table.addOperator('+', 1, "Left");
    table.addOperator('-', 1, "Left");
    table.addOperator('*', 2, "Left");
    table.addOperator('/', 2, "Left");
    table.addOperator('^', 3, "Right");

    cout << endl;

    // Check operator info
    table.getOperatorInfo('+');
    table.getOperatorInfo('^');
    table.getOperatorInfo('a'); // not an operator

    // Display full table
    table.displayTable();

    return 0;
}