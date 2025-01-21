#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define cerr if(1) cerr
#define all(v) v.begin(), v.end()
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define lowbit(x) (x & -x)
#define debug(z) cerr << "OuO.........? " << z << '\n';
#define Bbicorz ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(NULL)
#define int long long
#define double long double
const int MAX = 1e9 + 7, mod = 998244353;
const int p = 37;

inline void solve(){
	int n, x, y, sum = 0;
	cin >> n >> x >> y;
	vector<int> arr(n);
	for(int i = 0; i < n; ++i) cin >> arr[i], sum += arr[i];
	sort(all(arr));
	int ans = 0;
	for(int i = 0; i < n; ++i){
		int l = sum - y - arr[i];
		int r = sum - x - arr[i];
		auto a = lower_bound(arr.begin() + i + 1, arr.end(), l);
		auto b = upper_bound(arr.begin() + i + 1, arr.end(), r);
		ans += b - a;
	}
	cout << ans << '\n';
}

signed main(){
	Bbicorz;
	int T = 1;
	cin >> T;
	while(T--) solve();
	return 0;
}