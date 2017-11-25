#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  vector<ll> a(100);
  a[0] = 2, a[1] = 1;
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    a[i] = a[i - 1] + a[i - 2];
  }
  cout << a[n] << endl;
  return 0;
}
