#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 42
#endif
#define rep(i, x, y) for (int i = x; i < y; i++)
#define eb emplace_back
using namespace std;
template <typename T, typename T2> void cmin(T &x, const T2 &y) {
  if (x > y)
    x = y;
}
template <typename T, typename T2> void cmax(T &x, const T2 &y) {
  if (x < y)
    x = y;
}
using ll = long long;
mt19937 rng(time(NULL));
const int inf = 1000000000;
const ll lnf = 1000000000000000000;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  rep(i, 0, n) {
    int c;
    cin >> c;
    a[i].resize(c);
    for (auto &x : a[i]) {
      cin >> x;
      --x;
    }
  }
  int v;
  cin >> v;
  --v;
  int mnsz = 1e9;
  rep(i, 0, n) {
    bool ok = false;
    for (auto &x : a[i])
      if (x == v) {
        ok = true;
      }
    if (ok) {
      cmin(mnsz, a[i].size());
    }
  }
  if (mnsz == 1e9) {
    cout << "0"
         << "\n";
  } else {
    vector<int> ans;
    rep(i, 0, n) {
      bool ok = false;
      for (auto &x : a[i])
        if (x == v) {
          ok = true;
        }
      if (ok && sz(a[i]) == mnsz) {
        ans.eb(i);
      }
    }
    cout << sz(ans) << "\n";
    for (int i : ans) {
      cout << i + 1 << " ";
    }
    cout << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}