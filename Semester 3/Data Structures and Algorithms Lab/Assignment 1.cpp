/***  KNOWLEDGE IS POWER  ***/

#include<iostream>
#include<string>
using namespace std;

struct node
{
    char opr ;
    node* next ;
};

class stack
{
    node* top ;
    public:
        stack( ) // Initialisation
        {
            top = NULL ;
        }
        bool empty()
        {
            if(top == NULL) // No element added
            {
                return true ;
            }
            return false ;
        }
        
        void push(char c)
        {
            node *n ;
            n = new node ;
            n->opr = c ; // Assign value 
            n->next = top ; // Assign address of previous top
            top = n ; // Change this new node to top
        }
        
        char pop() // Pops element and also returns top value
        {
            if(!empty())
            {
                node *n ;
                n = new node ;
                n = top ;
                top = top->next ;
                char top_value = n->opr ;  
                delete n ;
                return top_value ;
            }
            else
            {
                return 0 ;
            }
        }
        char topchar( )
        {
            if(!empty())
            {
                node *n ;
                n = new node ;
                n = top ;
                char top_value = n->opr ;  
                return top_value ;
            }
            else
            {
                return 0 ;
            }
        }
};

// --- --- //
int findPrecedence(char ch)
{
    if(ch == '*' || ch == '/') // Highest Precedence
    {
        return 2 ;
    }
    else if(ch == '+' || ch == '-')
    {
        return 1 ;
    }
    return -1 ;
}

// --- CONVERSION --- //

string infixToPostfix(string expression)
{
    stack s ;
    char t ; // char value of top
    string ans = "" ;
    for(int i = 0 ; i < expression.length() ; i++)
    {
        char val = expression[i] ;
        if(isalnum(val)) // Operand
        {
            ans += val ;
        }
        else
        {
            if(val == '(')
            {
                s.push(val) ;
            }
            else
            {
                if(val == ')')
                {
                    while((t = s.pop()) != '(')
                    {
                        ans += t ;
                    }
                }
                else // Operator
                {
                    t = s.topchar() ;
                    while(!s.empty() && findPrecedence(val) <= findPrecedence(t))
                    {
                        t = s.pop() ;
                        ans += t ;
                    }
                    s.push(val) ; // Add element of higher Precedence
                }
            }
        }
    }
    while(!s.empty())
    {
        t = s.pop() ;
        ans += t ;
    }
    return ans ;
}
string infixToPrefix(string expression)
{
	reverse(expression.begin() , expression.end()) ;
	string s = infixToPostfix(expression) ;
	reverse(s.begin() , s.end()) ;
	return s ;
}
// -- 
void menu()
{
    cout << "\nChoose Your Operation:\n" ;
    cout << "1.Infix to Prefix\n" ;
    cout << "2.Infix to Postfix\n" ;
    cout << "3.Exit Program\n" ;
    cout << "Enter you choice: " ;
}
// -- 
// --- MAIN --- //
int main()
{
    string infix  ;
    while(true)
    {
        menu() ;
        int choice ;
        cin >> choice ;
        if(choice == 1)
        {
            cout << "Enter the Infix expression : " << "\n" ;
            cin >> infix ;
        	cout << "\nPrefix Expression is: " << infixToPrefix(infix) ;
        }
        else if(choice == 2)
        {
            cout << "Enter the Infix expression : " << "\n" ;
            cin >> infix ;
        	cout << "\nPostfix Expression is: " << infixToPostfix(infix) ;
        }
        else if(choice == 3)
        {
            cout << "Thank You!" ;
            break ;
        }
        else
        {
            cout << "Invalid choice. Try Again\n" ;
        }
    }
    return 0 ;
}

/***  END   ***/
