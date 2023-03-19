#include <iostream>
#include "SortedLinkedListTester.h"
#include "InputController.h"

int main() {
	LinkedList<int>* elementsForTesting = InputController::askForNumbersList();
	int indexToDelete = InputController::askForIndexToDelete();
	int valueToDelete = InputController::askForValueToDelete();

	LinkedListTester* linkedListTester = new LinkedListTester(elementsForTesting);
	linkedListTester->printTesterIsRunning();
	linkedListTester->runIsertionTest();
	linkedListTester->runDeletionByIndexTest(indexToDelete);
	linkedListTester->runDeletionByValueTest(valueToDelete);

	SortedLinkedListTester* sortedLinkedListTest = new SortedLinkedListTester(elementsForTesting);
	sortedLinkedListTest->printTesterIsRunning();
	sortedLinkedListTest->runIsertionTest();
	sortedLinkedListTest->runDeletionByIndexTest(indexToDelete);
	sortedLinkedListTest->runDeletionByValueTest(valueToDelete);

	return 0;
}

