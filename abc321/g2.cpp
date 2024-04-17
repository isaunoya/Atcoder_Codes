#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const long long HALF = 499122177;
int main(){
  int N, M;
  cin >> N >> M;
  vector<int> R(M);
  for (int i = 0; i < M; i++){
    cin >> R[i];
    R[i]--;
  }
  vector<int> B(M);
  for (int i = 0; i < M; i++){
    cin >> B[i];
    B[i]--;
  }
  vector<long long> inv(M + 1);
  inv[1] = 1;
  for (int i = 2; i <= M; i++){
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
  }
  vector<long long> fact(M + 1), finv(M + 1);
  fact[0] = 1;
  finv[0] = 1;
  for (int i = 1; i <= M; i++){
    fact[i] = fact[i - 1] * i % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
  vector<int> X(N, 0), Y(N, 0);
  for (int i = 0; i < M; i++){
    X[R[i]]++;
    Y[B[i]]++;
  }
  vector<int> SX(1 << N, 0);
  vector<int> SY(1 << N, 0);
  for (int i = 0; i < (1 << N); i++){
    for (int j = 0; j < N; j++){
      if ((i >> j & 1) == 1){
        SX[i] += X[j];
        SY[i] += Y[j];
      }
    }
  }
  vector<long long> A(1 << N, 0);
  for (int i = 1; i < (1 << N); i++){
    if (SX[i] == SY[i]){
      A[i] = fact[SX[i]] * fact[M - SX[i]] % MOD * finv[M] % MOD;
    }
  }
  for (int i = 1; i < (1 << N); i++){
    if (SX[i] == SY[i]){
      for (int j = i; j > 0; j = (j - 1) & i){
        if (j != i && j > (i ^ j)){
          if (SX[j] == SY[j]){
            int a = SX[i ^ j];
            int b = SX[(1 << N) - 1 - i];
            A[i] += MOD - A[j] * fact[a] % MOD * fact[b] % MOD * finv[a + b] % MOD;
            A[i] %= MOD;
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i < (1 << N); i++){
    ans += A[i];
  }
  ans %= MOD;
  cout << ans << endl;
}
