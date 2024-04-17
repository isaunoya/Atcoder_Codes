#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...)
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

template <class... T> void read() {}
template <class T> void read(T &x) { cin >> x; }
template <class T, class S> void read(pair<T, S> &v) {
  read(v.first, v.second);
}
template <class T> void read(vector<T> &v) {
  for (T &x : v)
    read(x);
}
template <class T, class... Ts> void read(T &a, Ts &...b) {
  read(a), read(b...);
}
struct unionfind {
  vector<int> p;
  unionfind(int N) { p = vector<int>(N, -1); }
  int root(int x) { return p[x] < 0 ? x : p[x] = root(p[x]); }
  bool same(int x, int y) { return root(x) == root(y); }
  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) {
      if (p[x] < p[y]) {
        swap(x, y);
      }
      p[y] += p[x];
      p[x] = y;
    }
  }
  int size(int x) { return -p[root(x)]; }
};
void solve() {
  int N;
  cin >> N;
  vector<array<int, 3>> P(N);
  vi fa(N);
  vc<vi> e(N);
  for (int i = 1; i < N; i++) {
    int p, t, s, g;
    read(p, t, s, g);
    --p;
    e[p].pb(i);
    fa[i] = p;
    P[i] = array<int, 3>{t, s, g};
  }
  unionfind f(N);
  ll now = 1;
  vector<int> st;
  while (true) {
    debug(now);
    queue<int> q;
    vi vis;
    for (int i = 1; i < N; i++) {
      if (f.root(fa[i]) == f.root(0) && !f.same(fa[i], i)) {
        vis.pb(i);
      }
    }
    debug(vis);
    vi enemy;
    for (auto x : vis) {
      if (P[x][0] == 1) {
        enemy.emplace_back(x);
      } else {
        st.emplace_back(x);
      }
    }
    sort(all(enemy), [&](int x, int y) {
      return P[x][1] < P[y][1];
    });
    sort(all(st));
    st.resize(unique(all(st)) - st.begin());
    sort(all(st), [&](int x, int y) {
      return P[x][2] < P[y][2];
    });
    for (auto i : enemy) {
      auto [s, g] = make_pair(P[i][1], P[i][2]);
      if (now >= s) {
        now += g;
        f.unite(0, i);
      } else {
        int t = (s + now - 1) / now;
        bool ok = false;
        for (auto &j : st) {
          if (P[j][2] >= t) {
            f.unite(0, j);
            now *= P[j][2];
            j = 0;
            ok = true;
            break;
          }
        }
        if (!ok) {
          cout << "No\n";
          return;
        }
        f.unite(0, i);
        now += g;
      }
    }
    if (enemy.empty() && !st.empty()) {
      int k = 0;
      while (k < sz(st) && st[k] == 0) {
        k += 1;
      }
      int j = st[k];
      st[k] = 0;
      now *= P[j][2];
      f.unite(0, j);
    }
    bool ok = true;
    for (int i = 1; i < N; i++) {
      if (!f.same(i, 0)) {
        ok = false;
        break;
      }
    }
    if (ok) {
      break;
    }
  }
  cout << "Yes\n";
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