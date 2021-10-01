#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> g(101,99999);
vector<vector<int> > v(101,g);
int memo[101][101][101];
bool sign[101][101][101];
int par[101][101];
int dp(int i,int j,int k)
{
	if(sign[i][j][k])
		return memo[i][j][k];
	int ans,temp;
	if(k==0)
	{
		ans=v[i][j];
		par[i][j]=i;
	}
	else 
	{
		ans=dp(i,j,k-1);
		temp=dp(i,k,k-1)+dp(k,j,k-1);
		if(ans>temp)
		{
			ans=temp;
			par[i][j]=par[k][j];
		}
	}
	sign[i][j][k]=1;
	memo[i][j][k]=ans;
	return ans;
}
int main()
{
	int n,e,a,b,c;
  	cout<<"ENTER THE TOTAL NO OF VERTICES IN THE GRAPH  :  ";
	cin>>n;
	cout<<"ENTER THE TOTAL NO OF EDGES IN THE GRAPH  :  ";
	cin>>e;
	cout<<endl<<endl<<"ENTER THE EDGE DETAILS  :  ";
	int dis[101][101];
	for(int i=0;i<e;i++)
	{
  	 	cin>>a>>b>>c;
		v[a][b]=c;
		par[a][b]=a;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		    dis[i][j]=dp(i,j,n);

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<dis[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl<<endl<<"SOURCE	   "<<" DESTINATION      "<<"   DISTANCE	       "<<" PATH		\n\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1,x;j<=n;j++)
		{
			cout<<"  "<<i<<"	   	 "<<j<<"	       ";
			if(dis[i][j]<90000)
			{
				stack<int> st;
				st.push(j);
				x=j;
				if(x!=i)
				{
					while(x!=i)
					{
						st.push(par[i][x]);
						x=par[i][x];	
					}
				}
				else 
				{
					while(par[i][x]!=i)
					{
						st.push(par[i][x]);
						x=par[i][x];
					}
					st.push(par[i][x]);
				}
				cout<<"    "<<dis[i][j]<<"		       ";
				while(!st.empty())
				{
					int t=st.top();
					st.pop();
					cout<<t;
					if(st.size())
					cout<<"---->";
				}
			}
			else cout<<"UNREACHABLE";
			cout<<endl;
		}
	}
}
