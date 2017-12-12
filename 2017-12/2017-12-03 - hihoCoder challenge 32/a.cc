#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i += 2) {
    cout << i << " ";
  }
  for (int i = ((n & 1) ? n - 1 : n); i >= 1; i -= 2) {
    cout << i << " ";
  }
  return 0;
}
