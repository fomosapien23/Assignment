#include <iostream>
#include<bits\stdc++.h>

using namespace std;

class gantt{
	public:
	void find(){
			int n;
			cout<<" Enter the no. of programme";
			cin>>n;
			
			vector<pair<int,pair<int,int>>> pro;
			
			
	
			for(int i=0;i<n;i++){
				cout<<" Enter the arrival time & end time "<<endl;
				int e,a;
				
				cin>>a>>e;
				pro.emplace_back(make_pair(e,make_pair(a,i+1)));
		
			}
				
			sort(pro.begin(),pro.end());
		show(n,pro);
	}
	
	private:
	void show(int n,vector<pair<int,pair<int,int>>> pro){
			float avg_wt=0;
		float avg_tat=0;
			int st[n], ft[n], wt[n], tat[n];
	
	st[0]=pro[0].second.first; ft[0]=pro[0].first,tat[0]=ft[0]-pro[0].second.first;
	avg_tat+=tat[0];

	for(int i=1;i<n;i++){
		st[i]=ft[i-1];
		ft[i]=st[i]+pro[i].first;
		tat[i]=ft[i]-pro[i].second.first;
		avg_tat+=tat[i];
	}
	for(int i=0;i<n;i++){
		wt[i]=tat[i]-pro[i].first;
		avg_wt+=wt[i];
	}
	cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
	cout<< "  pr		AT		ET		ST		FT		WT		TAT"<<endl;
	cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
	
	for(int i=0;i<n;i++){
		cout<<"| "<<"p"<<pro[i].second.second<<"	|	"<<pro[i].second.first<< "	|	"<<pro[i].first<< "	|	"<<st[i] <<"	|	"<<ft[i]<< "	|	"<<wt[i] <<"	|	"
		<<tat[i]<< "	|	"<<endl;
	}
	cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"average TAT= "<<avg_tat/n<<endl;
	cout<<"average WT= "<<avg_wt/n<<endl;
}
	
};



int main(){
	gantt g ;
	
	g.find();
	
	return 0;
}