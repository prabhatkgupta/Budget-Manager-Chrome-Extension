#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string s1,s2;
	cout<<"ENTER THE FIRST STRING  :  ";
	cin>>s1;
	cout<<endl<<endl<<"ENTER THE SECOND STRING  :  ";
	cin>>s2;
	int l1,l2,storei,storej;
	l1=s1.length();
	l2=s2.length();
	vector<vector<int> > v(l1+1,vector<int> (l2+1,0));
	int mx=0;
	for(int i=1;i<=l1;i++)
	{
		for(int j=1;j<=l2;j++)
		{
			if(s1[i-1]==s2[j-1])
				v[i][j]=1+v[i-1][j-1];
			else v[i][j]=0;
			if(v[i][j]>mx)
			{
				storei=i;
				storej=j;
				mx=v[i][j];
			}
		}
	}
	cout<<endl<<endl<<"LENGTH OF LONGEST COMMON SUBSTRING BETWEEN THEM  :  "<<mx;
	string ans;
	for(int i=1;i<=mx;i++)
	{
		ans=s1[storei-1]+ans;
		storei--;
	}
	cout<<endl<<endl<<"LONGEST COMMON SUBSTRING IS  :  "<<ans<<endl<<endl;
}
