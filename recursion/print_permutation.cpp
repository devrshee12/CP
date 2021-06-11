#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back



void solve(string s, string asf)
{
	if(s.length() == 0)
	{
		cout<<asf<<endl;
		return;
	}

	for(int i=0;i<s.length();i++)
	{
		char c = s[i];
		string lpart = s.substr(0,i);
		string rpart = s.substr(i+1);
		string ros = lpart + rpart;
		solve(ros,asf + c);
	}

	

}


int main()
{
	string s;
	cin>>s;
	solve(s,"");
	
	
}
