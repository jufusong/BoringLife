#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int sum = 0;
  for (int i = 0; i < k; i++) {
    sum += a[i];
  }
  cout << (sum - 1) / 100 + 1 << endl;
  return 0;
}
