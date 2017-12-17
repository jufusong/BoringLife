#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end()) << endl;
  }
  return 0;
}
