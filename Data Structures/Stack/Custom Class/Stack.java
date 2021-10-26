public class Stack {

    private static final int Max = 3;
    //private static final int Max = 1000;
    private int top;
    private int[] arr = new int[Max];

    Stack(){
        top = -1;
    }
    public boolean isEmpty(){
        return (top < 0);
    }

    public boolean push(int x){
        if(top >= (Max-1)){
            System.out.println("Stack Overflow!");
            return false;
        }

        else {
            top++;
            arr[top] = x;
            System.out.println(x + " has been pushed...");
            return true;

        }
    }

    public void peek(){
        if(this.isEmpty()){
            System.out.println("Stack is Empty!");
        }
        else {
            System.out.println("Peek : " + arr[top]);
        }
    }

    public int pop(){
        if(this.isEmpty()){
            System.out.println("Stack Underflow!");
            return 0;
        }
        else {
            return arr[top--];
        }
    }
    public void printStack(){
        for(int i = top ; i > -1;i--){
            System.out.print(arr[i] + " ");
        }

    }

    public static void main(String[] args) {
        Stack s = new Stack();
        s.peek();
        s.push(1);
        s.push(2);
        s.peek();
        System.out.println(s.pop());
        s.peek();
        System.out.println(s.pop());
        System.out.println(s.pop());
        s.push(8);
        s.push(9);
        s.push(10);
        System.out.println("Elements Present in Stack ...");
        s.printStack();
        System.out.println();
        s.push(12);

    }
}
