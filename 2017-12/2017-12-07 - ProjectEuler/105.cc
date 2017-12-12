#include <bits/stdc++.h>

using namespace std;

int check(vector<int> vec) {
  sort(vec.begin(), vec.end());
  int m = (vec.size() + 2) / 2;
  if (accumulate(vec.begin(), vec.begin() + m, 0) <= accumulate(vec.end() - m + 1, vec.end(), 0)) {
    return false;
  }
  set<int> se;
  for (int i = 0; i < 1 << vec.size(); ++i) {
    int sum = 0;
    for (int j = 0; j < vec.size(); ++j) {
      if ((1 << j) & i) sum += vec[j];
    }
    if (se.count(sum)) return 0;
    se.insert(sum);
  }
  return accumulate(vec.begin(), vec.end(), 0);
}

int main(int argc, char *argv[]) {
  string s;
  int sum = 0;
  while (getline(cin, s)) {
    stringstream ss(s);
    int v;
    char c;
    vector<int> a;
    while (ss >> v) {
      a.push_back(v);
      ss >> c;
    }
    sum += check(a);
  }
  cout << sum << endl;
  return 0;
}
