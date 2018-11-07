#include <iostream>
using namespace std;

const int MAX = 5;

/* O(n^2)
double div(int t[MAX][MAX], int w, int k){
	int sum_w = 0;
	int sum_k = 0;
	for(int i = 0; i < MAX; i++){
		sum_w += t[k][i];
		sum_k += t[i][w];
	}
	return (1.0*sum_k)/(sum_w);
}

int main(){
	int t[MAX][MAX];
	for(int i = 0; i < MAX; i++){
		for(int j =0 ; j<MAX; j++){
			cin>>t[i][j];
		}
	}
	double iloraz = 0.0;
	for(int i = 0; i<MAX;i++){
		for(int j = 0; j < MAX;j++){
			if(iloraz < div(t, j, i)) iloraz = div(t, j, i);
		}
	}
	
	cout<<iloraz;
	
	return 0;
*/

int main(){
	int t[MAX][MAX];
	for(int i = 0; i < MAX; i++){
		for(int j =0 ; j<MAX; j++){
			cin>>t[i][j];
		}
	}
	
	int sum_col = 0;
	int sum_row = 0;
	
	for(int i =0 ; i<MAX*MAX; i++){
		
		
		
		
		
		
	}
	
	
	return 0;
}



