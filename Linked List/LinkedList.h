//Charles Rothbacher
//CPSC 2430 Lab 3

#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

template <typename type>
struct ListNode{
	type data;
	ListNode* next;
	void setNode(type inData) {
		data = inData;
		next = nullptr;
	}
};

template <typename type>
class LinkedList {

public:

	ListNode<type> *head;

	LinkedList<type>() {
		head = nullptr;
	}

	LinkedList<type>(type inData) {
		ListNode<type> head = ListNode<type>(inData);
		head->next = nullptr;
	}

	void appendNode(type inData) {
		ListNode<type>* newNode = new ListNode<type>;
		newNode->setNode(inData);
		ListNode<type>* p = head;
		if (p == nullptr) {
			head = newNode;
			return;
		}
		else {
			while (p->next) {
				p = p->next;
			}
			p->next = newNode;
		}
	}

	void removeNode(type inData) {
		ListNode<type>* p = head;
		ListNode<type>* q = head -> next;

		if (head->data == inData) {
			head = q;
			p->next = nullptr;
			return;
		}
		else {
			while (p != nullptr) {
				if (q->data == inData) {
					p->next = q->next;
					q->next = nullptr;
					return;
				}
				q = p;
				p = p->next;
			}

		}
	}

	void clearList() {
		ListNode<type>* p = head;
		ListNode<type>* q = head->next;
		if (head == nullptr) {
			return;
		}
		else {
			while (q != nullptr) {
				p->next = nullptr;
				p = q;
				q = q->next;
			}
			head = nullptr; //finally kill the head
			p = nullptr; //this finishes up the deletion
		}
	}

	void printNodes() {
		ListNode<type>* p = head;
		if (p == nullptr) {
			std::cout << "List is empty!";
		}
		else {
			while (p) {
				std::cout << p->data << " ";
				p = p->next;
			}
			std::cout << "\n";
		}
	}

	ListNode<type>* getHead() { //helper function for the recursive function
		return head;
	}

	void getLastNegative(ListNode<type>* p, type inData) {
		if (p == nullptr) {
			std::cout << inData << "\n";
			return;
		}
		else if (p->data < 0) {
			getLastNegative(p->next, p->data);
		}
		else {
			getLastNegative(p->next, inData);
		}
	}
};

#endif

