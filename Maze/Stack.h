//Nicolas Caceda 4/4/2018

#pragma once

class Stack {
	private:
		int *list;
		int size;
		int sp;
	public:
		Stack(int n);
		~Stack();
		void Push(int data);
		int Pop();
		int StackSize();
		bool IsEmpty();
};