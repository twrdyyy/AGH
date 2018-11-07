#include <iostream>
using namespace std;

const int MAX = 3;

bool zad2(int t[MAX][MAX]){
	
	int k = 0;
	int w = 0;
	int num = 0;
	int done = false;
	while(w<MAX){
		num = t[k][w];
		while(num>0){
			done = true;
			if((num%10)%2!=0){				
				w = MAX;
				done = false;
				break;
			}
			num/=10;
		}
		if(!done) break;
		if(done && w+1 == MAX) break;
		if(w+1 == MAX){
			k++;
			w=0;
			if(k+1 == MAX) break;
		}
		else{
			w++;
		}
	}
	return done;
}

int main(){
	int t[MAX][MAX];
	
	for(int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++){
			cin>>t[i][j];
		}
	}
	if(zad2(t)) cout<<"YES";
	
	return 0;
}
