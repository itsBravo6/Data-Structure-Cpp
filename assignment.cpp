#include<iostream>
using namespace std;

struct node {
	int data;
	node *left;
	node *right;
};

class BST {

private:
	node *root;

public:
    BST() {
		root = NULL;
		
	}

	bool check_left(node *temp) {
		if (temp->left == NULL) {
			return true;
		}
		else return false;
	}

	bool check_right(node *temp) {
		if (temp->right == NULL)
			return true;
		else return false;
	}

	bool is_greater(int val, int val_1) {
		if (val > val_1)
			return true;
		else return false;
	}

	node* Create(int data) {
		node *Node = new node();
		Node->data = data;
		Node->left == NULL;
		Node->right == NULL;
		return Node;
	}

	void Insertion(node *temp, int data) {
		if (root == NULL) {
			root = Create(data);
			return;
		}
		if (is_greater(temp->data, data)) {
			if (check_left(temp)) {
				temp->left = Create(data);
				return;
			}
			else Insertion(temp->left, data);

		}
		else {
			if (check_right(temp)) {
				
				temp->right = Create(data);
				temp->right->left = temp->right->right = NULL;
				return;
			}
			else Insertion(temp->right, data);
		}

	}

	node *Get_Root() {
		return root;
	}

	void print(node *temp) {
		if (temp == NULL)
			return;
		print(temp->left);
		cout << temp->data << " ";
		print(temp->right);
	}
	




 
    // ***************Part A*******************
    int count_nodes(node* iter, int val, int count=0)
 {
	 
	if (iter==NULL)
		{
			cout<<"Number not present"<<endl;
			return 0;
		}
		if (val==iter->data)
		{  
			count=count+1;
			//cout<<"Number "<<val<< " Exists"<<endl;
			
			
			
				if (iter->left!=NULL)
				{
					count= count_nodes(iter->left,val=iter->left->data,count);
				}
				
				if (iter->right!=NULL)
				{
					count = count_nodes(iter->right,val=iter->right->data,count);
				}
				
			
			return count;
		
		
		}
      
		













		if (val>iter->data)
		{
			return count_nodes(iter->right,val,count);
			
			
		
		}
		if (val<iter->data)
		{
			return count_nodes(iter->left,val,count);
			
			
		}
		

  }
 

 
 
    // ****************Part-B********************
    int left_most_node(node *root_iter)
{	if (root_iter==NULL)
	{
		return -1;
	}

	if (root_iter->left!=NULL)
	{
		int lldepth= left_most_node(root_iter->left);
		int lrdepth=left_most_node(root_iter->right);

		if (lldepth>lrdepth)
	{
		return (lldepth+1);

	}
	else {
		return (lrdepth+1);
	
	
		
	}

	}
	if (root_iter->right!=NULL)
	{
		int rldepth= left_most_node(root_iter->left);
	
		int rrdepth=left_most_node(root_iter->right);

		if (rldepth>rrdepth)
	{
		return (rldepth+1);

	}
	else {
		return (rrdepth+1);
	
	
		
	}
	}
	

	
	
} 

    


   
    // **********************PART-C********************
	void getsum (node*temp ,int &val)
	{
		if (temp==NULL)
		{
			return ;
		}
		if (temp->right!=NULL && temp->right->right==NULL && temp->right->left==NULL)
		{
			val=val+temp->right->data;
		}
		getsum(temp->left,val);
		getsum(temp->right,val);
	}


    int right_leaves(node* root_iter){
		
		int addition=0;
		
       if (root_iter==NULL)
	   {
		   return addition;
		   
	   }
		if(root_iter->right!=NULL && root_iter->right->left==NULL && root_iter->right->right==NULL)
		
		{
			addition=addition+root_iter->right->data;
		}
		
	getsum(root_iter->right,addition);
	getsum(root_iter->left,addition);
	return addition;
	}
	
 

    // *********************PART-D******************

	void diffr (node*temp,int &min,int&diff)
	{
		if (temp==NULL)
		{
			return;
		}

		if (temp->left!=NULL)
		{
			diff=temp->data-temp->left->data;
			if (min>diff)
		{
			min=diff;
		}
		 diffr(temp->left,min,diff);
		}
		if (temp->right!=NULL)
		{
			diff=temp->right->data - temp->data;
			if (min>diff)
		{
			min=diff;
		}
		 diffr(temp->right,min,diff);
		}
			
	}
    int min_diff(node *root_iter,int diff=0)
	{
       
	    
		int mindiff=root->data;
		
		

		if (root_iter==NULL)
		{
			return mindiff;
		}

		if (root_iter->left != NULL)
			{
				diff = root_iter->data - root_iter->left->data; 
				
				
				
				diffr(root_iter,mindiff,diff);
				
				
			}
			
			
		
				

			if (root_iter->right != NULL)
			{
				 diff=root_iter->right->data-root_iter->data;
				 
				
			diffr(root_iter,mindiff,diff);
				
			}
		
		
		return mindiff;

    }

 
};

int main() {
	BST bst;
	bst.Insertion(bst.Get_Root(), 8);
    bst.Insertion(bst.Get_Root(), 5);
    bst.Insertion(bst.Get_Root(), 6);
    bst.Insertion(bst.Get_Root(), 20);
    bst.Insertion(bst.Get_Root(), 10);
    bst.Insertion(bst.Get_Root(), 12);
    bst.print(bst.Get_Root());
	cout<<"\n";
	cout<< "OUTPUT TASK 1:"<<bst.count_nodes(bst.Get_Root(),8,0)<<endl;
	cout<<"OUTPUT TASK 2: "<<bst.left_most_node(bst.Get_Root())<<endl;
   cout<<"OUTPUT TASK 3:"<<bst.right_leaves(bst.Get_Root())<<endl;
	cout<<"OUTPUT TASK 4:"<<bst.min_diff(bst.Get_Root())<<endl;
}