
#include <stdio.h>
#include "LinkedList.h"
/*************************************************************
By Oren Yair
**************************************************************/
/*************************************************************
LinkedList_RemoveItem: private function for inserting a node
Memory is not being allocated or relased by this function
Parameters :
curr_item - the item in the list that new item will be appended to
item - item to insert
Return Value :
None
* *************************************************************/
static void LinkedList_RemoveItem(struct Node** curr_item, struct Node* item)
{
	if (curr_item && *curr_item && item)
	{
		(*curr_item)->next = (*curr_item)->next->next;
	}
}

/*************************************************************
LinkedList_RemoveHead: private function for inserting the head node
Memory is not being allocated or relased by this function
Parameters:
curr_item - the item in the list that new item will be appended to
item - item to insert
Return Value:
None
**************************************************************/
static void LinkedList_RemoveHead(struct LinkedList* ll, struct Node* item)
{
	if (ll && item)
	{
		ll->head = ll->head->next;
	}
}

/*************************************************************
LinkedList_InsertItem: private function for inserting a node
Memory is not being allocated or relased by this function
Parameters:
curr_item - the item in the list that new item will be appended to
item - item to insert
Return Value:
None
**************************************************************/
static void LinkedList_InsertItem(struct Node** curr_item, struct Node* item)
{
	if (curr_item && *curr_item && item)
	{
		struct Node* prev = (*curr_item)->next;
		(*curr_item)->next = item;
		(*curr_item)->next->next = prev;
	}
}

/*************************************************************
LinkedList_InsertHead: private function for inserting the head node
Memory is not being allocated or relased by this function
Parameters:
curr_item - the item in the list that new item will be appended to
item - item to insert
Return Value:
None
**************************************************************/
static void LinkedList_InsertHead(struct LinkedList* ll, struct Node* item)
{
	if (ll && item)
	{
		struct Node* prev = ll->head;
		ll->head = item;
		ll->head->next= prev;
	}
}

/*************************************************************
LinkedList_Init: Initialize or reset list
Memory is not being allocated or relased by this function
Parameters:
linked_list - pointer to the linked list (memory must be allocated)
Return Value:
LINKED_LIST_SUCCESS
**************************************************************/
unsigned int LinkedList_Init(struct LinkedList* linked_list)
{
	linked_list->head = NULL;
	return LINKED_LIST_SUCCESS;
}

/*************************************************************
LinkedList_AppendItem: add item to the end of the list
Parameters:
linked_list - pointer to the linked list (memory must be allocated)
item - pointer to the item to add (memory must be allocated)
Return Value:
LINKED_LIST_SUCCESS
LINKED_LIST_ERROR_FAILED_ADDING_ITEM
**************************************************************/
unsigned int LinkedList_AppendItem(struct LinkedList* linked_list, struct Node* item)
{
	if (linked_list == NULL || item == NULL)
	{
		return LINKED_LIST_ERROR_FAILED_ADDING_ITEM;
	}
	else
	{
		struct Node* curr = linked_list->head;
		if (curr == NULL)
		{
			LinkedList_InsertHead(linked_list, item);
			return LINKED_LIST_SUCCESS;
		}
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		LinkedList_InsertItem(&curr, item);
	}
	return LINKED_LIST_SUCCESS;
}


/*************************************************************
LinkedList_PrependItem: add item to the begining of the list
Parameters:
linked_list - pointer to the linked list (memory must be allocated)
item - pointer to the item to add (memory must be allocated)
Return Value:
LINKED_LIST_SUCCESS
LINKED_LIST_ERROR_FAILED_ADDING_ITEM
**************************************************************/
unsigned int LinkedList_PrependItem(struct LinkedList* linked_list, struct Node* item)
{
	if (linked_list == NULL || item == NULL)
	{
		return LINKED_LIST_ERROR_FAILED_ADDING_ITEM;
	}
	LinkedList_InsertHead(linked_list, item);
	return LINKED_LIST_SUCCESS;
}


/*************************************************************
LinkedList_AddItem: add item sorted according to val
Parameters:
linked_list - pointer to the linked list (memory must be allocated)
item - pointer to the item to add (memory must be allocated)
Return Value:
LINKED_LIST_SUCCESS
LINKED_LIST_ERROR_FAILED_ADDING_ITEM
**************************************************************/
unsigned int LinkedList_AddItem(struct LinkedList* linked_list, struct Node* item)
{
	if (linked_list == NULL || item == NULL)
	{
		return LINKED_LIST_ERROR_FAILED_ADDING_ITEM;
	}

	if (linked_list->head == NULL)
	{
		LinkedList_InsertHead(linked_list, item);
		return LINKED_LIST_SUCCESS;
	}
	struct Node* curr = linked_list->head;
	if (linked_list->head != NULL && linked_list->head->val > item->val)
	{
		LinkedList_InsertHead(linked_list, item);
		return LINKED_LIST_SUCCESS;
	}

	while (curr->next != NULL)
	{
		if (curr->next->val <= item->val)
		{
			curr = curr->next;
			continue;
		}
		else 
		{
			LinkedList_InsertItem(&curr, item);
			return LINKED_LIST_SUCCESS;
		}
	}
	LinkedList_InsertItem(&curr, item);
	return LINKED_LIST_SUCCESS;
}

/*************************************************************
LinkedList_RemoveItem: remove all occurances of item from the list according to val
Parameters:
linked_list - pointer to the linked list (memory must be allocated)
item - pointer to the item to remove (memory must be allocated)
Return Value:
LINKED_LIST_SUCCESS
LINKED_LIST_ERROR_FAILED_ADDING_ITEM
**************************************************************/
unsigned int LinkedList_RemoveItem(struct LinkedList* linked_list, Node* item)
{
	if (linked_list == NULL || item == NULL || linked_list->head == NULL)
	{
		return LINKED_LIST_ERROR_FAILED_ADDING_ITEM;
	}

	struct Node* curr = linked_list->head;
	if (linked_list->head->val == item->val)
	{
		LinkedList_RemoveHead(linked_list, item);
	}

	while (curr->next != NULL)
	{
		if (curr->next->val == item->val)
		{
			LinkedList_RemoveItem(&curr, item);
		}
		else
		{
			curr = curr->next;
		}
	}
	return LINKED_LIST_SUCCESS;
}

/*************************************************************
LinkedList_Print: Print the linnked list from head to tail
Parameters:
linked_list - pointer to the linked list to print
Return Value:
LINKED_LIST_SUCCESS
**************************************************************/
unsigned int LinkedList_Print(struct LinkedList* linked_list)
{
	if (linked_list == NULL)
	{
		printf("[NULL]\n");
	}
	else 
	{
		struct Node* curr = linked_list->head;
		while (curr != NULL)
		{
			Node_Print(curr);
			printf("->");
			curr = curr->next;
		}
		printf("[NULL]\n");
	}
	return LINKED_LIST_SUCCESS;
}
