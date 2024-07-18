#include <iostream>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
#include "Queue.h"
template <typename T>
int main() {
	Queue<T> q;

	T countRand = 0;
	cin >> countRand;
	for (int i = 0; i < countRand; i++) {
		q.front(rand() % 10);

	}

	return 0;
}
