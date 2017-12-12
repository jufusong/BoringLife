#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int p;
  cin >> p;
  vector<int> a(6), b(6);
  for (int i = 0; i < 6; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < 6; ++i) {
    cin >> b[i];
  }
  vector<int> c(p, 0);
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 6; ++j) {
      c[(a[i] + b[j]) % p]++;
    }
  }
  bool flag = true;
  for (int i = 0; i < p; ++i) {
    flag &= (c[i] == c[0]);
  }
  puts(flag ? "YES" : "NO");
  return 0;
}
