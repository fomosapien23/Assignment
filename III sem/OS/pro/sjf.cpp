#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cout << "Enter the no. of process: ";
    cin >> n;

    vector<pair<int, int>> v;

    cout << "enter arrival and execution time:" << endl;

    for (int i = 0; i < n; i++)
    {
        int a, e;
        cin >> a >> e;
        v.push_back({a, e});
    }

    int t = 0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    while (pq.empty() && t < 10)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i].second != INT_MAX && v[i].first <= t)
            {
                pq.push({v[i].second, {v[i].first, i + 1}});
                v[i].second = INT_MAX;
            }
        }
        if (pq.empty())
            t++;
    }

    vector<vector<int>> ans;

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int at = it.second.first;
        int et = it.first;
        int pr = it.second.second;
        t += et;
        int tat = t - at;
        int wt = tat - et;
        ans.push_back({pr, at, et, t, tat, wt});

        for (int i = 0; i < n; i++)
        {
            if (v[i].second != INT_MAX && v[i].first <= t)
            {
                pq.push({v[i].second, {v[i].first, i + 1}});
                v[i].second = INT_MAX;
            }
        }
    }

    cout << "pro\tAT\tET\tCT\tTAT\tWT" << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << "\t" << ans[i][1] << "\t" << ans[i][2] << "\t" << ans[i][3] << "\t" << ans[i][4] << "\t" << ans[i][5] << "\t" << endl;
    }

    return 0;
}