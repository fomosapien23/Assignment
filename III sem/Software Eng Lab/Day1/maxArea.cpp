#include<iostream>
using namespace std;


int find(int n, int arr[]){
	
		if(n<=1)return 0;
	
	int l=0;
	int h=n-1;
	
	int maxi=0;
	while(l<h){
		
		maxi=max(maxi,(min(arr[l],arr[h])* (h-l)));
		
		if(arr[l]<arr[h]){
			l++;
		}
		else  {
			h--;
		}
	}
	return maxi;
}




int main(){
	int n;
	cout<<"enter the no. of element"<<endl;
	cin>>n;
	
	int arr[n];
	cout<<" enter the element "<<endl;
	for(int i=0;i<n;i++){
		cin>> arr[i];
	}
	
	cout<<"the maximum area should be : "<<find(n,arr)<<endl;
	return 0;
}