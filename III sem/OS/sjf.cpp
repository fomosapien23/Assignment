#include<bits/stdc++.h>

using namespace std;

int main()
{
	cout<<"enter the no. of process: ";
	int n=0;cin>>n;int x,y;
	priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, greater<pair<pair<int,int>,int>>> a;
	
	stack<pair<pair<int,int>,int>> st;
	cout<<"enter the arrival time and execution time :"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		a.push( make_pair(make_pair(y,x),i+1));
	}
	int s=0;

	cout<<"\tAT\tET\tST\tFT\tWT\tTAT"<<endl;
	pair<pair<int,int>,int> v;
	while(!a.empty())
		{
			v=a.top();
			if(v.first.second<=s){a.pop();break;}
			st.push(a.top());a.pop();
		}
		while(!st.empty())
		{
			a.push(st.top());st.pop();
		}
	for(int i=0;i<n;i++)
	{
		
		s+=v.first.first;
		cout<<"P"<<v.second<<"\t"<<v.first.second<<"\t"<<v.first.first<<"\t"<<s-v.first.first<<"\t"<<s<<"\t"<<s-v.first.first-v.first.second<<"\t"<<s-v.first.second<<endl;

		while(!a.empty())
		{
			v=a.top();
			if(v.first.second<=s){a.pop();break;}
			st.push(a.top());a.pop();
		}
		while(!st.empty())
		{
			a.push(st.top());st.pop();
		}
	} 

	return 0;
	
}