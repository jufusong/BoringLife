#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> a(2);
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    a[t % 2]++;
  }
  cout << a[0] * a[1] << endl;
  return 0;
}
