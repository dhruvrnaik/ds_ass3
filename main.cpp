#include "polynomial.h"

int main() {
    Polynomial<double> a;
    Polynomial<double> b;

    cout << "Enter first polynomial:" << endl;
    a.input();
    cout << "Enter second polynomial:" << endl;
    b.input();
    Polynomial<double> p = multiply(&a,&b);
    bool swapped = false;
    if(b > a) {
        Polynomial<double> tmp = b;
        b = a;
        a = tmp;
        swapped = true;
    }
    Polynomial<double> q = divide(&a,&b);

    cout << "Product: ";
    p.display();
    cout << "Division\n";
    cout << "Quotient: ";
    q.display();
    cout << "Remainder: ";
    a.display();
}