#include <iostream>
#include <queue>
#include <deque>
using namespace std;
#pragma once
template <typename T>
class Queue
{
private:
	deque<T> deq;
public:
	void front(T data) {
		deq.front(data);
	}
	void pop(T data) {
		if (!deq.empty()) {
			deq.pop_back();
		}
		else return;
	}
};

