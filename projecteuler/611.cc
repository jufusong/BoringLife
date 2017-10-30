#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  auto cal = [](long long N) {
    vector<int> vec;
    for (int i = 1; i * i <= N; i++) {
      vec.push_back(i * i);
    }
    vector<bool> a(N + 1);
    for (int i = 0; i < vec.size(); i++) {
      for (int j = i + 1; j < vec.size() && vec[i] + vec[j] <= N; j++) {
        a[vec[i] + vec[j]] = !a[vec[i] + vec[j]];
      }
    }
    int ans = 0;
    for (auto x : a) {
      ans += x;
    }
    return ans;
  };
  cout << cal((long long)1e12) << endl;
  return 0;
}
