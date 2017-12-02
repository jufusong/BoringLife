#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

std::vector<int> preInverse(int n, int md = mod) {
  std::vector<int> inv(n + 1);
  inv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    inv[i] = (ll)(md - md / i) * inv[md % i] % md;
  }
  return inv;
}

struct Binomial {
  int n, md;
  std::vector<int> factorial, inv_factorial;
  Binomial(int n, int mod) : n(n), md(mod) {
    factorial.resize(n + 1);
    inv_factorial = preInverse(n, md);
    factorial[0] = inv_factorial[0] = 1;
    for (int i = 1; i <= n; i++) {
      factorial[i] = (ll)factorial[i - 1] * i % md;
      inv_factorial[i] = (ll)inv_factorial[i - 1] * inv_factorial[i] % md;
    }
  }
  int choose(int n, int k) {
    if (k > n) return 0;
    return (ll)factorial[n] * inv_factorial[k] % md * inv_factorial[n - k] % md;
  }
}bn(1000005, mod);

ll calculate(const vector<int>& a) {
  int sum = 0;
  ll ans = 1;
  for (auto x : a) {
    sum += x;
    ans = ans * bn.inv_factorial[x] % mod;
  }
  ans = ans * bn.factorial[sum - 1] % mod;
  return ans;
}

int main(int argc, char *argv[]) {
  string s, t;
  cin >> s >> t;
  vector<int> a(26);
  for (auto c : s) {
    a[c - 'a']++;
  }
  auto b = a;
  bool flag = true, fz = true;;
  ll ans = 0;
  ll now1 = calculate(a), now2 = now1;
  auto cal = [&ans](vector<int>& a, int id, ll now) {
    if (a[id] > 0) {
      ans = (ans + now * bn.factorial[a[id]] % mod * bn.inv_factorial[a[id] - 1]) % mod;
    }
  };
  for (int i = 0; i < s.size(); i++) {
    if (flag) {
      for (int j = s[i] + 1; j < t[i]; j++) {
        cal(a, j - 'a', now1);
      }
    } else {
      for (int j = s[i] + 1; j <= 'z'; j++) {
        cal(a, j - 'a', now1);
      }
      if (fz) {
        for (int j = 'a'; j < t[i]; j++) {
          cal(b, j - 'a', now2);
        }
      }
    }
    now1 = now1 * bn.factorial[a[s[i] - 'a']] % mod;
    a[s[i] - 'a']--;
    now1 = now1 * bn.inv_factorial[a[s[i] - 'a']] % mod;
    if (b[t[i] - 'a'] >= 0) {
      now2 = now2 * bn.factorial[b[t[i] - 'a']] % mod;
    }
    b[t[i] - 'a']--;
    if (b[t[i] - 'a'] >= 0) {
      now2 = now2 * bn.inv_factorial[b[t[i] - 'a']] % mod;
    }
    if (i + 1 < s.size()) {
      now2 = now2 * bn.inv_factorial[s.size() - i - 1] % mod * bn.factorial[s.size() - i - 2] % mod;
      now1 = now1 * bn.inv_factorial[s.size() - i - 1] % mod * bn.factorial[s.size() - i - 2] % mod;      
    }
    fz &= (b[t[i] - 'a'] >= 0);
    fz &= (b[t[i] - 'a'] >= 0);
    flag &= (s[i] == t[i]);
  }
  cout << ans << endl;
  return 0;
}
