#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main()
{
	int n,e,a,b,c;
  	cout<<"ENTER THE TOTAL NO OF VERTICES IN THE GRAPH  :  ";
	cin>>n;
	vector<long int> g(n+1,99999);
	vector<vector<long int> > v(n+1,g);
	vector<int> ga(n+1,0);
	vector<vector<int> > par(n+1,ga);
	cout<<"ENTER THE TOTAL NO OF EDGES IN THE GRAPH  :  ";
	cin>>e;
	cout<<endl<<endl<<"ENTER THE EDGE DETAILS  :  ";
	for(int i=0;i<e;i++)
	{
  	 	cin>>a>>b>>c;
		v[a][b]=c;
		par[a][b]=a;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(v[i][j]>v[i][k]+v[k][j])
				{
					v[i][j]=v[i][k]+v[k][j];
					if(k==1) 
						par[i][j]=1;
					else par[i][j]=par[k][j];
				}
	cout<<"\n\nSOURCE     DESTINATION        DISTANCES            PATH\n\n";	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int x;
			if(v[i][j]<90000)
			{
				stack<int> pk;
				pk.push(j);
				x=j;
				cout<<i<<"  	        "<<j<<"	          "<<v[i][j]<<"	          "; 
				if(x!=i)
				{
					while(x!=i)
					{
						pk.push(par[i][x]);
						x=par[i][x];
					}
				}
				else 
				{
					while(par[i][x]!=i)
					{
						pk.push(par[i][x]);
						x=par[i][x];
					}
					pk.push(par[i][x]);
				}
				while(!pk.empty())
				{
					cout<<pk.top();
					pk.pop();
					if(pk.size())
						cout<<"--->";
				}
				cout<<endl;
			}
			else cout<<i<<"  	        "<<j<<"   	     UNREACHABLE\n";
		}
	}
}
