#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define maxi 3E5+5

//using extended euclid algorithum
//find only positive integer solution
//linear diophantnie equation

//how to implement extended euclid algo and how to find only positive integer solution



int gcd(int a, int b)
{
	if(b == 0)return a;
	return gcd(b,a%b);
}

int ex_gcd(int a, int b, int &x, int &y)	
{
	if(b==0)
	{
		x = 1;
		y = 0;
		return a;
	}

	int x1,y1;
	int d = ex_gcd(b,a%b,x1,y1);
	x = y1;
	y = x1 - y1*(a/b);
	return d;

}


void solve()
{	
	int a;
	cin>>a;
	int b;
	cin>>b;
	int c;
	cin>>c;
	int x,y;
	int ans = ex_gcd(a,b,x,y);
	// cout<<x<<" "<<y<<endl;
	// // int x1 = (x*c)/ans;
	// // int x2 = (y*c)/ans;
	if(c%ans != 0)
	{
		cout<<"NO SOLUTION"<<endl;
		return;
	}
	x *= c/ans;
	y *= c/ans;
	if(a<0)x = -x;
	if(b<0)y = -y;
	// cout<<x<<" "<<y<<endl;
	int l = (-1)*x;
	int t1 = (l*ans)/b;
	int t2 = (y*ans)/a;
	// cout<<t1<<" "<<t2<<endl;
	// ll c = 0;
	int count = 0;
	for(ll i=t1+1;i<t2;i++)
	{
		count++;
	}
	cout<<count<<endl;
	for(ll i=t1+1;i<t2;i++)
	{
		int mainx = x + (i*b)/ans;
		int mainy =y - (i*a)/ans;
		cout<<mainx<<" "<<mainy<<endl;
		// count++;

	}

	// cout<<count<<endl;
	




	

	
}




int main()
{
	// ll t;
	// cin>>t;
 
	// while(t--)
	// {
		solve();

	// }

	





	
	
}
