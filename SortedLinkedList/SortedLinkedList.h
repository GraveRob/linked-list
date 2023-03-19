#pragma once
#include "LinkedList.h"

class SortedLinkedList :
    public LinkedList<int>
{
public:
    void addElement(int element) override {
        size += 1;
        Node<int>* nodeToAdd = new Node<int>(element);
        Node<int>* current;
        if (head == nullptr || head->data >= nodeToAdd->data) {
            nodeToAdd->next = head;
            head = nodeToAdd;
        }
        else {
            current = head;
            while (current->next != nullptr && current->next->data < nodeToAdd->data) {
                current = current->next;
            }
            nodeToAdd->next = current->next;
            current->next = nodeToAdd;
        }
    }
};

