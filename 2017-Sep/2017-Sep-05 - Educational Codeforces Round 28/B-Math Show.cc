#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int n, k;
  ll M;
  cin >> n >> k >> M;
  vector<ll> a(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }
  ll sum = 0;
  for (int i = 0; i <= n; i++) {
    ll S = 0, cnt = i * (k + 1);
    for (auto x : a) {
      S += x;
    }
    S *= i;
    if (S > M) break;
    vector<int> b;
    for (int j = i; j < n; j++) {
      for (auto x : a) {
        b.push_back(x);
      }
    }
    sort(b.begin(), b.end());
    for (auto x : b) {
      if (S + x > M) break;
      S += x;
      cnt++;
    }
    sum = max(sum, cnt);
  }
  cout << sum << endl;
  return 0;
}
