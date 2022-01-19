/***  KNOWLEDGE IS POWER  ***/

import java.util.* ;

abstract class shape
{
    abstract public void computeArea() ;
}

class triangle extends shape
{
    private int base ;
    private int height ;

    public void setBase(int base)
    {
        this.base = base ;
    }
    public void setHeight(int height)
    {
        this.height = height ;
    }

    public void computeArea()
    {
        int area = (base*height)/2 ;
        System.out.println("The area of the Triangle is : " + area) ;
    }
}

class rectangle extends shape
{
    private int length ;
    private int breadth ;

    public void setLength(int length)
    {
        this.length = length ;
    }
    public void setBreadth(int breadth)
    {
        this.breadth = breadth ;
    }

    public void computeArea()
    {
        int area = length*breadth ;
        System.out.println("The area of the Rectangle is : " + area) ;
    }
}

public class Main
{
    public static void menu()
    {
        System.out.println("----------------------------------------------------") ;
        System.out.println("Which figure do want to calculate the area for?") ;
        System.out.println("1.Triangle") ;
        System.out.println("2.Rectangle") ;
        System.out.println("3.Exit") ;
        System.out.println("----------------------------------------------------") ;
        System.out.print("Enter you choice: ") ;
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in) ;
        while(true)
        {
            System.out.println() ;
            menu() ;
            int choice = sc.nextInt() ;
            if(choice == 1)
            {
                triangle obj = new triangle() ;
                System.out.print("Enter height of the Triangle: ") ;
                int height = sc.nextInt() ;
                System.out.print("Enter base of the Triangle: ") ;
                int base = sc.nextInt() ;

                obj.setHeight(height) ;
                obj.setBase(base) ;
                obj.computeArea() ;
            }
            else if(choice == 2)
            {
                rectangle obj = new rectangle() ;
                System.out.print("Enter length of the Rectangle: ") ;
                int length = sc.nextInt() ;
                System.out.print("Enter breadth of the Rectangle: ") ;
                int breadth = sc.nextInt() ;

                obj.setLength(length) ;
                obj.setBreadth(breadth) ;
                obj.computeArea() ;
            }
            else if(choice == 3)
            {
                System.out.println("Thank you!") ;
                break ;
            }
            else
            {
                System.out.println("Invalid choice!") ;
            }
        }
    }
}
/***  END   ***/
