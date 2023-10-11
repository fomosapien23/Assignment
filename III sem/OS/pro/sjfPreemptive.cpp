#include<bits/stdc++.h>
using namespace std;


bool cmp(vector<int> &a,vector<int> &b)
{
	return a[1]<b[1];
}

int main()
{
int n;
	cout<<"Enter the number of processes:";
	cin>>n;
	
//	                                          0      1              2               3         4              5
//	each process will have respective info : pid arrival time execution time, finish time, waiting time, turnaround time
	vector<vector<int>> process(n,vector<int>(6,0));
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	double avgTat=0;

	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter the arrival and execution time for process "<<i<<" : ";
		cin>>process[i][1]>>process[i][2];
		process[i][0]=i;
	}
	unordered_map<int,int>  mp;//arrival time ,pid
	for(auto it:process)
	{
		mp[it[1]]=it[0];
	}
	
//	for shortest job first we need to sort the processes on the basis of there execution time
//	sort(process.begin(),process.end(),cmp);
	
//	for(int i=0;i<n;i++)
//	{
//		cout<<process[i][0]<<" "<<process[i][1]<<" "<<process[i][2]<<" "<<process[i][3]<<endl;
//	}
	
	vector<string> ganttChart;
	
	int time=0;
	while(!mp.count(time))
	{
		time++;
		ganttChart.push_back("idle");
	}
//	now time is the first arrival time
	int firstProET=process[mp[time]][2];
	pq.push({firstProET,mp[time]});
	
	while(!pq.empty())
	{
		auto t=pq.top();
		int et=t.first;
		int id=t.second;
		pq.pop();
		et=et+time;
		while(time<et)
		{
			time++;	
			string p=to_string(process[id][0]);
			p="P"+p;
			ganttChart.push_back(p);
			if(pq.top().first<(et-time))
			{
				pq.push({et-time,id});
				break;
			}
			if(mp.count(time))
			{
				pq.push({process[mp[time]][2],mp[time]});
				pq.push({et-time,id});
				break;
			}
		
		}
//		finish time
		process[id][3]=time;
//		turn around time
		process[id][5]=time-process[id][1];
//		waiting time
		process[id][4]=process[id][5]-process[id][2];
		
//		avgTat+=process[id][5];
	}
	
	cout<<"\tTable\n";
	cout<<"Pid\tAT\tET\tFT\tWT\tTAT\n";
	for(int j=0;j<n;j++)
	{
		cout<<" "<< process[j][0]<<"\t"<<process[j][1]<<"\t"<<process[j][2]<<"\t"<<process[j][3]<<"\t"<<process[j][4]<<"\t"<<process[j][5]<<endl;
	}
	cout<<"\nGANTT CHART\n";
//	for(int j=0;j<ganttChart.size();j++)
//	{
//		cout<<" "<<j<<" ";
//	}
//	cout<<endl;
	for(int j=0;j<ganttChart.size();j++)
	{
		
		cout<<ganttChart[j]<<"|"<<" ";
	}
	for(int i=0;i<n;i++)
	{
		avgTat+=process[i][5];
	}
	cout<<"\nAverage Turn Around Time = "<<avgTat/n;
	return 0;
}