package hacktoberfest;
import java.util.Scanner;


public class Hacktoberfest {

    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter Your name:");
        
        String name = input.nextLine();
        System.out.println("Enter Your marks");
        int marks = input.nextInt();
        System.out.println("Hello "+ name);
        if(marks >= 75)
        {
            System.out.println("Congradulations you got A pass");
        }
        else if(marks >=65 && marks < 75)
        {
            System.out.println("Congradulations you got B pass");
        }
        else if(marks > 55 && marks < 65)
        {
            System.out.println("Congradulations you got C pass");
        }
        else if(marks > 35 && marks < 55)
        {
            System.out.println("Congradulations you just got S pass");
        }
        else
        {
            System.out.println("Work hard and Try Again.Better luck next time");
        }
        
        
        
    }
    
}
