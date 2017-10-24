#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    cout << (n % (k + 1) > 0 ? "A" : "B") << endl;
  }
  return 0;
}
