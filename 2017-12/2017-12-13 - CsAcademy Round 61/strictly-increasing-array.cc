#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] -= i;
  }
  vector<int> st;
  for (auto x : a) {
    if (st.empty() || x >= st.back()) {
      st.push_back(x);
    } else {
      *upper_bound(st.begin(), st.end(), x) = x;
    }
  }
  cout << n - st.size() << endl;
  return 0;
}
