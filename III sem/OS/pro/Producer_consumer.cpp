#include<bits/stdc++.h>

using namespace std;

#define Buffer_size 10

int in=0,out=0;
int total=0;

string Buffer[10];

void producer(){
	total++;
	Buffer[in]="Item"+to_string(in+1);
	cout<<"produced-> "<<Buffer[in]<<endl;
	in=(in+1)% Buffer_size;
	
}

void consumer(){
	total--;
	cout<<"consumed-> "<<Buffer[out]<<endl;
	out=(out+1)% Buffer_size;
	
}

int main(){
	
	int t=0;
	
	cout<<"enter your choice: \n1.consumer \n2.producer \n3.exit\n";
	
	while(t==0){
		int n;
		cin>>n;
		
		switch(n){
			case 1:
				if(total==0){
					cout<<"Buffer is Empty\n";
				}else{
					consumer();
				}
			break;
			
			case 2:
				if(total==10){
					cout<<"Buffer is full\n";
				}else{
					producer();
				}
			break;
			
			case 3:
				int t=-1;
			break;
		}	
		
	}
	return 0;
}