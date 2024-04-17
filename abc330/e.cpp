#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 42
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif
#define rep1(a) for (int i = 0; i < a; i++)
#define rep2(i, a) for (int i = 0; i < a; i++)
#define rep3(i, a, b) for (int i = a; i < b; i++)
#define rep4(i, a, b, c) for (int i = a; i < b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define pb emplace_back
using namespace std;
template <typename T, typename T2> void cmin(T &x, const T2 &y) {
  x = x < y ? x : y;
}
template <typename T, typename T2> void cmax(T &x, const T2 &y) {
  x = x > y ? x : y;
}
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
template <class T> using vc = vector<T>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
mt19937 rng(time(NULL));
const int inf = 1000000000;
const ll lnf = 1000000000000000000;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define fi first
#define se second

const int N = 262145;
int c[N];

void upd(int x, int y) {
  x += 1;
  while (x < N) {
    c[x] += y;
    x += x & -x;
  }
  return;
}

int mex() {
  int r = 0;
  for (int i = 18; i >= 0; i--) {
    if (c[r | (1 << i)] == (1 << i)) {
      r |= 1 << i;
    }
  }
  return r;
}

map<int, int> cnt;
void add(int x, int v) {
  cnt[x] += v;
  if (v == 1 && cnt[x] == 1) {
    if (x + 1 < N)
      upd(x, 1);
  }
  if (v == -1 && cnt[x] == 0) {
    if (x + 1 < N)
      upd(x, -1);
  }
}

void solve() {
  int n, q;
  cin >> n >> q;
  vi a(n);
  rep(i, n) cin >> a[i];
  rep(i, n) add(a[i], 1);
  while (q--) {
    int i, x;
    cin >> i >> x;
    i--;
    add(a[i], -1);
    a[i] = x;
    add(a[i], 1);
    cout << mex() << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}