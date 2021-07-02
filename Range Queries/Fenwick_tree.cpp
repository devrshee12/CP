#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define maxi 3E5+5
#define vi vector<ll>
#define vint vector<int>
//fenwick tree

int fen[100005];//global 

void update(int inx, int val, int n)
{
	while(inx <= n)
	{
		fen[inx] += val;
		inx = inx + (inx & ~inx);
	}
}

int sum(int ind)
{
	int s = 0 ;
	while(ind > 0)
	{
		s += fen[ind];
		ind = ind - (ind & ~ind);
	}

	return s;
}

void quaries()
{
	int n,q;
	cin>>n>>q;

	int a[n+1];

	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		update(i,a[i],n);
	}

	while(q--)
	{
		int type;
		cin>>type;

		if(type == 1)
		{
			int ind,val;
			cin>>ind>>val;
			update(ind,val);
		}
		else
		{
			int l,r;
			cin>>l>>r;
			cout<<sum(r) - sum(l-1)<<endl;
		}
	}
}


void countinversions()
{
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		freq[a[i]]++;
		update(a[i],1,n);

	}

	int cnt = 0;
	for(int i=1;i<=n;i++)
	{
		freq[a[i]]--;
		update(a[i],-1,n);
		cnt += sum(a[i]-1);

	}

	cout<<cnt<<endl;
}


//2D FENWICK TREE

int fen[1025][1025];//global;

void update2D(int fenno, int ind, int val)
{
	while(ind <= n)
	{
		fen[fenno][ind] += val;
		ind = ind + (ind & ~ind);
	}
}

int sum(int fenno ,int ind)
{
	int s=0 ;
	while(ind > 0)
	{
		s += fen[fenno][ind];
		ind = ind - (ind & ~ind);
	}

	return s;
}

void matrixsum()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		//clean ans use;

		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				fen[i][j] = 0;
			}
		}

		while(true)
		{
			string s;
			cin>>s;
			if(s == "END") return;
			else if(s == "SET")
			{
				int x,y,val;
				cin>>x>>y>>val;

				x += 1,y += 1; // for 1 base indexing 
				update2D(x,y,val);
			}
			else
			{
				int x1,y1,x2,y2;
				cin>>x1>>x2>>y1>>y2;

				x1 += 1, x2 += 1; // for 1 base indexing
				y1 += 1, y2 += 1;

				int s = 0;
				for(int fenno = x1;fenno <= x2;fenno++)
				{
					s += sum(fenno,y2) - sum(fenno,y1-1);
				}

				cout<<s<<endl;
			}
		}
	}
}
