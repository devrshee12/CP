#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define maxi 3E5+5


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
	if(c%ans != 0)//to check whether solution is exist or not
	{
		cout<<"NO SOLUTION"<<endl;
		return;
	}
	x *= c/ans;//convert ex_euclid algo into linear diophantine equation(for finding general solutions)(only finds one solution)
	y *= c/ans;//convert ex_euclid algo into linear diophantine equation(for finding general solutions)(only finds one solution)
	if(a<0)x = -x;
	if(b<0)y = -y;
	// cout<<x<<" "<<y<<endl;
	int l = (-1)*x;
	int t1 = (l*ans)/b;//checking k limits for only positive solution
	int t2 = (y*ans)/a;//checking k limits for only positive solution
	// cout<<t1<<" "<<t2<<endl;
	// ll c = 0;
	int count = 0;
	// for positive solution lies between t1 < k < t2

	//Xall = x + (k*b)/g;
	//Yall = y - (k*a)/g;
	for(ll i=t1+1;i<t2;i++)
	{
		count++;//to count how many positive solution does exist
	}
	cout<<count<<endl;
	for(ll i=t1+1;i<t2;i++)// for positive solution lies between t1 < k < t2
	{
		int mainx = x + (i*b)/ans;//Xall = x + (k*b)/g;
		int mainy =y - (i*a)/ans;//Yall = y - (k*a)/g;
		cout<<mainx<<" "<<mainy<<endl;//to print positive solution of equation
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
