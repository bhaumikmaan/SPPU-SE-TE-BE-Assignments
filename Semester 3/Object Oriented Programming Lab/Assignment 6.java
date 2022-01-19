/***  KNOWLEDGE IS POWER  ***/

import java.util.*;

public class Main
{
    public static void menu()
    {
        System.out.println("\n----------------------------------------------------------------- ") ;
        System.out.println("\nChoose Your Operation: ") ;
        System.out.println("\n1. Find the Element in the given Array [Enter Index]: ") ;
        System.out.println("\n2. Division of two numbers [Enter dividend and divisior]: ") ;
        System.out.println("\n3. Exit the Program: ") ;
        System.out.println("\nPlease enter your choice: ") ;
        System.out.println("\n----------------------------------------------------------------- ") ;
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in) ;
        // PREPARING THE DATA
        int size ;
        System.out.println("Insert the size of array") ;
        size = sc.nextInt() ;
        int[] arr = new int[size] ;
        int count = 0 ;
        while(count != size)
        {
            int index , element ;
            System.out.print("\nEnter The index: ");
            index = sc.nextInt() ;
            System.out.print("\nEnter The Element: ");
            element = sc.nextInt() ;
            try{
                arr[index] = element;
                count++ ; // Element is added
            }catch(ArrayIndexOutOfBoundsException e) // To Check if the index of the element is out of bounds
            {
                System.out.println("Index is out of bounds") ; 
            }
        }
        while(true)
        {
            menu() ;
            int choice ;
            choice = sc.nextInt() ;
            if(choice == 1)
            {
                System.out.println("Enter The Index for which you want to find the element: ");
                int index ;
                index = sc.nextInt() ;
                try
                {
                    System.out.println("Element at index " + index + " is " + arr[index]) ;
                }catch(ArrayIndexOutOfBoundsException e)
                {
                    System.out.println("Index Is Out of Bounds! Try again") ;
                }
            }
            else if(choice == 2)
            {
                int a , b ;
                int ans ;
                try {

                    System.out.print("\nEnter Numerator: ") ;
                    String s1 = sc.next() ;
                    a = Integer.parseInt(s1) ;

                    System.out.print("Enter Denominator: ") ;
                    String s2 = sc.next() ;
                    b =Integer.parseInt(s2) ;

                    try {
                        ans = a/b ; // Division by zero Exception
                        System.out.println ("Result: " + ans) ;
                    }
                    catch(ArithmeticException e) {
                        System.out.println("Divison not possible! Denominator is Zero");
                    }
                } catch (NumberFormatException e) { // Not a number Exception
                    System.out.println("Input is not a number. Please try again") ;
                }
            }
            else if(choice == 3)
            {
                System.out.println("Thank You!") ;
                break ;
            }
            else
            {
                System.out.println("Invalid Choice! Please try again!") ;
            }
        }
    }
}
/***  END   ***/
