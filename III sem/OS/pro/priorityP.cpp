#include<bits/stdc++.h>
using namespace std;           
int main()
{
    int n=0;cout<<"enter the value of n "<<endl;
    cin>>n;
    priority_queue<pair<pair<int,int>,pair<int,int>>,vector<pair<pair<int,int>,pair<int,int>>>,greater<pair<pair<int,int>,pair<int,int>>>> q;
    vector<pair<int,pair<int,int>>> v;
    int x=0,y=0,z=0;
    cout<<"enter AT, ET and P"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y>>z;
        q.push({{x,y},{z,i+1}});
        v.push_back({x,{y,z}});
    }
    unordered_map<int,pair<int,int>> m;
    
    stack<pair<pair<int,int>,pair<int,int>>> st;
    
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> qe;
    int s=0,siz=n;
    while(!q.empty()||!qe.empty())
    {
        for(int i=0;i<siz;i++)
        {
            pair<pair<int,int>,pair<int,int>> v=q.top();
            if(v.first.first<=s){qe.push({v.second.first,{v.second.second,v.first.second}});siz--;}
            else
            {st.push(q.top());}q.pop();
        }
        while(!st.empty())
        {
            q.push(st.top());st.pop();
        }

        if(m.find(qe.top().second.first)==m.end()){m[qe.top().second.first].first=s;}
        if(siz==0)
        {
        	cout<<s;
            s+=qe.top().second.second;
            cout<<" p"<<qe.top().second.first<<" "<<s<<endl;
            m[qe.top().second.first].second=s;
            qe.pop();
        }
        else{
        	cout<<s;
            s++;
            int r3=qe.top().second.second-1,r1=qe.top().first,r2=qe.top().second.first;qe.pop();
            cout<<" p"<<r2<<" "<<s<<endl;
            if(r3!=0)
            qe.push({r1,{r2,r3}});
            else{
            	m[r2].second=s;
			}
			
			
            for(int i=0;i<siz;i++)
            {
                pair<pair<int,int>,pair<int,int>> v=q.top();
                if(v.first.first<=s){qe.push({v.second.first,{v.second.second,v.first.second}});siz--;}
                else
                {st.push(q.top());}q.pop();
            }
            while(!st.empty())
            {
                q.push(st.top());st.pop();
            }
		
            
        }
    }
    float AWT=0,ATAT=0;
    cout<<"\tAT\tET\tP\tST\tFT\tWT\tTAT"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<"P"<<i<<"\t"<<v[i-1].first<<"\t"<<v[i-1].second.first<<"\t"<<v[i-1].second.second<<"\t"<<m[i].first<<"\t"<<m[i].second<<"\t"<<m[i].second-v[i-1].first-v[i-1].second.first<<"\t"<<m[i].second-v[i-1].first<<endl;
		AWT+=m[i].second-v[i-1].first-v[i-1].second.first;ATAT+=m[i].second-v[i-1].first;
    }
    cout<<"AWT is"<<AWT/n<<"\t AWT time"<<ATAT/n<<endl;
    return 0;
}

