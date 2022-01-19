/***  KNOWLEDGE IS POWER  ***/

import java.util.*;

class Employee
{
    Scanner sc= new Scanner(System.in) ;
    private String emp_name ;
    private String address ;
    private String mail_id ;
    private String mobile_no ;
    private int emp_id ;

    public void getData( )
    {
        System.out.println("Enter Employee Details: ") ;
        // Get
        System.out.print("Enter Name: ") ;
        String emp_name = sc.next() ;

        System.out.print("Enter ID: ") ;
        int emp_id = sc.nextInt() ;

        System.out.print("Enter address: ") ;
        String address = sc.next() ;

        System.out.print("Enter Mail-id: ") ;
        String mail_id = sc.next() ;

        System.out.print("Enter Mobile number: ") ;
        String mobile_no = sc.next() ;

        // Set
        this.emp_name = emp_name ;
        this.address = address ;
        this.mail_id = mail_id ;
        this.emp_id = emp_id ;
        this.mobile_no = mobile_no ;
    }

    public void display()
    {
        System.out.println("Name of the employee is: " +  emp_name) ;
        System.out.println("Id of the employee is: " + emp_id) ;
        System.out.println("Address of the employee is: " + address) ;
        System.out.println("Mail id of the employee is: " + mail_id) ;
        System.out.println("Mobile number of the employee is: " + mobile_no) ;
    }
}

class Programmer extends Employee // For Programmer
{
    Scanner sc= new Scanner(System.in);
    double basic , da , hra , pf , club , gross , net ;

    public void getSal()
    {
        System.out.println("Enter the Basic Amount Of salary of employee: ") ;
        int basic = sc.nextInt() ;
        this.basic = basic ;
    }

    public void calculateSal()
    {
        da = basic*0.97 ;
        hra = basic*0.1 ;
        pf = basic*0.12 ;
        club = basic*0.001 ;

        // Calculating gross salary and net salary
        gross = basic - pf ;
        net = gross - hra - club ;
    }

    public void displaySalary()
    {
        System.out.println("Basic Pay of the employee: " + basic) ;
        System.out.println("DA of the employee: " + da) ;
        System.out.println("HRA of the employee: " + hra) ;
        System.out.println("PF of the employee: " + pf) ;
        System.out.println("Staff club fund of the employee: " + club) ;
        System.out.println("Gross salary of the employee: " + gross) ;
        System.out.println("Net salary of the employee: "+ net) ;
    }

}

class teamLead extends Employee // For Team Lead
{
    Scanner sc = new Scanner(System.in) ;
    double basic , da , hra , pf , club , gross , net ;

    public void getSal()
    {
        System.out.println("Enter the Basic Amount Of salary of employee: ") ;
        int basic = sc.nextInt() ;
        this.basic = basic ;
    }

    public void calculateSal()
    {
        da = basic*0.97 ;
        hra = basic*0.1 ;
        pf = basic*0.12 ;
        club = basic*0.001 ;

        // Calculating gross salary and net salary
        gross = basic-pf ;
        net = gross - hra - club ;
    }

    public void displaySalary()
    {
        System.out.println("Basic Pay of the employee: " + basic) ;
        System.out.println("DA of the employee: " + da) ;
        System.out.println("HRA of the employee: " + hra) ;
        System.out.println("PF of the employee: " + pf) ;
        System.out.println("Staff club fund of the employee: " + club) ;
        System.out.println("Gross salary of the employee: " + gross) ;
        System.out.println("Net salary of the employee: "+ net) ;
    }
}

class assistantProjectManager extends Employee // For Assistant Project Manager
{
    Scanner sc= new Scanner(System.in);
    double basic , da , hra , pf , club , gross , net ;

    public void getSal()
    {
        System.out.println("Enter the Basic Amount Of salary of employee: ") ;
        int basic = sc.nextInt() ;
        this.basic = basic ;
    }

    public void calculateSal()
    {
        da = basic*0.97 ;
        hra = basic*0.1 ;
        pf = basic*0.12 ;
        club = basic*0.001 ;

        // Calculating gross salary and net salary
        gross = basic - pf ;
        net = gross - hra - club ;
    }

    public void displaySalary()
    {
        System.out.println("Basic Pay of the employee: " + basic) ;
        System.out.println("DA of the employee: " + da) ;
        System.out.println("HRA of the employee: " + hra) ;
        System.out.println("PF of the employee: " + pf) ;
        System.out.println("Staff club fund of the employee: " + club) ;
        System.out.println("Gross salary of the employee: " + gross) ;
        System.out.println("Net salary of the employee: "+ net) ;
    }
}

class projectManager extends Employee // For Project Manager
{
    Scanner sc = new Scanner(System.in);
    double basic , da , hra , pf , club , gross , net ;

    public void getSal()
    {
        System.out.print("Enter the Basic Amount Of salary of employee: ") ;
        int basic = sc.nextInt() ;
        this.basic = basic ;
    }

    public void calculateSal()
    {
        da = basic*0.97 ;
        hra = basic*0.1 ;
        pf = basic*0.12 ;
        club = basic*0.001 ;

        // Calculating gross salary and net salary
        gross = basic - pf ;
        net = gross - hra - club ;
    }

    public void displaySalary()
    {
        System.out.println("Basic Pay of the employee: " + basic) ;
        System.out.println("DA of the employee: " + da) ;
        System.out.println("HRA of the employee: " + hra) ;
        System.out.println("PF of the employee: " + pf) ;
        System.out.println("Staff club fund of the employee: " + club) ;
        System.out.println("Gross salary of the employee: " + gross) ;
        System.out.println("Net salary of the employee: "+ net) ;
    }
}

public class Main
{
    public static void menu()
    {
        System.out.println("\n---------------------------------------") ;
        System.out.println("1.Programmer") ;
        System.out.println("2.Team Leader") ;
        System.out.println("3.Assistant Project Manager") ;
        System.out.println("4.Project Manager") ;
        System.out.println("5.Exit") ;
        System.out.println("---------------------------------------") ;
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        while(true)
        {
            menu() ;
            System.out.println("Please enter your choice: ") ;
            int choice ;
            choice = sc.nextInt() ;

            if(choice == 1)
            {
                Programmer obj = new Programmer();
                obj.getData();
                obj.getSal();
                obj.calculateSal();
                obj.display();
                obj.displaySalary();

            }
            else if(choice == 2)
            {
                teamLead obj = new teamLead();
                obj.getData();
                obj.getSal();
                obj.calculateSal();
                obj.display();
                obj.displaySalary();

            }
            else if(choice == 3)
            {
                assistantProjectManager obj = new assistantProjectManager();
                obj.getData();
                obj.getSal();
                obj.calculateSal();
                obj.display();
                obj.displaySalary();

            }
            else if(choice == 4)
            {
                projectManager obj=new projectManager();
                obj.getData();
                obj.getSal();
                obj.calculateSal();
                obj.display();
                obj.displaySalary();

            }
            else if(choice == 5)
            {
                System.out.println("Thank you") ;
                break ;
            }
            else
            {
                System.out.println("Invalid choice") ;
            }
        }
    }
}
/***  END  ***/
