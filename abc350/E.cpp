#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, A, X, Y; cin >> N >> A >> X >> Y;

  map<long long, double> f;
  f[0] = 0;
  auto dfs = [&](auto &dfs, long long t) -> double {
    if (f.count(t)) {
      return f[t];
    }
    double res = dfs(dfs, t / A) + X;
    double cur = 0;
    for (int i = 2; i <= 6; i++) {
      cur += dfs(dfs, t / i) / 6.;
    }
    cur = (cur + Y) * 1.2;
    return f[t] = min(res, cur);
  };

  cout << fixed << setprecision(10) << dfs(dfs, N) << "\n";
}