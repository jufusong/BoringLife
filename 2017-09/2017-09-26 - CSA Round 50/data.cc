#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cout << 100000 << endl;
  int n = 10;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = i + 1;
  }
  for (int z = 0; z <= 100000; z++) {
    cout << n << endl;
    for (auto x : a) {
      cout << x << " ";
    }
    cout << endl;
    next_permutation(a.begin(), a.end());
  }
}
