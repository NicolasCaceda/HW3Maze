//Nicolas Caceda 4/4/2018 

#include "stdafx.h"
#include "Stack.h"

Stack::Stack(int n) {
	list = new int[n];
	if (list == nullptr) {
		printf("Error! Out of memory.");
		size = 0;
	}
	else {
		size = n;
	}
}

Stack::~Stack() {
	delete list;
}

void Stack::Push(int data) {
	if (sp < size) {
		list[sp] = data;
		sp = sp + 1;
	}
	else {
		printf("Stack is full. \n");
	}
}

int Stack::Pop() {
	int hold = 0;
	if (sp > 0) {
		sp = sp - 1;
		hold = list[sp];
	}
	return hold;
}

int Stack::StackSize() {
	return sp;
}

bool Stack::IsEmpty() {
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}