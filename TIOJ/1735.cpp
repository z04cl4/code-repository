#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")

using namespace std;

#define all(v) v.begin(), v.end()
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define lowbit(x) (x & -x)
#define debug cerr << "OuO.........?\n";
#define Bbicorz ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(NULL)
#define int long long
const int mod = 1e9 + 7; //mod2 = 1e9 + 9;
const int p = 37;// p2 = 31; 

inline int fpow(int a, int b, int mod){
	int re = 1;
	for(; b; b >>= 1, a = (a * a) % mod){
		if(b & 1) re = (re * a) % mod;
	}
	return re;
}

signed main(){
	Bbicorz;
	string s;
	int k;
	while(cin >> k){
		cin >> s;
		int n = s.size();
        vector<int> pre(n + 1);

		for (int i = 1; i <= n; ++i) {
			pre[i] = (pre[i - 1] * p % mod + s[i - 1]) % mod;
		}
		int ans = 0;
		int fp = fpow(p, k, mod);
		for(int i = k; i + k <= n; ++i){
			int hash1 = (pre[i] - pre[i - k] * fp % mod + mod) % mod;
			int hash2 = (pre[i + k] - pre[i] * fp % mod + mod) % mod;
			if(hash1 == hash2){
				++ans;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}