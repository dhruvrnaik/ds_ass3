#include "polynomial.h"

int main() {
    Polynomial<double> a;
    Polynomial<double> b;

    cout << "Enter first polynomial:" << endl;
    a.input();
    cout << "Enter second polynomial:" << endl;
    b.input();
    Polynomial<double> p = multiply(&a,&b);
    Polynomial<double> q = divide(&a,&b);

    cout << "Product: ";
    p.display();
    cout << "Division\n";
    cout << "Quotient: ";
    q.display();
    cout << "Remainder: ";
    if(b.head->exp > a.head->exp ||((b.head->exp == a.head->exp)&&(b.head->coef > a.head->coef)))
    a.display();
    else
    b.display();
}
