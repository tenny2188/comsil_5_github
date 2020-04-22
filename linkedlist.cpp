#include <iostream>
using namespace std;

// Linked List Node
template <class T>
class Node {
public:
	T data;
	Node* link;
	Node(T element)
	{
		data = element;
		link = 0;
	}
};

template <class T>
class LinkedList
{
protected:
	Node<T>* first;
	int current_size;
public:
	LinkedList()
	{
		first = 0;
		current_size = 0;
	};
	int GetSize();	// ����Ʈ�� ��� ������ ����
	void Insert(T element);	// �� �տ� ���Ҹ� ����
	virtual bool Delete(T& element);	// �� ���� ���Ҹ� ����
	void Print();	// ����Ʈ�� ���
};

// Linked List Class
template <class T>
int LinkedList<T>::GetSize()
{
	return current_size;
}

template <class T>
void LinkedList<T>::Insert(T element)
{ // �� ��带 �� �տ� ����
	Node<T>* newnode = new Node<T>(element);
	newnode->link = first;
	first = newnode;
	current_size++;
}

template <class T>
bool LinkedList<T>::Delete(T& element)
{
	// ������ ����� ���� �����ϸ鼭, �޸𸮿��� �Ҵ� ����
	if (first == 0) return false;
	Node<T>* current = first, * previous = 0;
	while (1) { // ������ ������ ã�ư��� �ݺ���
		if (current->link == 0) // find end node
		{
			if (previous) previous->link = current->link;
			else first = first->link;
			break;
		}
		previous = current;
		current = current->link;
	}
	element = current->data;
	delete current;
	current_size--;
	return true;
}

template <class T>
void LinkedList<T>::Print()
{

	if (first == 0);
	else
	{
		Node<T>* current = first;
		int i = 1;
		while (1)
		{
			if (current->link == 0) // find end node
			{
				cout << "[" << i << "|" << current->data << "]" << endl;
				break;
			}
			cout << "[" << i << "|" << current->data << "]->";
			current = current->link;
			i++;
		}
	}
}

template <class T>
class Stack : public LinkedList<T> {
public:
	bool Delete(T& element);
};

template <class T>
bool Stack<T>::Delete(T& element)
{
	if (this->first == 0) return false;
	Node<T>* del = this->first;
	this->first = this->first->link;
	element = del->data;
	delete del;
	this->current_size--;
	return true;
}
