#include <bits/stdc++.h>

using namespace std;

long long power(long long n, long long k) {
  long long ret = 1;
  for (int i = 0; i < k; ++i) {
    ret *= n;
  }
  return ret;
}

int main(int argc, char *argv[]) {
  vector<long long> a;
  for (int i = 2; i <= 100; i++) {
    for (int j = 2; ; j++) {
      long long val = power(i, j);
      if (val > 1e16) break;
      int x = 0;
      for (auto c : to_string(val)) {
        x += c - '0';
      }
      if (x == i) a.push_back(val);
    }
  }
  sort(a.begin(), a.end());
  for (int i = 1; i <= a.size(); i++) {
    cout << i << ": " << a[i - 1] << endl;
  }
  return 0;
}
