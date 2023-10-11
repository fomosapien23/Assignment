#include<bits\stdc++.h>

using namespace std;

void find(vector<vector<int>> adj[],int s,int n){
	
//	creating set to track the visiting node
	set<pair<int ,int>> st;
	
//	create vector to store shortest distance
//intialize with max value(infinite)

	vector<int> path(n,INT_MAX);
	
//	initialize source node distance with zero and insert into set
	path[s]=0;
	
	st.insert({0,s});
	
	
//	running loop until all edges process
	while(!st.empty()){
		
		auto temp= *(st.begin());
		
		st.erase(temp);
		
		int currNode= temp.second;
		int W= temp.first;
		
		
		
		for(auto it: adj[currNode] ){
			int adjnode= it[0];
			int adjW=it[1];
			
			if(path[adjnode]>W+adjW){
				path[adjnode]=  W+adjW;
				st.insert({path[adjnode],adjnode});	
			}
		}
	}
	
//	loop use to print the shortest distance of node from source node
	for(int i=0;i<n;i++){
		cout<<" the shortest distance from source Node  "<<s<<" to "<<i<< " is "<<path[i]<<endl;
	}
}

int main(){
	
//	taking no. of node and vertices from user
	int n,e;
	cout<<"enter the no. of nodes and edges: ";
	cin>>n>>e;
	
//	creating adjacency list for the graph
	vector<vector<int>>adj[n]; 
	
	
//	taking vertices ans weight as input
	for(int i=0;i<e;i++){
		int u,v,w;
		cout<<"enter the first Node , second node and weight : ";
		cin>>u>>v>>w;
		vector<int> temp1;
		
		temp1.emplace_back(v);
		temp1.emplace_back(w);
		adj[u].emplace_back(temp1);
		
		
		vector<int> temp2;
		temp2.emplace_back(u);
		temp2.emplace_back(w);
		
		adj[v].emplace_back(temp2);
	}
	
//	taking source from where to find shortest distance
	cout<<"enter the source point : ";
	int s;
	cin>> s;
	
	find(adj,s,n);
	
	return 0;
}