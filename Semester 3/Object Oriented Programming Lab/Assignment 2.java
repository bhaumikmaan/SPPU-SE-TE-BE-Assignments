/***  KNOWLEDGE IS POWER  ***/

import java.util.Scanner;


public class Main{
    
    public static void main(String[] args){
        Scanner input = new Scanner ( System.in) ;
        System.out.println("\n-----------------------------------------------------------------------\n\n");

        System.out.println("\n-------------------SET THE INFORMATION ABOUT BOOK------------------------\n") ;

        Books book = new Books() ;
        book.setBookInformation() ;

        System.out.println("\n-------------------SET THE INFORMATION ABOUT MAGAZINE------------------------\n") ;
       
        Magazine mag  = new Magazine() ;
        mag.setMagInformation(); 

        System.out.println("\n-------------------OPTIONS------------------------\n") ;
        
        while(true) 
        {
            menu() ;
            int choice = input.nextInt() ;
            if(choice == 1)
            {
                System.out.print("How many Books to you want to Buy : ");
                int quantity = input.nextInt() ;
                book.order_copies(quantity);
                System.out.println("Thank you for shoping with us! :)") ; 
                line() ;
            }
            else if(choice == 2)
            {
                System.out.print("How many Magazines to you want to Buy : ");
                int quantity = input.nextInt() ;  
                mag.order_copies(quantity);
                System.out.println("Thank you for shoping with us! :)") ; 
                line() ;
            } 
            else if(choice == 3)
            {
                String issue ; int quantity ;
                System.out.println("New Issue : ") ;
                issue = input.next() ;
                System.out.println("Quantity : ") ;
                quantity = input.nextInt() ;
                mag.recieve_new_issue(issue, quantity);
                System.out.println("Fresh Issue has been Added to the Stock!") ; 
                line();
    
            }
            else if(choice == 4)
            {
                book.information() ; 
                line() ;
            }
            else if(choice == 5)
            {
                mag.information() ; 
                line() ;
            }
            else if(choice == 6)
            {
                break ; 
            }
        }
        line(); line();
        input.close();
    }

    public static void menu()
    {
        System.out.println("1.Buy books");
        System.out.println("2.Buy magazines");
        System.out.println("3.Receive new Publication [Magazine]");
        System.out.println("4.Get Book Information");
        System.out.println("5.Get Magazine Information");
        System.out.println("6.Exit the program");
        System.out.print("Enter your choice: ");
    }

    public static void line()
    {
        System.out.println("----------------------------------------------------------------");
    }

}


class Publication {

    String title;
    double price;
    int copies;

    Scanner input = new Scanner(System.in);

    Publication(){} ;
    Publication(String title , double price , int copies){
        this.title = title ;
        this.price = price ;
        this.copies = copies ;
    }

    public int getCopies(){
        return this.copies ;
    }
    public void setCopies(int copies)
    {
        this.copies = copies ;
    }
    public void add_copies(int copies)
    {
        this.copies += copies ;
    }
    public void display_Current_Sales_Statistics(int quantity)
    {
        System.out.println("\nTotal Sales :  " + this.price*quantity + "\n" ) ;
    }
    public void sellCopy(int quantity) 
    { 
        this.copies -= quantity ; display_Current_Sales_Statistics(quantity) ; 
    }
    public void line()
    {
        System.out.println("----------------------------------------------------------------");
    }
    public void display_publication_data()
    {
        line() ;
        System.out.println("TITLE : " + this.title );
        System.out.println("PRICE : " + this.price );
        System.out.println("COPIES REMAINING IN STOCK  : " + this.copies );
    }
}

class Books extends Publication {  
    String author; 
    static int total_books = 0 ;
    public void setBookInformation()
    {
        System.out.print("TITLE OF THE BOOK : " );
        String t = input.nextLine();
        System.out.print("PRICE OF THE BOOK : " );
        double p = input.nextDouble();
        System.out.println("INITIAL COPIES OF THE BOOK: ") ;
        int c = input.nextInt() ;
        System.out.println("AUTHOR OF THE BOOK: " ) ;
        get_author() ;

        title = t ;
        price = p ;
        copies = c ;
        total_books += c ;
    }

    public void display_Current_Sales_Statistics(int quantity)
    {
        
        System.out.println("\nTotal Sales of Book:  " + this.price*quantity + "\n" ) ;
    }

    public void get_author()
    {
        input.nextLine() ;
        this.author =  input.nextLine() ;
    }

    public void order_copies(int quantity)
    {
        if(quantity > copies)
        { 
            System.out.println("Sorry , we don't have this number of Copies left" ) ; 
            return ;
        }
        total_books-=quantity ;
        this.copies -= quantity ; 
        display_publication_data() ; 
        display_Current_Sales_Statistics(quantity) ;
    }  
    public void information()
    {
        display_publication_data() ; 
        System.out.println("Author of the book : " + this.author);
    }
}

class Magazine extends Publication { 
    
    static int total_magazine = 0 ;
    String current_issue ;
    int orderQty = 0 ;

    public void information() 
    {
        display_publication_data() ; 
        System.out.println("Total Number of magazine are :"  + total_magazine) ; 
        System.out.println("Current issue OF THE Mangazine :" + current_issue) ;
    }

    public void display_Current_Sales_Statistics(int quantity)
    {
        System.out.println("\nTotal Sales of Magazine:  " + this.price*quantity + "\n" ) ;
    }
    public void get_issue()
    {
        System.out.println("CurrentIssue : " );
    }

    void order_copies(int quantity)
    {
        orderQty = quantity ;
        adjustQty(quantity) ;
        display_publication_data() ; 
        display_Current_Sales_Statistics(quantity) ;
    }
    void adjustQty(int quantity)
    {
        if(quantity > copies)
        { 
            System.out.println("Sorry , we don't have this number of Copies left" ) ; 
            return ;
        }
        total_magazine-=quantity ;
        copies -= quantity ; 
    }
    void recieve_new_issue(String NEW_ISSUE , int quantity)
    {
        this.copies+=quantity ;
        total_magazine += quantity ;
        current_issue = NEW_ISSUE ;
        display_publication_data() ; 
        information();
    }
    public void setMagInformation()
    {
        System.out.print("TITLE OF THE MAGAZINE : " );
        String t = input.nextLine();
        System.out.print("PRICE OF THE MAGAZINE : " );
        double p = input.nextDouble();
        System.out.print("INITIAL COPIES OF THE MAGAZINE : ") ;
        int c = input.nextInt() ;
        System.out.print("CURRENT ISSUE : ") ;
        input.nextLine();
        String cr = input.nextLine();
        title = t ;
        price = p ;
        copies = c ;
        total_magazine += c ;
        current_issue = cr ;
    }
}
/***  END  ***/
