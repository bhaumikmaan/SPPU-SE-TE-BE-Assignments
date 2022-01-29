/***  KNOWLEDGE IS POWER  ***/

#include<bits/stdc++.h>
using namespace std;

//=======================================//

struct Node {
    char data ;
    struct Node *left, *right ;
} ;

Node* newNode(char val) // Assigning value to a newly created node
{
    Node *temp = new Node ;
    temp->left = temp->right = NULL ;
    temp->data = val ;
    return temp ;
};

bool isOperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
    	return true ;
    }
    return false ;
}
//=======================================//
//========== NON-RECURSIVE ==========//
void inorder_withoutRec(Node* t)
{
    Node* temp = t ;
    stack<Node*> s ;
    while(temp)
    {
        s.push(temp) ;
        temp = temp->left ;
    }
    while(!s.empty())
    {
        temp = s.top() ;
        s.pop() ;
        cout << " " << temp->data ;
        temp = temp->right ;
        while(temp)
        {
            s.push(temp) ;
            temp = temp->left ;
        }
    }
}

void preorder_withoutRec(Node* t)
{
    Node* temp = t ;
    stack<Node*> s ;
    while(temp)
    {
        cout << " " << temp->data ;
        s.push(temp) ;
        temp = temp->left ;
    }
    while(!s.empty())
    {
        temp = s.top() ;
        s.pop() ;
        temp = temp->right ;
        while(temp)
        {
            cout << " " << temp->data ;
            s.push(temp) ;
            temp = temp->left ;
        }
    }
}

void postorder_withoutRec(Node* t)
{
    Node *t1, *temp = t ;
    stack<Node*> s, s1 ;
    while(temp)
    {
        s.push(temp) ;
        s1.push(NULL) ;
        temp = temp->left ;
    }
    while(!s.empty())
    {
        temp = s.top() ;
        s.pop() ;
        t1 = s1.top() ;
        s1.pop() ;
        if(t1 == NULL)
        {
            s.push(temp) ;
            s1.push((Node*)1) ;
            temp = temp->right ;
            while(temp)
            {
                s.push(temp) ;
                s1.push(NULL) ;
                temp = temp->left ;
            }
        }
        else
        {
        	cout << " " << temp->data ; 
        }       
    }     
}
//=======================================//


//========== PRINTING ==========//
// Preoder
void printPreorder(Node* node)
{
    if(node != NULL)
    {
        // Printing the data of node
        cout << node->data << " " ;
        // Using recursion to left and right
        printPreorder(node->left) ;
        printPreorder(node->right) ;
    }
}

// Postorder
void printPostorder(Node* node)
{
    if(node != NULL)
    {
        // Using recursion first on left and then on right
        printPostorder(node->left) ;
        printPostorder(node->right) ;
        // Now print the data of node
        cout << node->data << " ";
    }
}

// Inorder/infix
void printInorder(Node* node)
{
    if(node != NULL)
    {
        // Using recursion on the left
        printInorder(node->left) ;
        // then printing the data of node
        cout << node->data << " " ;
        // Now using recursion on the left
        printInorder(node->right) ;
    }
}
//=======================================//

//============ CONSTRUCTION OF TREE ============//	
class ExpressionTree{
	public:
	
      stack<Node*> st ;
      Node *t, *t1, *t2 ;
      Node *top ;
	void constructTree(string exp)
	{
	    // stack<Node*> st ;
	    // Node *t, *t1, *t2 ;
	 
	    // Traverse through every character of input expression
	    for(int i = 0 ; i < (int)exp.length() ; i++)
	    {
	        // If operand is character push into stack
	        if (!isOperator(exp[i]))
	        {
	            t = newNode(exp[i]) ;
	            st.push(t) ;
	        }
	        else
	        {
	            t = newNode(exp[i]) ;
	            t1 = st.top() ;
	            st.pop() ;
	            t2 = st.top() ;
	            st.pop() ;
	 			// Adding them as children
              t->right = t1 ;
	            t->left = t2 ;
	            // Adding to stack
	            st.push(t);
	        }
	    }
	 
	    //  only element will be root of expression tree
	    top = st.top() ;
	}
	void constructTreePre(string exp)
	{
	    reverse(exp.begin() , exp.end()) ;
	    // stack<Node*> st ;
	    // Node *t, *t1, *t2 ;
	 
	    // Traverse through every character of input expression
	    for(int i = 0 ; i < (int)exp.length() ; i++)
	    {
	        // If operand is character push into stack
	        if (!isOperator(exp[i]))
	        {
	            t = newNode(exp[i]) ;
	            st.push(t) ;
	        }
	        else
	        {
	            t = newNode(exp[i]) ;
	            t1 = st.top() ;
	            st.pop() ;
	            t2 = st.top() ;
	            st.pop() ;
	 			// Adding them as children
              t->left = t1 ;
	            t->right = t2 ;
	            // Adding to stack
	            st.push(t);
	        }
	    }
	 
	    //  only element will be root of expression tree
	    top = st.top() ;
	}
};

