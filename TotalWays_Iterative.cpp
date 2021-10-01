#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n,m;
	cout<<endl<<"ENTER THE TOTAL NO OF ROWS  :  ";
	cin>>n;
	cout<<endl<<endl<<"ENTER THE TOTAL NO OF COLUMNS  :  ";
	cin>>m;
	vector<vector<int> > ans(n,vector<int> (m,0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i==0&&j==0)
				ans[i][j]=1;
			else if(i==0)
				ans[i][j]=ans[i][j-1];
			else if(j==0)
				ans[i][j]=ans[i-1][j];
			else ans[i][j]=ans[i-1][j]+ans[i][j-1];
		}
	}
	cout<<endl<<endl<<"TOTAL WAYS TO REACH BOTTOM RIGHT ARE  :  "<<ans[n-1][m-1];
	cout<<endl<<endl;
}
