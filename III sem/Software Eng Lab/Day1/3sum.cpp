#include <bits\stdc++.h>

using namespace std;


void solve(int idx,int n, vector<int > v,vector<vector<int>> &ans,vector<int > output,int sum,int t ){
	
	if(t==3 && sum==0){
		ans.emplace_back(output);
		return;
	}
	
	if(t>3 || idx>=n)return ;
	
	sum+=v[idx];
	output.emplace_back(v[idx]);
	solve(idx+1,n,v,ans,output,sum,t+1);
	sum-=v[idx];
	output.pop_back();
	
	solve(idx+1,n,v,ans,output,sum,t);
	
	
}


int main(){
	
	cout<<"enter the no. of element";
	
	int n;
	cin>>n;
	cout<<"enter the element :"<<endl;
	vector<int > v(n);
	
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	vector<vector<int>> ans;
	vector<int > output;
	
	solve(0,n,v, ans,output, 0,0);
	
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[0].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}