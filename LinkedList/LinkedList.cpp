#include <iostream>


struct SingleNode;

void push(SingleNode**, int);
void InsertAfter(SingleNode*, SingleNode*, int);
void InsertBefore(SingleNode*, SingleNode*, int);
void display(SingleNode*);

void whileTest();
void test(int*);

struct SingleNode {

	int data;

	SingleNode* next;

};



int i = 0;
int main()
{
	SingleNode* node = nullptr;

	push(&node, 1);

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
}

void InsertBefore(SingleNode* head, SingleNode* before, int data)
{

	SingleNode* newNode = new SingleNode();

	newNode->data = data;

	if (head == nullptr || head == before)
	{
		push(&head, data);
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
		push(&head, data);
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



void push(SingleNode** head, int data)
{

	SingleNode* newNode = new SingleNode();
	
	newNode->data = data;

	newNode->next = *head;

	if (*head == nullptr) {
		
		newNode->next = nullptr;

		//std::cout << "Head Node " << (*head)->data << std::endl;
	}

	*head = newNode;

}


void display(SingleNode* node) 
{

	SingleNode* current = node;

	while (current != nullptr)
	{
		std::cout << "Data of Node : " << current->data << std::endl;

		current = current->next;
	}


}