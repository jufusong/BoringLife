#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int n;
  ll K;
  cin >> n >> K;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int low = 1, high = 1e9;
  while (low <= high) {
    int mid = (low + high) / 2;
    ll sum = 0;
    for (auto x : a) {
      sum += x / mid;
    }
    if (sum >= K) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << high << endl;
  return 0;
}
