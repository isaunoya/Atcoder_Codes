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

void solve() {
  int n;
  cin >> n;
  int x, y;
  cin >> x >> y;
  vi a(n);
  rep(i, n) cin >> a[i];

  auto work = [&](const vi &b, int goal) {
    int m = b.size() / 2;
    vi h1(b.begin(), b.begin() + m);
    vi h2(b.begin() + m, b.end());
    unordered_map<int, int> mp;
    rep(i, 1 << (h1.size())) {
      int s = 0;
      rep(j, h1.size()) if (i >> j & 1) { s += h1[j]; }
      else {
        s -= h1[j];
      }
      mp[s] = i;
    }
    rep(i, 1 << (h2.size())) {
      int s = 0;
      rep(j, h2.size()) if (i >> j & 1) { s += h2[j]; }
      else {
        s -= h2[j];
      }
      // debug(s, goal, goal - s);
      if (mp.count(goal - s)) {
        vi ans;
        int i1 = mp[goal - s];
        int i2 = i;
        rep(j, h1.size()) if (i1 >> j & 1) ans.pb(1);
        else ans.pb(0);
        rep(j, h2.size()) if (i2 >> j & 1) ans.pb(1);
        else ans.pb(0);
        return ans;
      }
    }
    return vi{};
  };

  vi bx, by;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 1) {
      bx.pb(a[i]);
    } else {
      by.pb(a[i]);
    }
  }

  auto ansx = work(bx, x);
  auto ansy = work(by, y);

  // debug(ansx, ansy);

  if (ansx.empty()) {
    cout << "No\n";
    return;
  }
  if (ansy.empty()) {
    cout << "No\n";
    return;
  }

  cout << "Yes\n";
  int d = 1;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 1) {
      if (ansx[i / 2] == 1) {
        if (d == 1) {
          cout << 'R';
        } else {
          cout << 'L';
        }
      } else {
        if (d == 1) {
          cout << 'L';
        } else {
          cout << 'R';
        }
      }
      d = ansx[i / 2];
    } else {
      if (ansy[i / 2] == 1) {
        if (d == 1) {
          cout << 'L';
        } else {
          cout << 'R';
        }
      } else {
        if (d == 1) {
          cout << 'R';
        } else {
          cout << 'L';
        }
      }
      d = ansy[i / 2];
    }
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