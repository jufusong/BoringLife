#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << (n % 2 && a[0] % 2 && a[n - 1] % 2 ? "Yes" : "No") << endl;
  return 0;
}
