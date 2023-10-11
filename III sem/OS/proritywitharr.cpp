#include<bits/stdc++.h>

using namespace std;

int main(){
	
	priority_queue<pair<pair<int,int> ,pair<int ,int>>> pq;
	
	int n;
	
	cout<<"enter the no. of proccess: ";
	cin>>n;
	
	
	cout<<"enter the priority, proccess no.,  arrival time and execution time: "<<endl;
	for(int i=0;i<n;i++){
		int p,t,a,e;
		
		cin>>p>>t>>a>>e;
		
		pq.push(make_pair(make_pair(p,t),make_pair(a,e)));
	}
	
	int st=0;
	int ft=0;
	cout<<"\tpro.\tAT\tET\tprior\tST\tFT\tTAT\tWT"<<endl;
	
	while(!pq.empty()){
		
		auto it=pq.top();
		pq.pop();
		st=ft;
		ft+=it.second.second;
		
		cout<<"\t"<<it.first.second<<"\t"<<it.second.first<<"\t"<<it.second.second<<"\t"<<it.first.first<<"\t"<<st<<"\t"<<ft<<"\t"<<ft<<"\t"<<ft-it.second.second<<endl;
		
		
	}
	
	
	
	
	return 0;
}