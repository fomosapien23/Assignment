#include<bits\stdc++.h>

using namespace std;

  bool dfs(int curr, vector<int>adj[],vector<bool > &visit, int parent,int &ans){
        
        visit[curr]=true;
        
        for(auto it: adj[curr]){
            if(visit[it]==false){
                if( dfs(it,adj,visit,curr,ans)==true){
                	ans++;
                    return true;
                }
            }
            else{
                if(it!=parent){
                	return true;
            }
        }
        return false;
   	 }
    }
    
    
int main(){
	
//	taking no. of node and vertices from user
	int n,e;
	cout<<"enter the no. of nodes and edges: ";
	cin>>n>>e;
	
//	creating adjacency list for the graph
	vector<int>adj[n]; 
	
	
//	taking vertices ans weight as input
	for(int i=0;i<e;i++){
		int u,v;
		cout<<"enter the first Node , second node: ";
		cin>>u>>v;
		
		
		adj[u].emplace_back(v);
		
		adj[v].emplace_back(u);
	}
	
	vector<bool>visit(n,0); 
		int ans=0;
		
		for(int i=0;i<n;i++){
			if(visit[i]==false)
			dfs(0,adj,visit,-1,ans);
			
		}
	
		cout<<ans;
	
	return 0;
}