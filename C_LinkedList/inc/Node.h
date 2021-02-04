
#ifndef __C_NODE_H__
#define __C_NODE_H__
#endif
/*************************************************************
By Oren Yair
**************************************************************/
#define NODE_SUCCESS                    0x00000000
#define NODE_FAILED                     0x00000001


struct Node
{
	unsigned int val;
	Node* next;
};

unsigned int Node_SetVal(struct Node* node, unsigned int val);
unsigned int Node_Print(struct Node* node);