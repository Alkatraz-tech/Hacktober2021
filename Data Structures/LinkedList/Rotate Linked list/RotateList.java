import java.util.Scanner;

class node
{
    public int data;
    node next;
    node(int d)
    {
        data = d;
        next = null;
    }
}

public class RotateList {

	public static node takeInput(Scanner s)
	{
	    System.out.println("Enter the data for nodes: ");
	    int data = s.nextInt();
	    node head = null;
	    while(data != -1)
	    {
	        node newNode = new node(data);
	        if(head == null)
	        {
	            head = newNode;
	        }
	        else
	        {
	            node temp = head;
	            while(temp.next != null)
	            {
	                temp = temp.next;
	            }
	            temp.next = newNode;
	        }
	        data = s.nextInt();
	    }
	    return head;
	}
	
	public static void printLL(node head)
	{
	    node temp = head;
	    while(temp != null)
	    {
	        System.out.print(temp.data + " ");
	        temp = temp.next;
	    }
	}

	public static void main(String[] args)
	{
	    Scanner s = new Scanner(System.in);
	    node head = takeInput(s);
	    System.out.println("Enter K: ");
	    int k = s.nextInt();
	    head = rotate(head, k);
	    printLL(head);
	}
	
	public static node rotate(node head, int k) {
		int n = 0;
		node temp = head, tail = null;
		while(temp != null) {
			n++;
			if(temp.next == null) {
				tail = temp;
			}
			temp = temp.next;
		}
		if(k > n) {
			k = k%n;
		}
		temp = head;
		while(n-- > k+1) {
			temp = temp.next;
		}
		tail.next = head;
		head = temp.next;
		temp.next = null;
		return head;
	}

}