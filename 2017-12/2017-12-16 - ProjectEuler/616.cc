#include <bits/stdc++.h>

using namespace std;

/*__int128 power(__int128 n, __int128 k) {
  __int128 ret = 1;
  for (__int128 i = 0; i < k; i++) {
    ret *= n;
  }
  return ret;
}

void solve(__int128 zz) {
  auto output = [](vector<__int128> a) {
    cout << "[";
    for (auto x : a) {
      cout << (long long)x << " ";
    }
    cout << "]";
  };
  set<vector<__int128>> se = {{zz}};
  queue<vector<__int128>> q;
  q.push({zz});
  while (!q.empty()) {
    auto vec = q.front();
    q.pop();
    auto update = [&](vector<__int128> a) {
      sort(a.begin(), a.end());
      if (!se.count(a)) {
        se.insert(a);
        q.push(a);
        output(vec);
        cout << "->";
        output(a);
        cout << endl;
      }
    };
    for (__int128 i = 0; i < vec.size(); i++) {
      for (__int128 j = 2; j <= 20; j++) {
        __int128 d = floor(pow(vec[i], 1.0 / j));
        if (d > 1 && power(d, j) == vec[i]) {
          auto nv = vec;
          nv.erase(nv.begin() + i);
          nv.push_back(d);
          nv.push_back(j);
          update(nv);
        }
      }
    }
    for (__int128 i = 0; i < vec.size(); i++) {
      for (__int128 j = i + 1; j < vec.size(); j++) {
        auto nv = vec;
        __int128 x = nv[j], y = nv[i];
        nv.erase(nv.begin() + j);
        nv.erase(nv.begin() + i);
        nv.push_back(power(x, y));
        update(nv);
        nv.pop_back();
        nv.push_back(power(y, x));
        update(nv);
      }
    }
  }
}
*/
std::pair<std::vector<bool>, std::vector<int>> primeSieve(int n) {
  std::vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  std::vector<int> prime_list;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      prime_list.push_back(i);
    }
    for (int j = 0; j < prime_list.size() && i * prime_list[j] <= n; j++) {
      is_prime[i * prime_list[j]] = false;
      if (i % prime_list[j] == 0) break;
    }
  }
  return {is_prime, prime_list};
}

int main(int argc, char *argv[]) {
  auto is_prime = primeSieve(1e6).first;
  set<long long> se;
  for (int i = 2; i <= 1e6; i++) {
    if (!is_prime[i]) {
      long long now = i;
      for (int j = 2; ; j++) {
        now *= i;
        if (now > 1e12) break;
        se.insert(now);
      }
    }
  }
  se.erase(se.begin());
  cout << *se.begin() << endl;
  unsigned long long sum = 0;
  for (auto x : se) {
    sum += x;
  }
  cout << sum << endl;
  return 0;
}
