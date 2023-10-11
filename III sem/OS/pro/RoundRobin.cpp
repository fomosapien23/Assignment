#include <bits/stdc++.h>

using namespace std;

int main()
{

    int time;
    cout << "Enter the time slice: ";
    cin >> time;

    int n;
    cout << "Enter the no. of process: ";
    cin >> n;

    vector<pair<int, int>> v;
    
    vector<bool> visit(n,0);

    cout << "enter arrival and execution time:" << endl;

    for (int i = 0; i < n; i++)
    {
        int a, e;
        cin >> a >> e;
        v.push_back({a, e});
    }

    int t = 0;

    queue<pair<int, pair<int, int>>> q;

    vector < vector<int>> ans;

    while (q.empty() && t < 10)
    {
        for (int i = 0; i < n; i++)
        {
            if (visit[i]==false && v[i].second > 0 && v[i].first <= t)
            {
                q.push({i + 1, {v[i].first, v[i].second}});
                visit[i]=true;;
            }
        }
        
        if (q.empty())
            t++;
    }

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        int at = it.second.first;
        int et = it.second.second;
        int pr = it.first;
        if(et>=time){
        	t += time; 
			et-=time;       	
		}
        else{
        	t+=et;
			et-=time;	
		}
        

        if(et <=0){
        	
        	
	        int tat = t - at;
	        int wt = tat - at;
	        
			        for (int i = 0; i < n; i++)
		        {
		            if (visit[i]==false && v[i].second > 0 && v[i].first <= t)
		            {
		                q.push({i + 1, {v[i].first, v[i].second}});
		                visit[i]=true;;
		            }
		        }
	        ans.push_back({pr, at, t, tat, wt});
        	
		}else{
		
			
				for (int i = 0; i < n; i++)
	        {
	            if (visit[i]==false && v[i].second > 0 && v[i].first <= t)
	            {
	                q.push({i + 1, {v[i].first, v[i].second}});
	                visit[i]=true;;
	            }
	        }
        	q.push({it.first,{it.second.first,it.second.second-time}});
		}

        
    }
    
    cout << "pro\tAT\tCT\tTAT\tWT" << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << "\t" << ans[i][1] << "\t" << ans[i][2] << "\t" << ans[i][3] << "\t" << ans[i][4]  << "\t" << endl;
    }

    return 0;
}