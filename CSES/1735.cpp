#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define Bbicorz ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(NULL)
#define int long long

struct Segment_tree{
	
	struct Node{
		int sum, add, set;
		bool flag;
	};

	vector<int> arr;
	vector<Node> seg;
	
	inline void init(int n){
		arr.resize(n + 1);
		seg.resize(4 * n + 5);
	}
	
	inline void build(int l, int r, int idx){
		if(l == r) return seg[idx] = {arr[l], 0, 0, 0}, void();
		int mid = l + r >> 1;
		build(l, mid, idx << 1);
		build(mid + 1, r, idx << 1 | 1);
		seg[idx].sum = seg[idx << 1].sum + seg[idx << 1 | 1].sum; 
	}
	
	inline void Set_number(int idx, int val, int m){
		seg[idx].sum = val * m;
		seg[idx].set = val;
		seg[idx].add = 0;
		seg[idx].flag = 1;
	}

	inline void addtag(int idx, int val, int m){
		seg[idx].sum += val * m;
		seg[idx].add += val;
	}
	
	inline void push(int idx, int sz){
		if(seg[idx].flag){
			Set_number(idx << 1, seg[idx].set, sz + 1 >> 1);
			Set_number(idx << 1 | 1, seg[idx].set, sz >> 1);
			seg[idx].flag = 0;
		}
		if(seg[idx].add) {
			addtag(idx << 1, seg[idx].add, sz + 1 >> 1);
			addtag(idx << 1 | 1, seg[idx].add, sz >> 1);
		}
		seg[idx].add = 0;
	}

	inline void update(int l, int r, int ql, int qr, int idx, int val){
		if(l >= ql && r <= qr) return addtag(idx, val, r - l + 1);
		int mid = l + r >> 1;
		push(idx, r - l + 1);
		if(qr <= mid) update(l, mid, ql, qr, idx << 1, val);
		else if(ql > mid) update(mid + 1, r, ql, qr, idx << 1 | 1, val);
		else update(l, mid, ql, mid, idx << 1, val), update(mid + 1, r, mid + 1, qr, idx << 1 | 1, val);
		seg[idx].sum = seg[idx << 1].sum + seg[idx << 1 | 1].sum;
	}

	inline void Set(int l, int r, int ql, int qr, int idx, int val){
		if(l >= ql && r <= qr) return Set_number(idx, val, r - l + 1);
		int mid = l + r >> 1;
		push(idx, r - l + 1);
		if(qr <= mid) Set(l, mid, ql, qr, idx << 1, val);
		else if(ql > mid) Set(mid + 1, r, ql, qr, idx << 1 | 1, val);
		else Set(l, mid, ql, mid, idx << 1, val), Set(mid + 1, r, mid + 1, qr, idx << 1 | 1, val);
		seg[idx].sum = seg[idx << 1].sum + seg[idx << 1 | 1].sum;
	}

	inline int query(int l, int r, int ql, int qr, int idx){
		if(l >= ql && r <= qr) return seg[idx].sum;
		int mid = l + r >> 1;
		push(idx, r - l + 1);
		if(qr <= mid) return query(l, mid, ql, qr, idx << 1);
		else if(ql > mid) 	return query(mid + 1, r, ql, qr, idx << 1 | 1);
		return query(l, mid, ql, mid, idx << 1) + query(mid + 1, r, mid + 1, qr, idx << 1 | 1);
	}

};

inline void solve() {
	int n, q, a, b, c, k;
	cin >> n >> q;
	Segment_tree f;
	f.init(n);
	for(int i = 1; i <= n; ++i) cin >> f.arr[i];
	f.build(1, n, 1);
	for(int i = 0; i < q; ++i){
		cin >> a;
		if(a == 1){
			cin >> b >> c >> k;
			f.update(1, n, b, c, 1, k);
		} else if(a == 2){
			cin >> b >> c >> k;
			f.Set(1, n, b, c, 1, k);
		} else {
			cin >> b >> c;
			cout << f.query(1, n, b, c, 1) << '\n';
		}
	}
}

signed main() {
	Bbicorz;
	int T = 1;
	// cin >> T;
	while (T--) solve();
	return 0;
}