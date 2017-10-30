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

int main(int argc, char *argv[]) {
  auto ret = primeSieve(2000000);
  long long ans = 0;
  for (auto x : ret.second) {
    ans += x;
  }
  cout << ans << endl;
  return 0;
}
