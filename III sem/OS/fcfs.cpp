#include <iostream>

using namespace std;

class gantt{
	public:
	void find(){
			int n;
			cout<<" Enter the no. of programme";
			cin>>n;
	
			int at[n], et[n];
	
			for(int i=0;i<n;i++){
				cout<<" Enter the arrival time & end time "<<endl;
				cin>>at[i]>>et[i];
		
			}
		show(n,at,et);
	}
	
	private:
	void show(int n,int at[],int et[]){
		float avg_wt=0;
		float avg_tat=0;
			int st[n], ft[n], wt[n], tat[n];
	
	st[0]=at[0]; ft[0]=et[0],tat[0]=ft[0]-at[0];
	avg_tat+=tat[0];

	for(int i=1;i<n;i++){
		st[i]=ft[i-1];
		ft[i]=st[i]+et[i];
		tat[i]=ft[i]-at[i];
		avg_tat+=tat[i];
	}
	for(int i=0;i<n;i++){
		wt[i]=tat[i]-et[i];
		avg_wt+=wt[i];
	}
	cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
	cout<< "  pr		AT		ET		ST		FT		WT		TAT"<<endl;
	cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
	
	for(int i=0;i<n;i++){
		cout<<"| "<<"p"<<i+1<<"	|	"<<at[i]<< "	|	"<<et[i]<< "	|	"<<st[i] <<"	|	"<<ft[i]<< "	|	"<<wt[i] <<"	|	"
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