/***  KNOWLEDGE IS POWER  ***/

#include<iostream>
using namespace std ;
 
class Queue
{
    int front = -1 , rear = -1 , size = 0 ;
    int *arr ;
    
    public:
    void initialise(int sz)
    {
       size = sz ;
       arr = new int[sz] ;
    }
    // Function to Add an element in Circular queue 
    void insertVal(int value)
    {
        if((front == 0 && rear == size -1 ) || (rear == (front-1)%(size-1)))
        {
            cout << "Queue is full, Element can not be inserted\n" ;
            return ;
        }
        else if(front == -1) // Inserting First Element
        {
            front = 0 ;
            rear = 0 ;
            arr[rear] = value ;
        }
        else if(rear == size - 1 && front != 0)
        {
            rear = 0 ;
            arr[rear] = value ;
        }
        else
        {
            rear++ ;
            arr[rear] = value ;
        }
    }
    // Function to Delete an element in Circular queue 
    int deleteVal( )
    {
        if(front == -1)
        {
            cout << "Queue is empty, No element can be deleted\n" ;
            return -1 ;
        }
        int val = arr[front] ;
        arr[front] = -1 ;
        if(front == rear) // If queue is empty after deletion
        {
            front = -1 ;
            rear = -1 ;
        }
        else if(front == size - 1)
        {
            front = 0 ;
        }
        else
        {
            front++ ;
        }
        return val ;
    }
    // Function to Display all elements in Circular queue
    void print( )
    {
        if(front == -1) // No elements 
        {
            cout << "The size of the Queue is 0\n" ;
            return ;
        }
        cout << "The elements of the queue are : " ;
        if(rear >= front)
        {
            for(int i = front ; i <= rear ; i++)
            {
                cout << arr[i] << " " ;
            }
            cout << "\n" ;
        }
        else
        {
            int pos = front ;
            while(true)
            {
                cout << arr[pos] << " " ;
                if(pos == rear)
                {
                    break ;
                }
                pos = (pos + 1)%size ; // Reset to 0 if it exceedes size
            }
            cout << "\n" ;
        }
    }  
};
// -- 
void menu()
{
    cout << "Choose Your Operation:\n" ;
    cout << "1.Insert An Element to the queue\n" ;
    cout << "2.Delete An Element from the queue\n" ;
    cout << "3.Print the Elements in the queue\n" ;
    cout << "4.Exit Program\n" ;
    cout << "Enter you choice: " ;
}
// -- 
int main()
{
    cout << "Enter the size of the queue: " ;
    int size ;
    cin >> size ;
    Queue q ;
    q.initialise(size) ;
    while(true)
    {
        cout << "\n" ;
        menu() ;
        int choice ;
        cin >> choice ;
        if(choice == 1)
        {
            cout << "Enter the number you want to insert in the queue: ";
            int val ;
            cin >> val ;
            q.insertVal(val) ;
        }
        else if(choice == 2)
        {
            q.deleteVal() ;
        }
        else if(choice == 3)
        {
            q.print() ;
        }
        else if(choice == 4)
        {
            cout << "Thank You!" ;
            break ;
        }
        else
        {
            cout << "Invalid choice. Try Again\n" ;
        }
    }
    return 0;
}

/***  END   ***/
