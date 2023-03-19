#pragma once

#include <iostream>
#include "LinkedList.h"

class InputController
{
public:
	static LinkedList<int>* askForNumbersList() {
		std::cout << "Enter number to add it to list\nEnter -1 to stop" << '\n';

		int inputNumber; std::cin >> inputNumber;
		LinkedList<int>* list = new LinkedList<int>;

		while (inputNumber != -1) {
			list->addElementToEnd(inputNumber);
			std::cin >> inputNumber;
		}

		return list;
	}

	static int askForIndexToDelete() {
		std::cout << "Enter index to delete" << '\n';
		int index; std::cin >> index;

		return index;
	}

	static int askForValueToDelete() {
		std::cout << "Enter value to delete" << '\n';
		int value; std::cin >> value;

		return value;
	}
};

