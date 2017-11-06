#include "polynomial.h"
#include<stdlib.h>


using namespace std;

int main() {
    Polynomial<double> a;
    Polynomial<double> b;

    cout << "Enter first polynomial:" << endl;
    a.input();
    cout << "Enter second polynomial:" << endl;
    b.input();
    int x=0;

    while(x!=7){
        cout<<"\n1.Display Polynomial 1\n2.Display Polynomial 2\n3.Insert to Polynomial 1\n4.Insert to Polynomial 2\n5.Multiplication of 2 Polynomials\n6.Division of 2 Polynomials\n7.Exit\n";
        cin>>x;

    if(x==1)
        a.display();
    if(x==2)
        b.display();
    if(x==3){
        cout<<"\nEnter coef";
        double c;
        cin>>c;
        cout<<"\nEnter exponent";
        double exp;
        cin>>exp;
        a.insert(c,exp);

    }
        if(x==4){
        cout<<"\nEnter coef";
        double c;
        cin>>c;
        cout<<"\nEnter exponent";
        double exp;
        cin>>exp;
        b.insert(c,exp);

    }
    if(x==5)
    {   Polynomial<double> p = multiply(&a,&b);
        cout << "Product: ";
        p.display();
    }
    if(x==6){
        bool swapped = false;
        if(b > a) {
            Polynomial<double> tmp = b;
            b = a;
            a = tmp;
            swapped = true;
        }
        Polynomial<double> q = divide(&a,&b);

        cout << "Division\n";
        cout << "Quotient: ";
        q.display();
        cout << "Remainder: ";
        a.display();
    }
    for(int i=0;i<130000000;i++)
    {}

    system("clear"); //For Linux based systems
    //system("cls") for Windows;
    }
}
