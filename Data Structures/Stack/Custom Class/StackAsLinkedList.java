public class StackAsLinkedList {

    StackNode top;
    public class StackNode{
        int data;
        StackNode next;
        StackNode(int data){
            this.data = data;
            next = null;
        }
    }

    public boolean isEmpty(){
        return (top == null);
    }

    public void peek(){
        if(this.isEmpty()){
            System.out.println("Stack is empty");
        }
        else{
            System.out.println("Peek : "+top.data);
        }
    }

    public int pop(){
        int popped = Integer.MIN_VALUE;

        if(this.isEmpty()){
            System.out.println("Stack Underflow!");
        }
        else {
            popped = top.data;
            top = top.next;

        }
        return popped;
    }

    public void push(int data){
        StackNode newNode = new StackNode(data);
        if(top == null){
            top = newNode;
        }
        else {
            StackNode temp = top ;
            top = newNode;
            top.next = temp;
        }
        System.out.println(data + " has been pushed");
    }

    public void print(){
        StackNode stack_top = top;
        while(stack_top != null){
            System.out.print(stack_top.data + " ");
            stack_top = stack_top.next;
        }
    }

    public static void main(String[] args) {
        StackAsLinkedList sll = new StackAsLinkedList();

        sll.push(10);
        sll.push(20);
        sll.push(30);
 
        System.out.println(sll.pop()  + " popped from stack");
 
        sll.peek();
        System.out.println("Elements present in stack : ");
        sll.print();

    }
}
