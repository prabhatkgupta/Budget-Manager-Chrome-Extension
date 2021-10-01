#include<iostream>
#include<vector>
using namespace std;
int dp(int i,vector<int> &memo,vector<bool> &sign)
{
	if(sign[i])
		return memo[i];
	for(int j=0;j<i;j++)
		memo[i]+=dp(j,memo,sign)*dp(i-j-1,memo,sign);
	sign[i]=1;
	return memo[i];
}
int main()
{
	int n;
	cout<<endl<<endl<<"ENTER THE NO OF KEYS  :  ";
	cin>>n;
	vector<int> memo(n+1,0);
	vector<bool> sign(n+1,0);
	memo[0]=1;
	sign[0]=1;
	cout<<endl<<endl<<"TOTAL NO OF BST POSSIBLE ARE  :  "<<dp(n,memo,sign)<<endl<<endl;
}
		
