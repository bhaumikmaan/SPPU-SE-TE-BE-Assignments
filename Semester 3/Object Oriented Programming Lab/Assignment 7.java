/***  KNOWLEDGE IS POWER  ***/

import java.util.*;

class Examine
{
    private
    static int count = 0 ;  // For counting whenever condition is satisfied
    ArrayList<Integer> satisfiedind = new ArrayList<Integer>() ; // For Index of elements [Even || Prime Elements]
    ArrayList<Integer> satisfiednum = new ArrayList<Integer>() ; // For Even || Prime
    ArrayList<Integer> satisfiedind2 = new ArrayList<Integer>() ; // For Index of elements [odd || Non Prime elements]
    ArrayList<Integer> satisfiednum2 = new ArrayList<Integer>() ; // For odd || Non Prime elements
    ArrayList<String> satisfiedstr = new ArrayList<String>() ; // For Palindrome
    public
    void EvenOrOdd(int n, int ind)  // Check whether number is even or odd
    {
        if(n%2 == 0 || n == 0)
        {
            satisfiednum.add(n) ; // Add element to ArrayList [Even]
            satisfiedind.add(ind) ; // Add index to ArrayList [Even]
            count++ ;  // count for even number increments by 1.
        }
        else
        {
            satisfiednum2.add(n) ; // Add element to ArrayList [Odd]
            satisfiedind2.add(ind) ; // Add index to ArrayList [Odd]
        }
    }

    void isPrime(int n , int ind)  // Check whether number is prime or not
    {
        boolean flag = true ; // Assuming the number is prime || Change to false if condition has failed and number is not prime.
        if(n <= 1) // Corner Case
        {
            flag = false ;
        }
        for(int i = 2 ; i < n ; i++)
        {
            if(n%i == 0)
            {
                flag = false ; // Factor has been found
                break ;
            }
        }
        if(flag)
        {
            satisfiednum.add(n) ; // Add element to ArrayList [Prime]
            satisfiedind.add(ind) ; // Add index to ArrayList [Prime]
            count++ ;
        }
        else
        {
            satisfiednum2.add(n) ; // Add element to ArrayList [Non-Prime]
            satisfiedind2.add(ind) ; // Add index to ArrayList [Non-Prime]
        }
    }
    void isPalindrome(String s , int ind)  // Check if string is palindrome or not
    {
        StringBuilder s1 = new StringBuilder(s);  // StringBuilder collection
        if(s.equals(s1.reverse().toString()))  // Check if string palindrome
        {
            satisfiedstr.add(s) ; // Add element to ArrayList
            satisfiedind.add(ind) ; // Add index to ArrayList
            count++ ;  // increment count for palindrome strings
        }
        else
        {
            // Non Palindromic string
        }
    }
    void countoddeven()  //method to take array input and print results for even/odd or prime
    {
        // Clear arraylist for new elements
        satisfiednum.clear() ;
        satisfiedind.clear() ;
        satisfiednum2.clear() ;
        satisfiedind2.clear() ;
        //--------------------------------
        ArrayList<Integer> array = new ArrayList<Integer>();  // Declaring ArrayList collection with Integer generic type
        Scanner input = new Scanner(System.in) ;
        System.out.print("\nEnter number of integers: ") ;
        int size = input.nextInt();
        int n ;
        System.out.print("\nEnter " + size + " integer elements: ");
        count = 0;
        for(int i = 0; i < size; i++)
        {
            n = input.nextInt() ;
            array.add(n);
        }
        Iterator<Integer> it = array.iterator() ;  //iterator through the ArrayList
        int index = 1 ;
        while(it.hasNext())
        {
            EvenOrOdd((int)it.next() , index);
            index++ ;
        }
        System.out.print("\nNo. of Even elements are: "+count+"\nNo. of Odd elements are: "+(size - count)) ;
        System.out.print("\nEven elements are:" ) ;
        int satisfiedsize = satisfiednum.size() ; // Size for index and integer array is same [EVEN]
        for(int i = 0 ; i < satisfiedsize ; i++)
        {
            System.out.print("\nIndex is: " + satisfiedind.get(i) + " And Element is: " + satisfiednum.get(i)) ;
        }
        System.out.print("\nOdd elements are:" ) ;
        int satisfiedsize2 = satisfiednum2.size() ; // Size for index and integer array is same [ODD]
        for(int i = 0 ; i < satisfiedsize2 ; i++)
        {
            System.out.print("\nIndex is: " + satisfiedind2.get(i) + " And Element is: " + satisfiednum2.get(i)) ;
        }
    }
    void countprimenonprime()  //method to take array input and print results for even/odd or prime
    {
        // Clear arraylist for new elements
        satisfiednum.clear() ;
        satisfiedind.clear() ;
        satisfiednum2.clear() ;
        satisfiedind2.clear() ;
        //--------------------------------
        ArrayList<Integer> array = new ArrayList<Integer>();  // Declaring ArrayList collection with Integer generic type
        Scanner input = new Scanner(System.in);
        System.out.print("\nEnter number of integers: ");
        int size = input.nextInt();
        int n ;
        System.out.print("\nEnter " + size + " integer elements: ");
        count = 0;
        for(int i = 0; i < size; i++)
        {
            n = input.nextInt();
            array.add(n);
        }
        int index = 1 ;
        Iterator<Integer> it = array.iterator() ;  //iterator through the ArrayList
        while(it.hasNext())
        {
            isPrime((int)it.next() , index);
            index++ ;
        }
        System.out.print("\nNo. of Prime elements are: "+count+"\nNo. of Non-Prime elements are: "+(size - count)) ;
        System.out.print("\nPrime elements are:" ) ;
        int satisfiedsize = satisfiednum.size() ; // Size for index and integer array is same [Prime]
        for(int i = 0 ; i < satisfiedsize ; i++)
        {
            System.out.print("\nIndex is: " + satisfiedind.get(i) + " And Element is: " + satisfiednum.get(i)) ;
        }
        System.out.print("\nNon-Prime elements are:" ) ;
        int satisfiedsize2 = satisfiednum2.size() ; // Size for index and integer array is same [Non-Prime]
        for(int i = 0 ; i < satisfiedsize2 ; i++)
        {
            System.out.print("\nIndex is: " + satisfiedind2.get(i) + " And Element is: " + satisfiednum2.get(i)) ;
        }
    }

