#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << "0 0" << endl;
    return 0;
  }
  cout << min(1, n - k) << " " << min(2 * k, n - k) << endl;
  return 0;
}
