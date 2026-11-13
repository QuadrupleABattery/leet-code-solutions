/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *before_next_different(struct ListNode *list) {
	int val = list -> val;
	struct ListNode *nextNode = list;
	struct ListNode *prevNode = list;

	while (nextNode -> next != NULL) {
		nextNode = nextNode -> next;

		if (nextNode -> val != val) {
			break;
		}
		
		prevNode = nextNode;
	}

	return prevNode;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	struct ListNode *head;
	struct ListNode *tail;
	struct ListNode *lNode;
	struct ListNode *rNode;

	if (!list1) {
		return list2;
	} else if (!list2) {
		return list1;
	}

	if (list1 -> val <= list2 -> val) {
		head = list1;
		tail = head;
		list1 = list1 -> next;
	} else {
		head = list2;
		tail = head;
		list2 = list2 -> next;
	}

	while (list1 != NULL && list2 != NULL) {
		struct ListNode *nextNode;
		struct ListNode *nextDifferent;

		if (list1 -> val <= list2 -> val) {
			nextNode = list1;
			nextDifferent = before_next_different(nextNode);
			list1 = nextDifferent -> next;
		} else {
			nextNode = list2;
			nextDifferent = before_next_different(nextNode);
			list2 = nextDifferent -> next;
		}

		tail -> next = nextNode;
		tail = nextDifferent;
	}

	if (list1 == NULL) {
		tail -> next = list2;
	} else {
		tail -> next = list1;
	}

	return head;
}
