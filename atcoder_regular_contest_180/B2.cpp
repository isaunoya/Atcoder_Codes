#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, K; cin >> N >> K;
  vector<int> P(N);
  for (int i = 0; i < N; i++) cin >> P[i];

  int M;
  cin >> M;
  while (M--) {
    int l, r;
    cin >> l >> r; 
    --l; --r;
    swap(P[l], P[r]);
  }

  debug_out(P);
}

/*
10 5
8 7 6 10 9 3 1 5 2 4
15
3 8
2 8
3 10
3 9
1 8
2 10
2 9
2 7
1 10
5 10
1 9
4 10
4 9
1 7
1 6
*/