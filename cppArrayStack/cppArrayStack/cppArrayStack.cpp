// cppArrayStack.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <time.h>

using namespace std;

class stack
{
public:
	int maxSize = 0, link = 0, *elements;
public:
	stack();
	~stack();
	stack(int size);

	void push(int number);
	void pop();

	int top();

	bool empty();
	bool full();
};

stack::stack() {
	link = 0;
	maxSize = 10;
	elements = new int[10];
	cout << endl << "Wywolano konstruktor domyslny" << endl << this << endl;
}

stack::stack(int size) {
	link = 0;
	maxSize = size;
	elements = new int[size];
	cout << endl << "Wywolano konstruktor parametrowy" << endl << this << endl;
}

stack::~stack() {
	cout << "Wywolano destructor" << endl << this << endl;
	delete[] elements;
}

bool stack::empty() {
	if (!link) {
		return false;
	}
	else {
		return true;
	}
}

void stack::push(int number) {
	if (link < maxSize) {
		elements[link] = number;
		link++;
	}
	else cout << "Stack is FULL!!!";
}

void stack::pop() {
	if (link > 0)
		link--;
	else
		cout << "Stack is EMPTY!!!";
}

int stack::top() {
	if (link > 0)
		return elements[link - 1];
	else
		cout << "Stack is EMPTY!!!" << endl;
}

bool stack::full() {
	if (link == maxSize)
		return true;
	else
		return false;
}

void f(stack& s, int a) {
	s.push(a);
}

int main()
{
	stack s;
	s.push(0);
	f(s, 1);
	f(s, 2);
	while (!s.empty()) {
		cout << " " <<
		s.top();
		s.pop();
	}
	system("pause"); //comment
    return 0;
}

