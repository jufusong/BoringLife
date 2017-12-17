#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  vector<int> a = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  auto b = a;
  b[1] = 29;
  b.insert(b.begin(), a.begin(), a.end());
  b.insert(b.begin(), a.begin(), a.end());
  b.insert(b.end(), a.begin(), a.end());
  b.insert(b.end(), a.begin(), a.end());
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; ++i) {
    cin >> vec[i];
  }
  bool ok = false;
  for (int i = 0; i + n <= b.size(); i++) {
    bool f = true;
    for (int j = i, k = 0; k < n; k++, j++) {
      f &= (b[j] == vec[k]);
    }
    ok |= f;
  }
  puts(ok ? "YES" : "NO");
  return 0;
}
