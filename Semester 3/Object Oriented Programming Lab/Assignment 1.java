/***  KNOWLEDGE IS POWER  ***/

package com.company ;

class complex {
    int real , img ;
    float tempReal , tempImg ; // For Division
    public void setValue(int a , int b)
    {
        real = a ;
        img = b ;
    }
    public void setFloatValue(float c , float d)
    {
        tempReal = c ;
        tempImg = d ;
    }
}
class operations
{
    public static complex add(complex c1,complex c2) // (a + c) + i*(b + d)
    {
        int sumReal = c1.real + c2.real ;
        int sumImg = c1.img + c2.img ;
        complex ans = new complex() ;
        ans.setValue(sumReal,sumImg) ;
        return ans ;
    }
    public static complex subtract(complex c1,complex c2) // (a - c) + i*(b - d)
    {
        int diffReal = c1.real - c2.real ;
        int diffImg = c1.img - c2.img ;
        complex ans = new complex() ;
        ans.setValue(diffReal , diffImg) ;
        return ans ;
    }
    public static complex multiply(complex c1,complex c2) // (a*c - b*d) + i*(a*d + b*c)
    {
        int prodReal = (c1.real*c2.real) - (c1.img*c2.img) ;
        int prodImg = (c1.real*c2.img) + (c1.img*c2.real) ;
        complex ans = new complex() ;
        ans.setValue(prodReal,prodImg) ;
        return ans ;
    }
    public static complex divide(complex c1,complex c2)
    {
        float divReal= (float) (((c1.real*c2.real)+(c1.img*c2.img))*1.0/((c2.real*c2.real)+(c2.img*c2.img))) ;
        float divImg= (float) (((c1.img*c2.real)-(c1.real*c2.img))*1.0/((c2.real*c2.real)+(c2.img*c2.img))) ;
        complex ans=new complex() ;
        ans.setFloatValue(divReal,divImg) ;
        return ans ;
    }
}
public class Main {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        while(true) // Until exited
        {
            System.out.println("Enter your choice of operation");
            System.out.println("1.Addition");
            System.out.println("2.Subtraction");
            System.out.println("3.Multiplication");
            System.out.println("4.Division");
            System.out.println("5.Exit");

            int choice = sc.nextInt() ;
            if(choice < 1 || choice > 5) // Out of the given options
            {
                System.out.println("Invalid choice, try again");
                continue ;
            }
            if(choice == 5)
            {
                break ;
            }

            // Taking input for the first complex number
            complex c1 = new complex() ;
            System.out.println("Enter the Real value of the First complex number: ");
            int Real1 = sc.nextInt() ;
            System.out.println("Enter the Imaginary value of the First complex number: ");
            int Img1 = sc.nextInt() ;
            c1.setValue(Real1,Img1) ;

            // Taking input for the second complex number
            complex c2 = new complex() ;
            System.out.println("Enter the Real value of the Second complex number: ");
            int Real2 = sc.nextInt() ;
            System.out.println("Enter the Imaginary value of the Second complex number: ");
            int Img2 = sc.nextInt() ;
            c2.setValue(Real2,Img2) ;

            if(choice == 1)
            {
                System.out.println("The Addition of the complex numbers is");
                complex ansSum = operations.add(c1,c2) ;
                System.out.println(ansSum.real + " + " + ansSum.img + "i") ;
            }
            else if(choice == 2)
            {
                System.out.println("The Subtraction of the complex numbers is") ;
                complex ansSub = operations.subtract(c1,c2) ;
                System.out.println(ansSub.real + " + " + ansSub.img + "i") ;
            }
            else if(choice == 3)
            {
                System.out.println("The Multiplication of the complex numbers is");
                complex ansProd = operations.multiply(c1,c2) ;
                System.out.println(ansProd.real + " + " + ansProd.img + "i") ;
            }
            else
            {
                System.out.println("The Division of the complex numbers is") ;
                complex ansDiv = operations.divide(c1,c2) ;
                System.out.println(ansDiv.tempReal + " + " + ansDiv.tempImg + "i" );
            }
            System.out.println() ;
        }
    }
}

/***  END ***/
