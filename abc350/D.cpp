#include <bits/stdc++.h>
using namespace std;
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
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);

  int N, M; cin >> N >> M;
  unionfind f(N);

  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y, --x, --y;
    f.unite(x, y);
  }

  long long ans = 0;
  for (int i = 0; i < N; i++) {
    if (f.root(i) == i) {
      long long cur = f.size(i);
      ans += cur * (cur - 1) / 2;
    }
  }

  cout << ans - M << "\n";
}