#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <deque>
using namespace std;


template <typename T>
class List
{
public:
	List();
	~List();

	void pushBack(T data);
	int getSize() { return Size; };

	T& operator[](const int inndex);
private:
	template <typename T>
	class Node {
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<int>* head;
};

template <typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}
template <typename T>
List<T>::~List()
{

}

template<typename T>
void List<T>::pushBack(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
T& List<T>::operator[](const int inndex)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr) {
		if (counter == inndex) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}



