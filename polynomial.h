#pragma once
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

template <class T>
class Node {
public:
	T coef, exp;
	Node<T>* next;
	Node(T coef = 0, T exp = 0) {
		this->coef = coef;
		this->exp = exp;
		next = NULL;
	}
};

template <class T>
class Polynomial {
public:
	Node<T>* head;
	Polynomial() {
		head = NULL;
	}
	

	//function to delete the current head node
	void delete_b() {
		if(head->next == NULL) {
			head->coef = head->exp = 0;
			return;
		}
		Node<T>* x = head;
		head = head->next;
		delete x;
	}

	//function to delete a node with a known value of exp
	void deleteN(double e) {
		if(head->exp == e) {
			delete_b();
			return;
		}
		Node<T>* p = head->next;
		Node<T>* q = head;
		while(p != NULL) {
			if(p->exp == e) {
				q->next = p->next->next;
				delete p;
				return;
			}
			p = p->next;
			q = q->next;
		}	
	}

	//function to insert nodes in decreasing order of exp
	//a pre-existing node is modified/deleted if the value of exp is not unique
	void insert(T coef, T exp) {
		//if the polynomial is empty
		if(head == NULL) {
			head = new Node<T>(coef, exp);
			return;
        }
		
        if(coef == 0) 
            return;
		
		Node<T>* tmp = new Node<T>(coef, exp);

		if(exp == head->exp) {
			head->coef += coef;
			if(head->coef == 0)
				deleteN(head->exp);
			return;
		}		

		if(exp > head->exp) {
			tmp->next = head;
			head = tmp;
			return;
		}
		
		Node<T>* prev = head;
		Node<T>* cur = head->next;
		while(cur != NULL) {
            if(exp == cur->exp) {
				cur->coef += coef;
				if(cur->coef == 0) {
					deleteN(cur->exp);
				}
                return;
            }

			if(exp > cur->exp) {
				prev->next = tmp;
				tmp->next = cur;
				return;
			}
			prev = cur;
			cur = cur->next;
		}			
		prev->next = tmp;
	}

	void insert(Node<T>* x) {
		insert(x->coef, x->exp);
	}

	//
	void input() {
		cout << "Enter coef followed by exponent. Enter 0 0 to stop taking input" << endl;
		double a, b;
		while(1) {
			cin >> a >> b;
			if(!a && !b)
				return;
			insert(a, b);
		}
	}

	//Overloading > operator for comparing two polynomials
	friend bool operator>(Polynomial<T> x , Polynomial<T> y) {
		Node<T>* xHead = x.head;
		Node<T>* yHead = y.head;
		char firstGT = '0';
		while(xHead != NULL || yHead != NULL) {
			if(xHead == NULL)
				return true;
			if(yHead == NULL)
				return true;
			
			if(xHead->exp > yHead->exp)
				return true;
			if(xHead->exp < yHead->exp)
				return false;

			if(firstGT == '0') {
				firstGT = (xHead->coef > yHead->coef) ? '1' : '2';
			}

			xHead = xHead->next;
			yHead = yHead->next;
		}
		if(firstGT == '0')
			return true;
		return firstGT == '1';
	}
	
	//function to multiply two polynomials
	//returns the product of two input polynomials - p and q
	friend Polynomial<T> multiply(Polynomial<T>* p, Polynomial<T>* q) {
		Polynomial<T> r;
		Node<T>* a = p->head;
		while(a != NULL) {
			Node<T>* b = q->head;
			while(b != NULL) {
				r.insert(a->coef*b->coef, a->exp+b->exp);
				b = b->next;
			}
			a = a->next;
		}
		return r;
	}

	//funtion to divide two polynomials
	//returns the quotient obtained on division of p by q
	//modifies the value of p at each step
	//the final value of p acts as the remainder
    friend Polynomial<T> divide(Polynomial<T>* p, Polynomial<T>* q) {
		Polynomial<T> Q;
		while(q->head->exp <= p->head->exp) {
			double mTempCoef = p->head->coef / q->head->coef;
			double mTempExp = p->head->exp - q->head->exp;
			Q.insert(mTempCoef, mTempExp);
			Node<T>* qHead = q->head;
			while(qHead != NULL) {
				p->insert(mTempCoef * qHead->coef * -1, mTempExp + qHead->exp);
				// if(qHead == NULL)
				// 	break;
				qHead = qHead->next;
			}
		}
		return Q;
	}
	
	//function to display the polynomial
	void display() {
		if(head == NULL) {
			cout << "0" << endl;
			return;
		}
		
		Node<T>* tmp = head;
		do {
            if(tmp->exp != 0) {
                if(tmp == head && tmp->coef > 0) {
                    if(tmp->coef == 1)
                        cout << "x^" << tmp->exp;
                    else
                        cout << tmp->coef << "x^" << tmp->exp;
                    tmp = tmp->next;
                    continue;
                }
                
                if(tmp->coef < 0) {
                    if(tmp->coef == -1)
                        cout << "-x^" << tmp->exp;
                    else
                        cout << tmp->coef << "x^" << tmp->exp;
                } else {
                    if(tmp->coef == 1)
                        cout << "+" << "x^" << tmp->exp;
                    else
                        cout << "+" << tmp->coef << "x^" << tmp->exp;
                }
            }
            else {
                if(tmp == head)
                    cout << tmp->coef;
                else {
                    if(tmp->coef > 0)
                        cout << "+"  << tmp->coef;
                    else
                        cout << tmp->coef;
                }
            }
            tmp = tmp->next;
        } while(tmp != NULL);
        cout << endl;
	}
};
