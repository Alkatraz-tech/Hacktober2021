#include <stdlib.h> 
#include <stdio.h> 

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}
 
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}


/* Function to print an array */
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}


int main()
{
	int i;
	int number;

	printf("\nEnter the number of elements in your array:- ");
	scanf("%d", &number);

	int array[number];

	printf("\nEnter the array elements with SPACE as separator:- ");
	for (i = 0; i < number; ++i)
		scanf("%d", &array[i]);

	int arr_size = sizeof(array) / sizeof(array[0]);

	printf("\nThe typed array is :- ");
	printArray(array, arr_size);

	mergeSort(array, 0, arr_size - 1);

	printf("\nThe Sorted array is :- ");
	printArray(array, arr_size);
	return 0;
}