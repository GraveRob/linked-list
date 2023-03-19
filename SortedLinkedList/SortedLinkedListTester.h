#pragma once

#include "LinkedListTester.h"
#include "SortedLinkedList.h"

class SortedLinkedListTester :
    public LinkedListTester
{
protected: 
    void setupBeforeTesting() override {
        list = new SortedLinkedList();
    }

    void describeInsertTest() override {
        ConsoleLogger::printLine();
        std::cout << "Test #1: Inserting new elements\n";
        std::cout << "Output should be sorted from "; elements->printAllElements(); std::cout << '\n';
        ConsoleLogger::printLine();

        std::cout << '\n';
    }

public:
    SortedLinkedListTester() {
        list = nullptr;
        elements = nullptr;
    }

    SortedLinkedListTester(LinkedList<int>* elements) {
        list = nullptr;
        this->elements = elements;
    }

    ~SortedLinkedListTester() {
        delete list;
        delete elements;
    }

	void printTesterIsRunning() override {
		std::cout << "SORTED LINKED LIST TESTER IS RUNNING\n";
	}
};

