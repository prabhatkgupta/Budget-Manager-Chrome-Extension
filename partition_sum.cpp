#include <bits/stdc++.h>
using namespace std;

bool SubSum(int arr[], int n, int sum)
{
	// handle base cases first
	if (sum == 0)
		return true;
	if (n == 0 && sum != 0)
		return false;
  
	if (arr[n - 1] > sum)
		return SubSum(arr, n - 1, sum);
  
	return SubSum(arr, n - 1, sum)
		|| SubSum(arr, n - 1, sum - arr[n - 1]);
}

bool findPartiion(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];

  // check if odd
	if (sum % 2 != 0)
		return false;

	return SubSum(arr, n, sum / 2);
}
// main function
int main()
{
	int arr[] = { 3, 1, 5, 9, 12 };
	int n = sizeof(arr) / sizeof(arr[0]);

	if (findPartiion(arr, n) == true)
		cout << "Can be divided into two subsets of equal sum";
	else
		cout << "Can not be divided into two subsets f equal sum";
	return 0;
}