    void countpalindrome()
    {
        // Clear arraylist for new elements
        satisfiedstr.clear() ;
        satisfiedind.clear() ;
        ArrayList<String> array = new ArrayList<String>();  // Declaring ArrayList collection with String generic type
        Scanner input = new Scanner(System.in);
        System.out.print("\nEnter Number of strings : ");
        int size = input.nextInt();
        String str ;
        System.out.print("\nEnter "+size+" strings (with spaces): ");
        count = 0 ;
        for(int i = 0; i < size; i++)
        {
            str = input.next() ;
            array.add(str);
        }
        int index = 1 ;
        Iterator<String> it = array.iterator() ;  // Iterator through the ArrayList
        while(it.hasNext())
        {
            isPalindrome((String)it.next() , index);
            index++ ;
        }
        System.out.print("\n\nNo. of Palindrome string are: " + count);
        System.out.print("\nPalindrome strings are:" ) ;
        int satisfiedsize = satisfiedstr.size() ; // Size for index and string array is same
        for(int i = 0 ; i < satisfiedsize ; i++)
        {
            System.out.print("\nIndex is: " + satisfiedind.get(i) + " And Element is: " + satisfiedstr.get(i)) ;
        }
    }
}

public class Main
{
    public static void menu()
    {
        System.out.println("\n============================================================") ;
        System.out.println("1. Count number of even and odd") ;
        System.out.println("2. Count number of primes and non-primes") ;
        System.out.println("3. Count the number of Palindrome and Non-palindrome strings") ;
        System.out.println("4. Exit")  ;
        System.out.println("============================================================") ;
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in) ;
        Examine check = new Examine() ;
        while(true)
        {
            menu() ;
            System.out.println("Please enter your choice: ") ;
            int choice ;
            choice = sc.nextInt() ;

            if(choice == 1)
            {
                // Odd or even
                check.countoddeven( ) ;
            }
            else if(choice == 2)
            {
                // Prime or non prime
                check.countprimenonprime( ) ;
            }
            else if(choice == 3)
            {
                // Palindrome or non palindrome
                check.countpalindrome( ) ;

            }
            else if(choice == 4)
            {
                System.out.println("Thank you") ;
                break ;
            }
            else
            {
                System.out.println("Invalid choice. Please Try again") ;
            }
        }
    }
}
/***  END  ***/
