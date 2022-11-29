#include <stdio.h>
#include <stdlib.h>

int binary_search(int ar[],int start ,int end, int key)
{
	if(start < end)
	{
		int mid = (start+end)/2;
		if(key == ar[mid])
			return mid ;
		else if(key < ar[mid])
			return binary_search(ar,start,mid,key);
		else
			return binary_search(ar,mid+1,end,key);
	}
	if( (key < 0) || (key > end) )
		return -1;
	return -1;
}

int main(int argc, char *argv[]){

	int arr[20], size = 0,result, key;
	printf("%s\n", "===== Binary Search by Child Process =====");
	for(int i = 0 ; argv[i+1] != 0 ; i++){
		arr[i] = atoi(argv[i+1]);
		size++;
	}

	printf("%s\n", "Sorted Array: ");
	for(int i = 0 ; i < size ; i++){
		printf("%d\t", arr[i]);
	}

	printf("\n%s", "Number to search: " );
	scanf("%d", &key);

	result = binary_search(arr, 0, size, key);

	if(result == -1)
		printf("%s\n", "Number not Found" );
	else{
		printf("Element found at %d location\n", result+1);
	}

	return 0;
}
