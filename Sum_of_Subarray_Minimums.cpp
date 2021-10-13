#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
Input: arr = [3,1,2,4]
Output: 17
Explanation:
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
*/

class Solution {
public:
	int sumSubarrayMins(vector<int>& arr) {
		stack<long > s1, s2;
		int n = arr.size();
		vector<long > next_Smaller(n), pre_Smaller(n);
		for (int i = 0; i < n; ++i) {
			next_Smaller[i] = n - i - 1;
			pre_Smaller[i] = i;
		}
		for (int i = 0; i < n; ++i) {
			while (!s1.empty() && arr[s1.top()] >= arr[i]) {
				next_Smaller[s1.top()] = i - s1.top() - 1;
				s1.pop();
			}
			s1.push(i);
		}
		for (int i = n - 1; i >= 0; --i) {
			while (!s2.empty() && arr[s2.top()] > arr[i]) {
				pre_Smaller[s2.top()] = s2.top() - i - 1;
				s2.pop();
			}
			s2.push(i);
		}
		long ans = 0, mod = 1e9 + 7;
		for (int i = 0; i < n; ++i) {
			ans += (long)arr[i] * (pre_Smaller[i] + 1) * (next_Smaller[i] + 1);
			ans %= mod;
		}
		return ans;
	}
};

int main() {
	ll n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	Solution ob;
	cout << ob.sumSubarrayMins(arr) << '\n';
	return 0;
}
