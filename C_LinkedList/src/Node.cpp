#include <stdio.h>
#include "Node.h"

/*************************************************************
Node_SetVal: Set the value of the node
Parameters:
linked_list - pointer to the node
Return Value:
LINKED_LIST_SUCCESS
**************************************************************/
unsigned int Node_SetVal(struct Node* node, unsigned int val)
{
	if (node != NULL)
	{
		node->val = val;
	}
	return NODE_SUCCESS;
}

/*************************************************************
Node_Print: Prints the node value
Parameters:
linked_list - pointer to the node
Return Value:
LINKED_LIST_SUCCESS
**************************************************************/
unsigned int Node_Print(struct Node* node)
{
	if (node == NULL)
	{
		printf("[NULL]");
	}
	else
	{
		printf("[%u]", node->val);
	}
	return NODE_SUCCESS;
}
