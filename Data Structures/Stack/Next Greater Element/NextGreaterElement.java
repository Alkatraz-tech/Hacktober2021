import java.util.Stack;

public class NextGreaterElement {
    
    public static int[] findGreaterElement(int[] arr){
        int[] ans = new int[arr.length];

        Stack <Integer> stack = new Stack <>();

        for(int i = arr.length - 1 ; i>=0;i--){

            if(!stack.empty()) {
                while(!stack.empty() && stack.peek() <= arr[i]){
                    stack.pop();
                }
            }
            ans[i] = stack.empty() ? -1 : stack.peek();
            stack.push(arr[i]);

        }

        return ans;
    }
    public static void main(String[] args) {
        
        int[] arr = {4, 6, 13, 1, 2, 25, 3, 3};
        //int[] arr_1 = {11, 13, 21, 3};
        System.out.print("Given Array : ");
        for(Integer i : arr){
            System.out.print(" " + i);
        }

        int[] ans = findGreaterElement(arr);

        System.out.print("\nNext greater elements : ");
        for(Integer i : ans){
            System.out.print(" " + i);
        }
    }
}
