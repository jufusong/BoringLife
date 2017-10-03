#include <bits/stdc++.h>

using namespace std;

int cal(vector<int> a) {
  vector<int> st;
  for (auto x : a) {
    if (st.empty() || x >= st.back()) {
      st.push_back(x);
    } else {
      *upper_bound(st.begin(), st.end(), x) = x;
    }
  }
  return st.size();
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    int xx = cal(a);
    for (auto& x : a) {
      x = -x;
    }
    xx = max(xx, cal(a));
    puts(k >= n - xx ? "A is a magic array." : "A is not a magic array.");
  }
  return 0;
}
