#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define cerr if(1) cerr
#define all(v) v.begin(), v.end()
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define pii pair<int, int>
#define F first
#define S second
#define lowbit(x) (x & -x)
#define Bbicorz ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(NULL)
#define int long long
#define double long double

const int mod = 1e9 + 7; // INF = LLONG_MAX;//, INF = 998244353; 
const int base = 31;
const int N = 1e7 + 1;

int dx[4]{1, 0, -1, 0};
int dy[4]{0, 1, 0, -1};

inline void solve() {
	int n, k;
	cin >> n;
	vector<int> arr(n);
	for(int &i : arr) cin >> i;
	sort(all(arr));
	cout << arr[n - 1] - arr[0] << '\n';
}

signed main(){
	Bbicorz;
	int T = 1;
	cin >> T;
	while(T--) solve();
	return 0;
}