#include <iostream>
using namespace std;

int arr[] = {5,8,9,4,6,3,8,7,1,5,6};
int n = sizeof(arr)/sizeof(*arr);

void swap(int arr[], int a, int b){
		
	int sum = arr[a] + arr[b];
	arr[a] = sum - arr[a];
	arr[b] = sum - arr[b];
	
}
	
int main() {
	int b = n;
	
	while( n > 1){
		for(int i = 0;i < n-1;i++){
			if(arr[i] > arr[i+1])
				swap(arr, i, i+1);
			for(int i = 0;i < b;i++){
				cout<<arr[i]<<" ";
				
			}
			cout<<endl;
			
		}
		
	n = n - 1;
	
	}
	for(int i = 0;i < b;i++){
		cout<<arr[i]<<" ";
}
	return 0;
}
