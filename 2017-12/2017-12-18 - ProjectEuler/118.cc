#include <bits/stdc++.h>

using namespace std;

bool isPrime(long long n) {
  if (n <= 1) return false;
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  vector<int> a;
  for (int i = 1; i <= 9; ++i) {
    a.push_back(i);
  }
  set<vector<int>> se;
  do {
    auto toInt = [](vector<int> a) {
      long long ret = 0;
      for (auto x : a) {
        ret = ret * 10 + x;
      }
      return ret;
    };
    for (int i = 0; i < 1 << 8; i++) {
      bool ok = true;
      for (int j = 0, last = 0; j < 9; j++) {
        if (j == 8 || ((1 << j) & i)) {
          ok &= isPrime(toInt({a.begin() + last, a.begin() + j + 1}));
          last = j + 1;
        }
      }
      if (ok) {
        vector<int> vec;
        for (int j = 0, last = 0; j < 9; j++) {
          if (j == 8 || ((1 << j) & i)) {
            vec.push_back(toInt({a.begin() + last, a.begin() + j + 1}));
            last = j + 1;
          }
        }
        sort(vec.begin(), vec.end());
        se.insert(vec);
      }
    }
  } while (next_permutation(a.begin(), a.end()));
  cout << se.size() << endl;
  return 0;
}
