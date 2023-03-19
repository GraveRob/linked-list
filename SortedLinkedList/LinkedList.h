#pragma once

#include <iostream>
#include "Node.h";

template <typename T>
class LinkedList
{
protected:
	Node<T>* head;
	int size;

public:
	LinkedList() {
		head = nullptr;
		size = 0;
	};

	~LinkedList()
	{
		Node<T>* node;
		while (head != nullptr)
		{
			node = head;
			head = head->next;
			delete node;
		}
		size = 0;
	}

	int getSize() {
		return size;
	}

	Node<T>* getHead() {
		return head;
	}


	virtual void addElement(T element) {
		size += 1;
		Node<T>* addedNode = new Node<T>(element);

		if (head == nullptr) {
			head = addedNode;
			return;
		}

		addedNode->next = head;
		head = addedNode;
	}

	void addElementToEnd(T element) {
		size += 1;
		Node<T>* addedNode = new Node<T>(element);
		Node<T>* cur = head;

		if (head == nullptr) {
			head = addedNode;
			return;
		}

		while (cur->next != nullptr) {
			cur = cur->next;
		}

		cur->next = addedNode;
	}

	void printAllElements() {
		Node<T>* currentNode = head;

		while (currentNode != nullptr) {
			std::cout << currentNode->data << ' ';
			currentNode = currentNode->next;
		}
	};

	Node<T>* findNodeByIndex(int index) {
		if (!checkIndexIsValid()) {
			std::cout << "Error happened\n";
			return;
		}

		int counter = 0;
		Node<T>* node = head;

		while (counter < index) {
			node = node->next;
			counter++;
		}

		return node;
	}

	bool checkIndexIsValid(int index) {
		return index >= 0 && index < size;
	}

	void removeNodeByIndex(int index) {
		if (!checkIndexIsValid(index)) {
			 std::cout << "Error happened\n";
			 return;
		}

		Node<T>* nodeToDelete = head;
		Node<T>* prevNode = nullptr;
		int counter = 0;

		while (counter < index) {
			prevNode = nodeToDelete;
			nodeToDelete = nodeToDelete->next;
			counter += 1;
		}

		if (nodeToDelete == nullptr) {
			std::cout << "Error happened\n";
			return;
		}

		if (prevNode != nullptr) {
			prevNode->next = nodeToDelete->next;
		}
		else {
			head = nodeToDelete->next;
		}
		
		delete nodeToDelete;
		size -= 1;
	};

	Node<T>* findNodeByValue(T value) {
		Node<T>* node = head;
		while (node->data != value && node != nullptr) {
			node = node->next;
		}

		return node;
	}

	void removeNodeByValue(T value) {
		Node<T>* nodeToDelete = head;
		Node<T>* prevNode = nullptr;

		while (nodeToDelete != nullptr && nodeToDelete->data != value) {
			prevNode = nodeToDelete;
			nodeToDelete = nodeToDelete->next;
		}

		if (nodeToDelete == nullptr) {
			std::cout << "Error happened\n";
			return;
		}

		if (prevNode != nullptr) {
			prevNode->next = nodeToDelete->next;
		}
		else {
			head = nodeToDelete->next;
		}

		delete nodeToDelete;
		size -= 1;
	}

	void sortNodesData() {
		bool unsorted = true;
		Node<T>* cur;

		while (unsorted) {
			unsorted = false;
			cur = head;

			while (cur != nullptr && cur->next != nullptr) {
				Node<T>* next = cur->next;
				if (next->data < cur->data) {
					T tmp = cur->data;
					cur->data = next->data;
					next->data = tmp;

					unsorted = true;
				}

				cur = cur->next;
			}
		}
	}
};


