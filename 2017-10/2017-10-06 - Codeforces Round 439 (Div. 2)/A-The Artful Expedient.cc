#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  vector<int> c(3000001);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    c[a[i]] = 1;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    c[b[i]] = 1;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cnt += c[a[i] ^ b[j]];
    }
  }
  cout << (cnt % 2 ? "Koyomi" : "Karen") << endl;
  return 0;
}
