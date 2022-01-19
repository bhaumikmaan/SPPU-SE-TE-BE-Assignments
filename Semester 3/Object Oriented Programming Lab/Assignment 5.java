/***  KNOWLEDGE IS POWER  ***/

import java.util.* ;

interface vehicle
{
    void ShowData() ;
    void changeGear(int inc) ;
    void changeSpeed(int inc) ;
    void applyBrakes() ;
}

class bicycle implements vehicle
{
    int speed = 0 , gear = 0 ;
    // Function made to print the detail of the bicycle
    public void ShowData()
    {
        System.out.println("Speed of the bicycle: " + speed) ;
        System.out.println("Gear of the bicycle: " + gear) ;
    }
    public void changeGear(int g)
    {
        this.gear += g ;
    }
    public void changeSpeed(int s)
    {
        this.speed += s ;
        this.speed = Math.max(this.speed , 0) ;
    }
    public void applyBrakes()
    {
        this.speed = 0 ;
        this.gear = 0 ;
    }
}
class bike implements vehicle
{
    int speed = 0 , gear = 0 ;
    public void ShowData( )
    {
        System.out.println("Speed of the bike: " + speed) ;
        System.out.println("Gear of the bike: " + gear) ;
    }
    public void changeGear(int g)
    {
        this.gear += g ;
    }
    public void changeSpeed(int s)
    {
        this.speed += s ;
        this.speed = Math.max(this.speed , 0) ;
    }
    public void applyBrakes( )
    {
        this.speed = 0 ;
        this.gear = 0 ;
    }
}


class car implements vehicle
{
    int speed = 0 , gear = 0 ;
    public void ShowData( )
    {
        System.out.println("Speed of the car: " + speed) ;
        System.out.println("Gear of the car: " + gear) ;
    }

    public void changeGear(int g)
    {
        this.gear += g ;
    }

    public void changeSpeed(int s)
    {
        this.speed += s ;
        this.speed = Math.max(this.speed , 0) ;
    }

    public void applyBrakes()
    {
        this.speed = 0 ;
        this.gear = 0 ;
    }
}

public class Main
{
    public static void menu( )
    {
        System.out.println( ) ;
        System.out.println("Please enter the vehicle:") ;
        System.out.println("1. Bicycle") ;
        System.out.println("2. Bike") ;
        System.out.println("3. Car") ;
        System.out.println("4. Exit") ;
        System.out.print("Please enter your choice: ") ;
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        while(true)
        {
            menu();
            int choice=sc.nextInt();
            if(choice == 1)
            {
                bicycle nova = new bicycle() ;

                // Changing the speed of the bicycle
                System.out.println("Changing the speed of the bicycle") ;
                nova.changeSpeed(50) ;

                // Changing the gear of the bicycle
                System.out.println("Changing the gear of the bicycle") ;
                nova.changeGear(4) ;

                // Printing the data of the bicycle
                System.out.println("Printing the data of the bicycle") ;
                nova.ShowData() ;

                // Applying Brakes
                System.out.println("Applying brake to the bicycle") ;
                nova.applyBrakes() ;

                // Printing the data of the bicycle after applying brake
                System.out.println("Printing the data of the bicycle after applying brake") ;
                nova.ShowData() ;
            }
            else if(choice == 2)
            {
                bike KTM = new bike();

                // changing the gear of the bike
                System.out.println("Changing the gear of the bike");
                KTM.changeGear(5);

                //changing the speed of the bike
                System.out.println("Changing the speed of the bike");
                KTM.changeSpeed(70);

                // printing the data of the bike
                System.out.println("Printing the data of the bike");
                KTM.ShowData();

                System.out.println("Applying brake to the bike");
                KTM.applyBrakes();

                // printing the data of the bike after applying brake
                System.out.println("Printing the data of the bike after applying brake");
                KTM.ShowData();
            }
            else if(choice == 3)
            {
                car tata = new car();

                // changing the gear of the car
                System.out.println("Changing the gear of the car");
                tata.changeGear(7);

                //changing the speed of the car
                System.out.println("Changing the speed of the car");
                tata.changeSpeed(120);

                // printing the data of the car
                System.out.println("Printing the data of the car");
                tata.ShowData();

                System.out.println("Applying brake to the car");
                tata.applyBrakes();
                
                // printing the data of the car after applying brake
                System.out.println("Printing the data of the car after applying brake");
                tata.ShowData();
            }
            else if(choice == 4)
            {
                System.out.println("Thank You!");
                break;
            }
            else
            {
                System.out.println("Invalid choice, Please try again.");
            }
        }
    }
}
/***  END   ***/
