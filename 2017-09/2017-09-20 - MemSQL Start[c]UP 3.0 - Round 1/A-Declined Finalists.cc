#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int K, mx = 0;
  cin >> K;
  for (int i = 0, t; i < K; i++) {
    cin >> t;
    mx = max(mx, t);
  }
  cout << max(0, mx - 25) << endl;
  return 0;
}