//------------------------ MENU ------------------------//
void menu( )
{
    cout << "Choose Your Operation:\n" ;
    cout << "1.Enter a prefix expression\n" ;
    cout << "2.Enter a postfix expression\n" ;
    cout << "3.Exit Program\n" ;
    cout << "Enter you choice: " ;
}
void prefixmenu()
{
    cout << "Choose Your Operation:\n" ;
    cout << "1.Get the postfix expression with recursion\n" ;
    cout << "2.Get the infix expression with recursion\n" ;
    cout << "3.Get the postfix expression without recursion\n" ;
    cout << "4.Get the infix expression without recursion\n" ;
    
}
void postmenu()
{
	cout << "Choose Your Operation:\n" ;
    cout << "1.Get the prefix expression with recursion\n" ;
    cout << "2.Get the infix expression with recursion\n" ;
    cout << "3.Get the prefix expression without recursion\n" ;
    cout << "4.Get the infix expression without recursion\n" ;
}
//------------------------ END MENU ------------------------//

int main( )
{
	while(true)
	{
		menu() ;
    ExpressionTree tree ; 
		int choice ;
		cin >> choice ;
		if(choice == 1) // Prefix to Postfix || Infix
		{
			cout << "Enter Your Prefix Expression: " ;
			string exp ;
			cin >> exp ;
			tree.constructTreePre(exp) ;
			prefixmenu() ;
			int choice2 ;
			cin >> choice2 ;
			if(choice2 == 1)
			{
				cout << "The postfix expression is:\n" ;
				printPostorder(tree.top) ;
				cout << "\n" ;
			}
			else if(choice2 == 2)
			{
				cout << "The infix expression is:\n" ;
				printInorder(tree.top) ;
				cout << "\n" ;
			}
			else if(choice2 == 3)
			{
				cout << "The postfix expression without recursion is:\n" ;
				postorder_withoutRec(tree.top) ;
				cout << "\n" ;
			}
			else if(choice2 == 4)
			{
				cout << "The infix expression without recursion is:\n" ;
				inorder_withoutRec(tree.top) ;
				cout << "\n" ;
			}
		}
		else if(choice == 2)
		{
			cout << "Enter Your Postfix Expression: " ;
			string exp ;
			cin >> exp ;
			tree.constructTree(exp) ;
			postmenu() ;
			int choice2 ;
			cin >> choice2 ;
			if(choice2 == 1)
			{
				cout << "The prefix expression is:\n" ;
				printPreorder(tree.top) ;
				cout << "\n" ;
			}
			else if(choice2 == 2)
			{
				cout << "The infix expression is:\n" ;
				printInorder(tree.top) ;
				cout << "\n" ;
			}
			else if(choice2 == 3)
			{
				cout << "The prefix expression without recursion is:\n" ;
				preorder_withoutRec(tree.top) ;
				cout << "\n" ;
			}
			else if(choice2 == 4)
			{
				cout << "The infix expression without recursion is:\n" ;
				inorder_withoutRec(tree.top) ;
				cout << "\n" ;
			}
		}
		else if(choice == 3)
		{
			cout << "Thank you!" ;
			break ;
		}
		else
		{
			cout << "Invalid choice, please try again" ;
		}
	}
	return 0 ;
}

/***  END   ***/
