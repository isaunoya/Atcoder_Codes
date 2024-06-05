#include <bits/stdc++.h>
using namespace std;
int a[1 << 20], b[1 << 20];
int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    a[x]++;
  }
  for (int i = (1 << 20) - 2; i >= 1; i--) {
    b[i] = b[i + 1] + a[i];
  }

  long long ans = 0;
  for (int i = 1; i < (1 << 20); i++) {
    if (!a[i])
      continue;
    ans += 1ll * a[i] * (a[i] - 1) / 2;
    ans += 1ll * a[i] * b[i + 1];
    for (int j = i * 2; j < (1 << 20); j += i) {
      ans += 1ll * a[i] * b[j];
    }
  }

  cout << ans << "\n";
}