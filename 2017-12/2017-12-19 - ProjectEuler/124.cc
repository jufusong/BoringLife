#include <bits/stdc++.h>
#include "/home/palayutm/pcl/number-theory/factorize.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  auto ret = preFactorize(100000);
  vector<pair<int, int>> vec;
  for (int i = 1; i <= 100000; i++) {
    int S = 1;
    for (auto e : ret[i]) {
      S *= e.first;
    }
    vec.emplace_back(S, i);
  }
  sort(vec.begin(), vec.end());
  cout << vec[9999].second << endl;
  return 0;
}
