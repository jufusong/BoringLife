#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, K, X, sum = 0;;
  cin >> n >> K >> X;
  for (int i = 0, t; i < n; i++) {
    cin >> t;
    sum += (i >= n - K ? X : t);
  }
  cout << sum << endl;
  return 0;
}
