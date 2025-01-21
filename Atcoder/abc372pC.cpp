#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define cerr if(false) cerr
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
	int n, q, a, cnt = 0;
	char x;
	string s;
	cin >> n >> q >> s;
	for(int i = 0; i < n - 2; ++i){
		if(s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C'){
			++cnt;
		}
	}
	cerr << cnt << '\n';
	while(q--){
		cin >> a >> x;
		a--;
		if(s[a - 1] == 'A' && s[a] == 'B' && s[a + 1] == 'C' && x != 'B' || s[a] == 'A' && s[a + 1] == 'B' && s[a + 2] == 'C' && x != 'A' || s[a - 2] == 'A' && s[a - 1] == 'B' && s[a] == 'C' && x != 'C') --cnt;
		if(s[a - 1] == 'A' && s[a] != 'B' && s[a + 1] == 'C' && x == 'B' || s[a] != 'A' && s[a + 1] == 'B' && s[a + 2] == 'C' && x == 'A' || s[a - 2] == 'A' && s[a - 1] == 'B' && s[a] != 'C' && x == 'C') ++cnt;
		s[a] = x;
		cout << cnt << '\n';
	}
}

signed main(){
	Bbicorz;
	int T = 1;
	// cin >> T;
	while(T--) solve();
	return 0;
}