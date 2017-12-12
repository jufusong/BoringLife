#include <bits/stdc++.h>

using namespace std;

const long long inf  = 2e18;

long long a[100006];
string S = "What are you doing at the end of the world? Are you busy? Will you save us?";
string T1 = "What are you doing while sending \"";
string T2 = "\"? Are you busy? Will you send \"";
string T3 = "\"?";

char solve(int n, long long K) {
  if (K > a[n]) return '.';
  if (n == 0) return S[K - 1];
  if (K <= T1.size()) return T1[K - 1];
  K -= T1.size();
  if (K <= a[n - 1]) return solve(n - 1, K);
  K -= a[n - 1];
  if (K <= T2.size()) return T2[K - 1];
  K -= T2.size();
  if (K <= a[n - 1]) return solve(n - 1, K);
  K -= a[n - 1];
  return T3[K - 1];
}

int main(int argc, char *argv[]) {
  a[0] = S.size();
  int sz = T1.size() + T2.size() + T3.size();
  for (int i = 1; i <= 100000; i++) {
    a[i] = a[i - 1] * 2 + sz;
    if (a[i] > inf) a[i] = inf;
  }
  int T;
  cin >> T;
  while (T--) {
    int n;
    long long K;
    cin >> n >> K;
    cout << solve(n, K);
  }
  return 0;
}
