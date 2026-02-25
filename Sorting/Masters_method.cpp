#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, k;

    cout << "Master's Theorem Solver\n";
    cout << "Recurrence form: T(n) = aT(n/b) + n^k\n\n";

    cout << "Enter value of a: ";
    cin >> a;

    cout << "Enter value of b: ";
    cin >> b;

    cout << "Enter value of k (power of n): ";
    cin >> k;

    // Calculate log_b(a)
    double logba = log(a) / log(b);

    cout << "\nlog_b(a) = " << logba << endl;

    // Compare log_b(a) with k
    if (logba > k)
    {
        cout << "\nCase 1 applies.\n";
        cout << "Time Complexity: Theta(n^" << logba << ")\n";
    }
    else if (abs(logba - k) < 0.0001)
    {
        cout << "\nCase 2 applies.\n";
        cout << "Time Complexity: Theta(n^" << k << " log n)\n";
    }
    else
    {
        cout << "\nCase 3 applies.\n";
        cout << "Time Complexity: Theta(n^" << k << ")\n";
    }

    return 0;
}