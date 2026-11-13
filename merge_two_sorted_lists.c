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

struct ListNode *next_different(struct ListNode *list) {
	int val = list -> val;
	struct ListNode *nextNode = list -> next;

	while (nextNode != NULL) {
		if (nextNode -> val == val) {
			continue;
		}

		break;
	}

	return nextNode;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	struct ListNode *head;
	struct ListNode *lNode;
	struct ListNode *rNode;

	if (list1 -> val <= list2 -> val) {
		head = list1;
	}

	while (list1 -> next != NULL && list2 -> next != NULL) {
		
	}

	return head;
}
