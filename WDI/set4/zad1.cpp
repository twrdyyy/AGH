#include <iostream>   
using namespace std;

const int MAX = 20;

void spiral(int t[MAX][MAX]){
	
	int temp = MAX;
	int i = 0;
	int j = 0;
	int counter = 0;
	int raw_counter = 0;
	for(int n = 1; n <= MAX*MAX; n++){
		raw_counter++;
		if(raw_counter%temp == 0){
			counter++;
			raw_counter = 0;
			if(counter%2==1) temp--;
		}
		t[j][i] = n;
		
		if(counter%4==0){
			i++;
		}
		if(counter%4==1){
			j++;
		}
		if(counter%4==2){
			i--;
		}
		if(counter%4==3){
			j--;
		}	
	}
	
	for(int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++){
			cout.width(4);
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	
	int t[MAX][MAX];
	
	spiral(t);
	
	return 0;
}
