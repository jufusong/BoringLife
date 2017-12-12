#include <bits/stdc++.h>

using namespace std;

struct Polynomial {
  vector<double> a;
  Polynomial(int n) : a(n + 1) {}
  Polynomial(vector<double> g) : a(g) {}
  Polynomial(vector<pair<double, double>> point) {
    int n = point.size();
    a.assign(n, 0);
    vector<double> temp(n);
    for (int k = 0; k < n - 1; ++k) {
      for (int i = k + 1; i < n; ++i) {
        point[i].second = (point[i].second - point[k].second) / (point[i].first - point[k].first);  
      }
    }
    double last = 0; temp[0] = 1;
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        a[i] += point[k].second * temp[i];
        swap(last, temp[i]);
        temp[i] -= last * point[k].first;
      }
    }
  }
  double operator()(double x) const {
    double val = 0;
    for(int i = (int)a.size() - 1; i >= 0; --i) (val *= x) += a[i];
    return val;
  }
};

const double eps = 1e-8;

int main(int argc, char *argv[]) {
  cout.precision(15);
  Polynomial p1({1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1});
  vector<pair<double, double>> vec;
  for (int i = 1; i <= 11; ++i) {
    vec.push_back({i, p1(i)});
  }
  double sum = 0;
  for (int i = 1; i <= 10; ++i) {
    Polynomial p(vector<pair<double, double>>{vec.begin(), vec.begin() + i});
    sum += p(i + 1);
  }
  cout << sum << endl;
  return 0;
}
