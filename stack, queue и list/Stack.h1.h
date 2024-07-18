#include <iostream>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
#pragma once
template <typename T>
class Stack {
private:
	deque<T> deq;

public:
	Stack() = default;
	void push(T data) {
		deq.push_back(data);
	}
	void pop(T data) {
		if (!deq.empty()) {
			deq.pop_back();
		}
		else return;
	}
	
};

