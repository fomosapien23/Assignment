#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cout << "Enter the no. of process: ";
    cin >> n;

    vector< pair < int , int > > v;

    cout << "enter priority, arrival and execution time:" << endl;

    for (int i = 0; i < n; i++)
    {
        int p, e;
        cin >> p >> e;
        v.push_back({p, e});
    }

    

    priority_queue< pair<int, int>> pq;

    vector<vector<int>> ans;
    vector<bool>visit(n,0);
	
	int mini=-1;
	
		for(int i=0;i<n;i++){
			if(mini<v.second){
				mini=v.second;
			}
		}
   
        for (int i = 0; i < n; i++)
        {
            if (visit[i]==false && mini==pq.second)
            {
                pq.push({v[i].first, {v[i].second.first, v[i].second.second}});
                visit[i]=true;
                mini=
            }
        }
       
   

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int at = it.second.first;
        int et = it.second.second;
        int pr = it.first;
        t += et;
        int tat = t - at;
        int wt = tat - et;
        ans.push_back({pr, at, et, t, tat, wt});

        for (int i = 0; i < n; i++)
        {
            if (v[i].second.first != INT_MAX && v[i].second.first <= t)
            {
                pq.push({v[i].first, {v[i].second.first, v[i].second.second}});
                v[i].second.first = INT_MAX;
            }
        }
    }

    cout << "pri\tAT\tET\tCT\tTAT\tWT" << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << "\t" << ans[i][1] << "\t" << ans[i][2] << "\t" << ans[i][3] << "\t" << ans[i][4] << "\t" << ans[i][5] << "\t" << endl;
    }

    return 0;
}