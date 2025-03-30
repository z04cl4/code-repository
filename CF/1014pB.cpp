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
#define debug(z) cerr << #z << ' ' << z << '\n'
#define YES cout << "Yes" << '\n'
#define NO cout << "No" << '\n'
#define Bbicorz ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(NULL)
#define int long long
#define double long double

const int mod = 1e9 + 7; // INF = LLONG_MAX;//, INF = 998244353; 
const int base = 31;
const int N = 1e7 + 1;

int dx[4]{1, 0, -1, 0};
int dy[4]{0, 1, 0, -1};

inline void solve() {
	int n, m;
	cin >> n;
	string a, b;
	cin >> a >> b;
	bool f = 0;
	for (int i = 0; i < n; i++) {
		if(a[i] == '1') {
			f = 1;
			break;
		}
	}
	if(!f){
		cout << "YES\n";
		return;
	}
	

	int odd_a = 0, even_a = 0, odd_b = 0, even_b = 0;
	for(int i = 0; i < n; ++i){
		if(i & 1){
			odd_a += a[i] == '1';
		} else {
			even_a += a[i] == '1';
		}

		if(i & 1){
			odd_b += b[i] == '0';
		} else {
			even_b += b[i] == '0';
 		}
	}
	cout << (odd_a <= even_b && even_a <= odd_b ? "YES\n" : "NO\n"); 
}

signed main(){
	Bbicorz;
	int T = 1;
	cin >> T;
	while(T--) solve();
	return 0;
}