#include "StackL.h"

int Stack::size() {
	return data.size();
}

void Stack::push(int i) {
	data.insert(i, data.size()+1);
}

void Stack::pop() {
	data.remove(data.size());
}

int Stack::top() {
	return data.get(data.size());
}

void Stack::clear() {
	data.clear();
}
