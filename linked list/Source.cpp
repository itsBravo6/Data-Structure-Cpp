#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

class linkedlist
{
public:
	node* head;

	linkedlist()
	{
		head = NULL;

	}

	void add(int x)
	{
		if (head == NULL)
		{
			head = new node;
			head->data = x;
			head->next = NULL;
			return;

		}
		else
		{
			node* temp = NULL;
			temp = head;
			while (temp != NULL)
			{
				if (temp->next == NULL)
				{
					node* temp1 = new node;
					temp1->data = x;
					temp1->next = NULL;
					temp->next = temp1;
					return;

				}
				temp = temp->next;
			}
			
			
		}
	}

	void print(node* head,int i)
	{
		
		cout << endl;

		
		if (head == NULL)
		{
		
			cout << "no of elements in linked list are : " << i << endl;

		}

		else
		{
			i++;
			cout << head->data << " ";

			print(head->next,i);
			cout << head->data << " "; 
			
		}

		
	}
};

int main()
{
	linkedlist A;

	A.add(1); 
	A.add(2);
	A.add(3);
	A.add(4);
	A.add(5);
	A.add(6);
	A.add(7);

	A.print(A.head,0);

	
}