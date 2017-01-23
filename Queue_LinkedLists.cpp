#include <iostream>

using std::cout;
using std::endl;

template <class T>
class Queue;

template <class T>
class Node
{
	friend class Queue<T>;
	public:
		Node() :Data(0), Next(0) {};
		Node(T x) :Data(x), Next(0) {};
	private:
		T Data;
		Node<T> *Next;
};

template <class T>
class Queue
{
	public:
		Queue() : front(-1), rear(-1), first(0) {};
		bool Empty();
		Node<T> *Last();
		void Push(T);
		T Pop();
		void PrintQueue();
	private:
		int front;
		int rear;
		Node<T> *first;
};

int main()
{
	Queue<int> queue;
	queue.Push(10);
	queue.Push(11);
	queue.Pop();
	queue.Push(12);
	queue.Push(13);
	queue.Pop();
	queue.PrintQueue();

	Queue<char> queue1;
	queue1.Push('A');
	queue1.Push('B');
	queue1.Pop();
	queue1.Push('C');
	queue1.Push('D');
	queue1.Pop();
	queue1.PrintQueue();

	system("pause");
	return 0;
}

template <class T>
bool Queue<T>::Empty()
{
	if (first == 0) { return true; }
	else { return false; };
}

template <class T>
Node<T>* Queue<T>::Last()
{
	Node<T> *current = first;
	while (current->Next != 0)
	{
		current = current->Next;
	}
	return current;
}

template <class T>
void Queue<T>::Push(T x)
{
	Node<T> *newnode = new Node<T>(x);
	Node<T> *current = first;
	if (current == 0)
	{
		first = newnode;
		rear++;
		front++;
		return;
	}

	Last()->Next = newnode;
	rear++;
	front++;
}

template <class T>
T Queue<T>::Pop()
{
	if (first->Next == 0) 
	{
		T tmp = first->Data;
		cout << "Queue is empty!!" << endl; 
		rear--;
		front--;
		delete first;
		first = 0;
		return tmp;
	}
	else
	{
		Node<T> *current = first;
		T tmp = first->Data;
		first = first->Next;
		rear--;
		delete current;
		current = 0;
		return tmp;
	}
}

template <class T>
void Queue<T>::PrintQueue()
{
	Node<T> *current = first;
	while (current != 0)
	{
		cout << current->Data << " ";
		current = current->Next;
	}
	cout << endl;
}