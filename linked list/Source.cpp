#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};
class link
{
private:
	node* head, * tail, * temp, * temp1;//pointers
	int key;
public:
	link()
	{
		head = temp = temp1 = NULL;
		tail = NULL;
		
	}
	void add()
	{
		if (head == NULL)
		{
			head = new node;
			cout << "enter the value for 1st node" << endl;
			cin >> head->data;
			head->next = NULL;
			return;
		}
		else
		{
			temp = head;
			while (temp != NULL)

			{

				if (temp->next == NULL)
				{


					temp1 = new node;
					cout << "Enter the value of the node :";
					cin >> temp1->data;
					temp->next = temp1;
					temp1->next = NULL;
					return;

				}
				temp = temp->next;
			}


		}
	}


	void print()
	{
		cout << endl;
		
		cout << "The Linked List you created is : ";
		if (head == NULL)
		{
			cout << "empty" << endl;

		}
		
		else
		{
			temp = head;

			while (temp != NULL)
			{
				cout << temp->data<<" ";
				temp = temp->next;

			}
		}

		cout << endl;
	}

	~link()
	{
		delete head;
	}


	void check()               // function to check the conditions required
	{
		int z;
		int m;
		temp = head;
		cout << "Enter The number whose successor you want to find : ";
		cin >> z;
		while (temp != NULL)
		{

			if (temp->data == z)              // This part checks if the input number has an immediate successor 
			{
				int v;
				int o = z;
				int max = 0;
				v = z;
				m = z + 1;
				
				temp = head;
				while (temp != NULL)
				{
					if (temp->data == m)
					{
						cout << "the next successor is :" << m << endl;
						return;
					}




					temp = temp->next;

				}
				

				temp = head;
				while (temp != NULL)
				{
					if (temp->data > v)               // this part checks the successor of the number taken as input if the number doesn't have an immediate senior
					{
						int y = temp->data;

						temp = head;

						while (temp != NULL)
						{
							if (y > temp->data && temp->data > v)
							{
								y = temp->data;


							}


							temp = temp->next;
						}
						cout << "the next successor is :" << y << endl;
						return;

					}
					
					temp = temp->next;
				}

				temp = head;
				while (temp != NULL)
				{
					if (o > temp->data)           // This part checks if the number taken as input is greatest of all in the list and thus has no successor

					{

						max = 0;
						cout << "You've chosen a max position, it has no successor thus it's :" << max << endl;
						return;
					}
					
					temp = temp->next;
				}























			}
			temp = temp->next;
		}






	}

};



int main()
{
	link a;
	char x;
	do
	{

	
	a.add();
	
	cout << "Do you want to add a new node ? (y/n) ";
	cin >> x;
	} while (x != 'n');

	a.print();

	a.check();

	system("pause");
	return 0;

}