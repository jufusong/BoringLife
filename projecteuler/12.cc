#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  vector<int> pr(1000001);
  for (int i = 1; i <= 1000000; i++) {
    for (int j = i; j <= 1000000; j += i) {
      pr[j]++;
    }
  }
  vector<int> a(1002, 1e9);
  for (int i = 999999; i >= 1; i--) {
    int t;
    if (i & 1) {
      t = pr[i] * pr[(i + 1) / 2];
    } else {
      t = pr[i / 2] * pr[i + 1];
    }
    if (t > 1001) t = 1001;
    a[t] = i;
  }
  for (int i = 1000; i >= 2; i--) {
    a[i] = min(a[i], a[i + 1]);
  }
  cout << (long long)a[500 + 1] * (a[500 + 1] + 1) / 2 << endl;
  return 0;
}
