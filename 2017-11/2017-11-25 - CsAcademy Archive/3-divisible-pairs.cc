#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<ll> a(3);
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    a[t % 3]++;
  }
  cout << a[1] * a[2] + a[0] * (a[0] - 1) / 2 << endl;
  return 0;
}
