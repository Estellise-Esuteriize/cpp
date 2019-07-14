#include <iostream>
#include <type_traits>
#include "Node.h"

using namespace std;

//struct SingleNode;
//struct DoubleNode;
//struct BaseNode;

//void push(void**, int);

//void InsertAfter(SingleNode*, SingleNode*, int);
//void InsertBefore(SingleNode*, SingleNode*, int);
//void display(SingleNode*);


 struct node_l {

	 int data;
		
	 node_l* next;
};



template <typename... Ts> using void_t = void;

template <typename T, typename = void>
struct has_typedef_foobar : false_type {};

//template <typename T>
//struct has_typedef_foobar<T, void_t<typename T::intData>> : std::true_type {};

template <typename T>
struct has_typedef_foobar<T, decltype(declval<T>().data, void())> : true_type {};

struct foo {
	float foobar;
};


int main()
{
	node_l* head = nullptr;


	Node node;

	node.push<node_l, int>(&head, 1);


	//SingleNode* node = nullptr;

	//std::cout << has_typedef_foobar<int>::value << std::endl;
	//std::cout << has_typedef_foobar<BaseNode>::value << std::endl;

	/**
	| Start Single Linked List
	*//* * /
	SingleNode* node = nullptr;

	int* pInt = new int(324);

	push((void**)&node, 1);

	push(&node, 2);

	InsertBefore(node, node->next, 8);

	InsertAfter(node, node->next, 11);

	push(&node, 3);

	InsertBefore(node, node->next, 6);

	InsertAfter(node, node->next, 13);

	push(&node, 4);

	InsertAfter(node, node->next, 15);

	display(node);

	getchar();

	/**
	| End Single Linked List
	*//* * /

	DoubleNode* dNode = nullptr;

	push(&dNode, 2);

	push(&dNode, 5);
	push(&dNode, 7);

	display(dNode);

	/**
	| Double Linked List
	*/

	return 0;
}

/** /
void InsertBefore(SingleNode* head, SingleNode* before, int data)
{

	SingleNode* newNode = new SingleNode();

	newNode->data = data;

	if (head == nullptr || head == before)
	{
		//push(&head, data);
	}
	else
	{
		
		SingleNode** node = &head;

		while (head->next != before)
		{
			if (head->next == nullptr)
			{
				std::cout << "couldn't locate node " << std::endl;

				return;
			}

			head = head->next;
		}

		node = &head;

		newNode->next = (*node)->next;

		(*node)->next = newNode;

	}
	
}

void InsertAfter(SingleNode* head, SingleNode* after, int data)
{
	
	SingleNode* newNode = new SingleNode();

	newNode->data = data;

	if (head == nullptr)
	{
		//push(&head, data);
	}
	else 
	{
		SingleNode** node = &head;

		if (head == after)
		{
			newNode->next = (*node)->next;
	
			(*node)->next = newNode;

			return;
		}

		while (head->next != after)
		{
			
			if(head->next == nullptr)
			{
				std::cout << "Null next node, could not find node" << std::endl;
				return;
			}

			head = head->next;
		}

		node = &head->next;

		newNode->next = nullptr;

		if ((*node)->next != nullptr) 
		{
			newNode->next = (*node)->next;
		}

		(*node)->next = newNode;

	}

}


void push(void** head, int data)
{

	/*SingleNode* newNode = new SingleNode();

	newNode->data = data;

	newNode->next = *head;

	if (*head == nullptr) {

		newNode->next = nullptr;

		//std::cout << "Head Node " << (*head)->data << std::endl;
	}

	*head = newNode;
	/** /

}
/* /
void push(DoubleNode** head, int data)
{

	DoubleNode* node = new DoubleNode();

	node->data = data;

	node->next = *head;

	(*head)->back = node;

	if ((*head)->next == nullptr)
	{
		node->next = nullptr;
		(*head)->back = nullptr;
	}

	*head = node;

}
* /

void display(SingleNode* node) 
{

	SingleNode* current = node;

	while (current != nullptr)
	{
		std::cout << "Data of Node : " << current->data << std::endl;

		current = current->next;
	}


}

void display(DoubleNode* node)
{

	DoubleNode* current = node;

	while (current != nullptr)
	{
		std::cout << "Data of Node : " << current->data << std::endl;

		current = current->next;
	}


}
/**/