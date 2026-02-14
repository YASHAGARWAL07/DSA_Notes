#include <iostream>
using namespace std;

struct node {
    int coef;
    int exp;
    node* next;
};

struct polynomial {
    node* head;

    polynomial() {
        head = NULL;
    }

    void insert_sorted(int c, int e) {
        node* temp = new node;
        temp->coef = c;
        temp->exp = e;
        temp->next = NULL;

        if (head == NULL || head->exp < e) {
            temp->next = head;
            head = temp;
            return;
        }

        node* cur = head;
        while (cur->next != NULL && cur->next->exp > e) {
            cur = cur->next;
        }

        if (cur->next != NULL && cur->next->exp == e) {
            cur->next->coef += c;
            delete temp;
        } else {
            temp->next = cur->next;
            cur->next = temp;
        }
    }

    void create(int terms) {
        for (int i = 1; i <= terms; i++) {
            int c, e;
            cout << "Enter coefficient and exponent of term " << i << ": ";
            cin >> c >> e;
            insert_sorted(c, e);
        }
    }

    void display() {
        if (head == NULL) {
            cout << "0\n";
            return;
        }
        node* t = head;
        while (t != NULL) {
            cout << t->coef << "x^" << t->exp;
            if (t->next != NULL) cout << " + ";
            t = t->next;
        }
        cout << endl;
    }

    int power(int base, int exp) {
        int result = 1;
        for (int i = 0; i < exp; i++) {
            result *= base;
        }
        return result;
    }

    int evaluate(int x) {
        int sum = 0;
        node* t = head;
        while (t != NULL) {
            sum += t->coef * power(x, t->exp);
            t = t->next;
        }
        return sum;
    }

    int compare(polynomial& p2) {
        node* a = head;
        node* b = p2.head;
        while (a != NULL && b != NULL) {
            if (a->exp != b->exp || a->coef != b->coef)
                return 0;
            a = a->next;
            b = b->next;
        }
        return (a == NULL && b == NULL);
    }

    polynomial add(polynomial& p2) {
        polynomial res;
        node* a = head;
        node* b = p2.head;

        while (a != NULL && b != NULL) {
            if (a->exp > b->exp) {
                res.insert_sorted(a->coef, a->exp);
                a = a->next;
            } else if (a->exp < b->exp) {
                res.insert_sorted(b->coef, b->exp);
                b = b->next;
            } else {
                res.insert_sorted(a->coef + b->coef, a->exp);
                a = a->next;
                b = b->next;
            }
        }

        while (a != NULL) {
            res.insert_sorted(a->coef, a->exp);
            a = a->next;
        }
        while (b != NULL) {
            res.insert_sorted(b->coef, b->exp);
            b = b->next;
        }

        return res;
    }
};

int main() {
    polynomial p1, p2;
    int n;

    cout << "Enter total terms for polynomial 1: ";
    cin >> n;
    p1.create(n);

    cout << "Enter total terms for polynomial 2: ";
    cin >> n;
    p2.create(n);

    cout << "First polynomial: ";
    p1.display();
    cout << "Second polynomial: ";
    p2.display();

    int x;
    cout << "Enter value of x for evaluation: ";
    cin >> x;

    cout << "P1(" << x << ") = " << p1.evaluate(x) << endl;
    cout << "P2(" << x << ") = " << p2.evaluate(x) << endl;

    if (p1.compare(p2))
        cout << "Both polynomials are equal\n";
    else
        cout << "Polynomials are not equal\n";

    polynomial p3 = p1.add(p2);
    cout << "Addition result: ";
    p3.display();

    return 0;
}
