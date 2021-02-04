
#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__
#endif

#include "Node.h"
#define LINKED_LIST_SUCCESS                    0x00000000
#define LINKED_LIST_ERROR_FAILED_ADDING_ITEM   0x00000001
#define LINKED_LIST_ERROR_FAILED_REMOVING_ITEM 0x00000002

struct LinkedList
{
	struct Node* head;
};
unsigned int LinkedList_Init(struct LinkedList* linked_list);
unsigned int LinkedList_AddItem(struct LinkedList* linked_list, struct Node* item);
unsigned int LinkedList_RemoveItem(struct LinkedList* linked_list, struct Node* item);
unsigned int LinkedList_Print(struct LinkedList* linked_list);
unsigned int LinkedList_AppendItem(struct LinkedList* linked_list, struct Node* item);
unsigned int LinkedList_PrependItem(struct LinkedList* linked_list, struct Node* item);