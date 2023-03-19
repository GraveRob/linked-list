#pragma once

#include <string>
#include "LinkedList.h";
#include "ConsoleLogger.h"

class LinkedListTester
{
protected:
	LinkedList<int>* list;
	LinkedList<int>* elements;

	virtual void describeInsertTest() {
		ConsoleLogger::printLine();
		std::cout << "Test #1: Inserting new elements\n";
		std::cout << "Output should be reversed from "; elements->printAllElements(); std::cout << '\n';
		ConsoleLogger::printLine();

		std::cout << '\n';
	}

	void insertElements() {
		Node<int>* tmp = elements->getHead();
		while (tmp != nullptr) {
			list->addElement(tmp->data);
			tmp = tmp->next;
		}
	}

	void printTestResult() {
		ConsoleLogger::printLine();
		std::cout << "Result: ";
		list->printAllElements();
		std::cout << '\n';
		ConsoleLogger::printLine();

		std::cout << '\n';
	}

	virtual void setupBeforeTesting() {
		list = new LinkedList<int>();
	}

	void cleanupAfterTesting() {
		delete list;
	}

	void describeDeleteByIndexTest(int index) {
		ConsoleLogger::printLine();
		std::cout << "Test #2: Deleting element by index\n";
		std::cout << "Output should be without index " << index << "\n";
		ConsoleLogger::printLine();

		std::cout << '\n';
	}

	void deleteElementByIndex(int index) {
		list->removeNodeByIndex(index);
	}

	void describeDeleteByValueTest(int value) {
		ConsoleLogger::printLine();
		std::cout << "Test #3: Deleting element by value\n";
		std::cout << "Output should be without first " << value << "\n";
		ConsoleLogger::printLine();

		std::cout << '\n';
	}

	void deleteElementByValue(int value) {
		list->removeNodeByValue(value);
	}

public:
	LinkedListTester() {
		list = nullptr;
		elements = nullptr;
	}

	LinkedListTester(LinkedList<int>* elements) {
		list = nullptr;
		this->elements = elements;
	}

	~LinkedListTester() {
		delete list;
		delete elements;
	}

	virtual void printTesterIsRunning() {
		std::cout << "LINKED LIST TESTER IS RUNNING\n";
	}

	void runIsertionTest() {
		setupBeforeTesting();

		describeInsertTest();
		insertElements();
		printTestResult();

		cleanupAfterTesting();
	}

	void runDeletionByIndexTest(int index) {
		setupBeforeTesting();

		describeDeleteByIndexTest(index);
		insertElements();
		deleteElementByIndex(index);
		printTestResult();

		cleanupAfterTesting();
	}

	void runDeletionByValueTest(int value) {
		setupBeforeTesting();

		describeDeleteByValueTest(value);
		insertElements();
		deleteElementByValue(value);
		printTestResult();

		cleanupAfterTesting();
	}
};

