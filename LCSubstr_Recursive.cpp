#include<iostream>
#include<string>
#include<vector>
using namespace std;
int mx=0;
int memo[100][100]={0};
bool sign[100][100]={0};
string s1,s2;
int storei,storej;
int dp(int i,int j)
{
	if(sign[i][j])
		return memo[i][j];
	int val;
	if(i==0||j==0)
		val=0;
	else if(s1[i-1]==s2[j-1])
		val=dp(i-1,j-1)+1;
	else val=0;
	memo[i][j]=val;
	sign[i][j]=1;
	if(memo[i][j]>mx)
	{
		mx=memo[i][j];
		storei=i;
		storej=j;
	}
	return memo[i][j];
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
	for(int i=1;i<=l1;i++)
		for(int j=1;j<=l2;j++)
			int temp=dp(i,j);
	cout<<endl<<endl<<"LENGTH OF LONGEST COMMON SUBSTRING BETWEEN THEM  :  "<<mx;
	string ans;
	for(int i=1;i<=mx;i++)
	{
		ans=s1[storei-1]+ans;
		storei--;
	}
	cout<<endl<<endl<<"LONGEST COMMON SUBSTRING IS  :  "<<ans<<endl<<endl;
}
