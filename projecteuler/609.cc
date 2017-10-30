#include <bits/stdc++.h>

using namespace std;

pair<vector<bool>, vector<int>> primeSieve(int n) {
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  vector<int> prime;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      prime.push_back(i);
    }
    for (int j = 0; j < prime.size() && i * prime[j] <= n; j++) {
      is_prime[i * prime[j]] = false;
      if (i % prime[j] == 0) break;
    }
  }
  return {is_prime, prime};
}

typedef long long ll;

int main(int argc, char *argv[]) {
  int N = 100000001;
  auto ret = primeSieve(N);
  int h = 0;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    if (i % 3000000 == 0) {
      cout << i << endl;
    }
    if (h < ret.second.size() && ret.second[h] <= i) {
      h++;
    }
    a[i] = h;
  }
  vector<int> b(10000);
  for (int i = 2; i < N; i++) {
    int cnt = !ret.first[i];
    int t = i;
    while (t > 1) {
      t = a[t];
      cnt += !ret.first[t];
      b[cnt]++;
    }
  }
  const int mod = 1e9 + 7;
  ll ans = 1;
  for (int i = 0; i < 10000; i++) {
    if (b[i]) {
      ans = ans * b[i] % mod;
    }
  }
  cout << ans << endl;
  return 0;
}
