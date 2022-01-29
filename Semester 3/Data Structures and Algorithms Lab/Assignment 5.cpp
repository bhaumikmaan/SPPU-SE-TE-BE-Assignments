/***  KNOWLEDGE IS POWER  ***/

#include<bits/stdc++.h>

using namespace std;
 
struct Node
{
    Node *left, *right;
    int data , lbit , rbit ;
};

Node *insert(Node *root, int data)
{
    Node *temp = root ;
    Node *parent = NULL ; 
    while(temp)
    {
        if(data == (temp->data))
        {
            cout << "Data already exist" ;
            return root ;
        }
        parent = temp ;  
        if(data > temp->data)
        {
        	if(temp->rbit == 0)
            {    
            	temp = temp->right ; 
            }
            else
            {
            	break ;
            }
        }
        else
        {
            if(temp->lbit == 0)
            {    
            	temp = temp->left ;
            }
            else
            {
            	break ;
            }
        }
    }
    Node *tmp = new Node;
    tmp->data = data ;
    tmp->lbit = 1 , tmp->rbit = 1 ;
    if(!parent)
    {
        root = tmp ;
        tmp->left = NULL ;
        tmp->right = NULL ;
    }
    else if(data < (parent->data))
    {
        tmp->left = parent->left ;
        tmp->right = parent ;
        parent->lbit = 0 ;
        parent->left = tmp ;
    }
    else
    {
        tmp->left = parent ;
        tmp->right = parent->right ;
        parent->rbit = 0 ; 
        parent->right = tmp ;
    }
    return root ;
}
//================== Printing ==================//
void preorder(Node* root)
{
	cout << "PREORDER TRAVERSAL\n" ;
    if(!root)
    {
        cout << "Tree is Empty" ;
        return ;
    }
    Node* temp=root;
    while(temp) 
    {
        cout << temp->data << " " ;
        while(temp->lbit == 0) 
        {		
            temp = temp->left; 
            cout << temp->data << " " ;		
        }
        while(temp->rbit == 1 && temp->right) 
        {
            temp = temp->right ;
        }	
        temp = temp->right ;		
    }
}
Node *inorderSuccessor(Node *t)
{
    if(t->rbit == 1)
    {
        return t->right ;
    }
    t = t -> right ;
    while(t -> lbit == 0)
    {
    	t = t -> left ;
    }
    return t ;
}
void inorder(Node *root)
{
	cout << "INORDER TRAVERSAL\n" ;
    if(!root)
    {
    	cout << "Tree is Empty" ;
    }
    struct Node *temp = root ;
    while(temp->lbit == 0)
    {
    	temp = temp->left ;
    } 
    while(temp)
    {
        cout << temp->data << " " ;
        temp = inorderSuccessor(temp) ;
    }
}
//================== ==================//
//====================== MAIN =====================//
void menu( )
{
	cout << "\nChoose Your Operation:\n" ;
    cout << "1.Insert Nodes\n" ;
    cout << "2.Display Tree. (PREORDER TRAVERSAL)\n" ;
    cout << "3.Display Tree. (INORDER TRAVERSAL)\n" ;
    cout << "4.Exit Program\n" ;
    cout << "Enter you choice: " ;
}
int main()
{
    Node *root = NULL ;
    while(true)
    {
    	menu() ;
        int choice ;
        cin >> choice ;
        cout << "\n" ;
        if(choice == 1)
        {
            cout<<"Enter number element to be insert : ";
            int sz ;
            cin >> sz ;
            cout << "Enter " << sz << " elements : \n" ;
            while(sz--)
            {
            	int data ;   
            	cin >> data ;
                root = insert(root , data) ;
            }
        }
        else if(choice == 2)
        {
            preorder(root);
        }
        else if(choice == 3)
        {
            inorder(root) ;
        }
        else if(choice == 4)
        {
            cout << "Thank You!" ;
            break ;
        }
        else
        {
            cout << "Invalid Choice! Please Try Again." ;
        }
    }
    return 0;
}

/***  END   ***/
