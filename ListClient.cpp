#include <iostream>
#include "List.h"

using namespace std;

int main() {
	 List L1, L2;

	 //Do some stuff with L1, L2, ...
	 // ...
	 for(int i = 0; i < 10; i++)
	 	L1.insert(i, i+1);
	 L1.display();
	 cout<<L1.get(5)<<endl;
	 L1.clear();
	 L1.insert(2, 1);
	 L1.display();
}
