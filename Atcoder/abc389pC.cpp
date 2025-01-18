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
int n;

signed main() {
	Bbicorz;
	int a, b, dis = 0;
	queue<int> q;
	deque<int> pre;
	cin >> n;
	while(n--){
		cin >> a;
		if(a == 1){
			cin >> b;
			q.push(b);
			if(pre.size()) pre.pb(pre.back() + b);
			else pre.pb(b);
		}else if(a == 2){
			int k = q.front();
			q.pop();
			pre.pop_front();
			dis += k;
		}else{
			cin >> b;
			if(!pre.size()) continue;
			cout << (b - 2 < 0 ? 0 : pre[b - 2] - dis) << '\n';
		}
	}
	return 0;
}