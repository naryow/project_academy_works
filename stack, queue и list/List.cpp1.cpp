#include "List.h"
#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <deque>
using namespace std;


template <typename T>
int main() {
	int numberCount = 0;
	cin >> numberCount;
	List<int> lst;
	lst.pushBack(5);
	lst.pushBack(10);
	lst.pushBack(22);
	cout << lst[2] << endl;

	for (int i = 0; i < numberCount; i++) {
		lst.pushBack(rand() % 10);
	}

	for (int i = 0; i < lst.getSize(); i++) {
		cout << lst[i] << endl;
	}




	return 0;

}