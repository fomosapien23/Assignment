#include <bits\stdc++.h>

using namespace std;


string solve(string &st, int r){
	
	int i=0;
	bool tr=0;
	vector<string> temp(r,"");
	
	for(auto ch: st){
		temp[i]+=ch;
		
		if(tr){
			if(i==0){
				i++;
				tr=false;
			}
			else{
				i--;
			}
		}
		else {
			if(i==r-1){
				i--;
				tr=true;
				
			}else{
				i++;
			}
		}
	}
	string ans="";
	for(auto &s: temp){
		ans+=s;
	}
	return ans;
	
}


int main(){
	string st;
	cout<<"Enter the string :";
	cin>>st;
	
	int r;
	cout<<"enter the no. of row: ";
	cin>>r;
	
	cout<<"string is :"<<solve(st,r);
	return 0;
}