#include <iostream>
using namespace std;

int arr[] = {5,8,9,4,6,3,8,7,1,5,9,3,12,54,3,34,123,4,65,65,1,14};
int n = sizeof(arr)/sizeof(*arr);

void swap(int arr[], int a, int b){
		
	int sum = arr[a] + arr[b];
	arr[a] = sum - arr[a];
	arr[b] = sum - arr[b];

}

void insertion_sort(int arr[], int n){
	for(int i = 1;i < n; i++){
		for(int j = 0; j < i; j++){
			if(arr[i] < arr[j])
				swap(arr, i, j);		
		}	
	}
}

int main() {
	
	insertion_sort(arr, n);
	for(int i = 0;i < n;i++){
		cout<<arr[i]<<" ";
	}
	
}
