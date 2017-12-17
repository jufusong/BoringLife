#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  long long S = 0;
  for (int i = 1; i <= n; ++i) {
    S += i;
  }
  vector<int> a;
  for (int i = n; i >= 1; i--) {
    if (2 * i <= S) {
      S -= 2 * i;
      a.push_back(i);
    }
  }
  cout << S << endl << a.size();
  for (auto x: a) {
    cout << " " << x;
  }
  return 0;
}
