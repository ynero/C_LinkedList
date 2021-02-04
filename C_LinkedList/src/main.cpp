
#include <stdio.h>
#include "LinkedList.h"

/*************************************************************
By Oren Yair
Simple main to test the implementation
**************************************************************/
int main()
{
	struct LinkedList ll;
	struct Node node1;
	struct Node node2;
	struct Node node3;
	struct Node node4;
	struct Node node5;
	struct Node node6;
	struct Node node7;
	struct Node node8;
	struct Node node9;
	Node_SetVal(&node1, 5);
	Node_SetVal(&node2, 3);
	Node_SetVal(&node3, 7);
	Node_SetVal(&node4, 4);
	Node_SetVal(&node5, 1);
	Node_SetVal(&node6, 5);
	Node_SetVal(&node7, 8);
	Node_SetVal(&node8, 7);
	Node_SetVal(&node9, 10);
	LinkedList_Init(&ll);
	LinkedList_AddItem(&ll, &node1);
	LinkedList_AddItem(&ll, &node2);
	LinkedList_AddItem(&ll, &node3);
	LinkedList_AddItem(&ll, &node4);
	LinkedList_AddItem(&ll, &node5);
	LinkedList_AddItem(&ll, &node6);
	LinkedList_AddItem(&ll, &node7);
	LinkedList_AddItem(&ll, &node8);
	LinkedList_AddItem(&ll, &node9);
	LinkedList_Print(&ll);
	printf("item to remove");
	Node_Print(&node8);
	printf("\n");
	LinkedList_RemoveItem(&ll, &node8);
	printf("item to remove");
	Node_Print(&node5);
	printf("\n");
	LinkedList_RemoveItem(&ll, &node5);
	LinkedList_Print(&ll);
	return 0;
}