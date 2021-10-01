#include<iostream>
#include<string>
#include<vector>
using namespace std;
string s1,s2;
bool dp(int i,int j,vector<vector<bool> > &memo,vector<vector<bool> > &sign)
{
	if(sign[i][j])
		return memo[i][j];
	if(i==0||j==0)
		return memo[i][j];
	else 
	{
		if(s1[i-1]==s2[j-1]||s1[i-1]=='?')
			memo[i][j]=dp(i-1,j-1,memo,sign);
		else if(s1[i-1]=='*')
			memo[i][j]=dp(i-1,j,memo,sign)|dp(i,j-1,memo,sign);
		else memo[i][j]=0;
	}
	sign[i][j]=1;
	return memo[i][j];
}
int main()
{
	cout<<endl<<"ENTER THE PARENT STRING  :  ";
	cin>>s1;
	cout<<endl<<endl<<"ENTER THE TEST STRING  :  ";
	cin>>s2;
	int l1=s1.length();
	int l2=s2.length();
	vector<vector<bool> > memo(l1+1,vector<bool> (l2+1,0));
	vector<vector<bool> > sign(l1+1,vector<bool> (l2+1,0));
	memo[0][0]=1;
	int k=0;
	while(k<l1&&s1[k]=='*')
		 memo[++k][0]=1;
	bool ans=dp(l1,l2,memo,sign);
	if(ans)
		cout<<endl<<endl<<"TEST STRING IS THE CHILD OF THE PARENT STRING !!";
	else cout<<endl<<endl<<"TEST STRING IS NOT THE CHILD OF THE PARENT STRING !!";
	cout<<endl<<endl;
}
