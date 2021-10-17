import java.util.Arrays;

public class CountingSort {
	public static void main(String[] args) {
		int[] arr = { 1, 88, 9, 22, 9, 3, 0, 44, 78, 99, 88, 2 };
		countsort(arr);
	}

	static void countsort(int[] arr) {
		// gets maximum value in array;
		int max = Arrays.stream(arr).max().getAsInt();
		int[] count = new int[max + 1];
		for (int a : arr) {
			count[a]++;
		}
		for (int i = 0; i < count.length; i++) {
			while (count[i]-- > 0) {
				System.out.print(i + ", ");
			}
		}
	}
}