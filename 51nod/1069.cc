#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, t = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    t ^= x;
  }
  cout << (t ? "A" : "B") << endl;
  return 0;
}
