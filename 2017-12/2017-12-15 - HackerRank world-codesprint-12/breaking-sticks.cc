#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  long long ans = 0;
  vector<long long> a(n), div;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (long long j = 1; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        div.push_back(j);
        div.push_back(a[i] / j);
      }
    }
  }
  sort(div.begin(), div.end());
  div.erase(unique(div.begin(), div.end()), div.end());
  vector<long long> f(div.size(), 0);
  f[0] = 1;
  for (int i = 1; i < div.size(); i++) {
    f[i] = 1;
    for (int j = 0; j < i; j++) {
      if (div[i] % div[j] == 0) {
        f[i] = max(f[i], f[j] * (div[i] / div[j]) + 1);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    ans += f[lower_bound(div.begin(), div.end(), a[i]) - div.begin()];
  }
  cout << ans << endl;
  return 0;
}
