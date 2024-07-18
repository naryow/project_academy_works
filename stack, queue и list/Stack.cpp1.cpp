#include <iostream>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
#include "Stack.h"
template <typename T>
int main() {
	system("cls");
	Stack<T> stack;
	T countRand = 0;
	cin >> countRand;
	for (int i = 0; i < countRand; i++) {
		stack.push(rand() % 10);

	}
	
	return 0;
}