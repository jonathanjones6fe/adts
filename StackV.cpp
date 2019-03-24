#include "StackV.h"
#include <stdexcept>//used to be able to "throw" exceptions

int Stack::size() {
	return data.size();
}

void Stack::push(int i) {
	data.push_back(i);
}

void Stack::pop() {
	if (!data.empty())
		data.pop_back();
}

int Stack::top() {
	if (!data.empty())
		return data[size() - 1];
	else throw out_of_range("Stack is empty");
}

void Stack::clear() {
	while(!data.empty())
		pop();
}
