#include <bits/stdc++.h>
using namespace std;
// this problem can be solved in O(n^3) time complexity with dynamic programming based approach
int sum(int freq[], int i, int j);

// definition of function that will recursively calculate the state values where state value represents
// cost of optimal binary search tree
int optimalCost(int freq[], int i, int j)
{
	if (j < i)
		return 0;
	if (j == i)
		return freq[i];
	
	int x = sum(freq, i, j);

	int t = INT_MAX;

	for (int r = i; r <= j; ++r)
	{
		int cost = optCost(freq, i, r - 1) +
				optCost(freq, r + 1, j);
		if (cost < min)
			min = cost;
	}
	
	return t + x;
}

int optimalSearchTree(int keys[],
					int freq[], int n)

	return optimalCost(freq, 0, n - 1);
}

int sum(int freq[], int i, int j)
{
	int s = 0;
	for (int k = i; k <= j; k++)
	s += freq[k];
	return s;
}

int main()
{
	int keys[] = {10, 12, 20};
	int freq[] = {34, 8, 50};
	int n = sizeof(keys) / sizeof(keys[0]);
	cout << "Cost of Optimal BST is "
		<< optimalSearchTree(keys, freq, n);
	return 0;
}
