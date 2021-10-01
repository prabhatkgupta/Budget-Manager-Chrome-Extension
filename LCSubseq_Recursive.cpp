#include<iostream>
#include<vector>
#include<string>
using namespace std;
string s1,s2;
bool mark[100][100]={0};
int ans[100][100]={0};
int dp(int n,int m)
{
	if(mark[n][m])
		return ans[n][m];
	if(n==0||m==0)
		return 0;
	if(s1[n-1]==s2[m-1])
		ans[n][m]=dp(n-1,m-1)+1;
	else ans[n][m]=max(dp(n-1,m),dp(n,m-1));
	mark[n][m]=1;
	return ans[n][m];
}
int main()
{
	cout<<"ENTER THE FIRST STRING  :  ";
	cin>>s1;
	cout<<endl<<endl<<"ENTER THE SECOND STRING  :  ";
	cin>>s2;
	int l1,l2;
	l1=s1.length();
	l2=s2.length();
	cout<<endl<<endl<<"LENGTH OF LONGEST COMMON SUBSEQUENCE IS  :  "<<dp(l1,l2);
	cout<<endl<<endl<<"LONGEST COMMON SUBSEQUENCE IS  :  ";
	vector<bool> flag(l1+1,0);
	int a=l1,b=l2;
	while(a&&b&&ans[a][b])
	{
		if(dp(a,b)!=dp(a-1,b)&&dp(a,b)!=dp(a,b-1))
		{
			flag[a-1]=1;
			a--;
			b--;
		}
		else if(dp(a,b)==dp(a,b-1))
			b--;
		else a--;
	}
	for(int i=0;i<l1;i++)
		if(flag[i])
			cout<<s1[i]<<" ";
}
	
	
