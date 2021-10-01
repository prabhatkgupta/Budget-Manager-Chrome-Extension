#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cout<<endl<<endl<<"ENTER THE NO OF KEYS  :  ";
	cin>>n;
	vector<int> ans(n+1);
	ans[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
			ans[i]+=ans[j]*ans[i-j-1];
	}
	cout<<endl<<endl<<"TOTAL NO OF BST POSSIBLE ARE  :  "<<ans[n]<<endl<<endl;
}
		
