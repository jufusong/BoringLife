#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> a(n), vec;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    vec.push_back(a[i]);
  }
  sort(vec.begin(), vec.end());
  for (auto x : a) {
    auto it = upper_bound(vec.begin(), vec.end(), x);
    if (it == vec.end()) {
      cout << vec[0] << " ";
    } else {
      cout << *it << " ";
    }
  }
  return 0;
}
