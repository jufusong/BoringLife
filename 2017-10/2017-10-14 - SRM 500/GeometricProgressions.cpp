#include <bits/stdc++.h>

using namespace std;

class GeometricProgressions {
public:
  vector<pair<int, int>> factorization(int n) {
    if (n == 1) return {{1, 1}};
    vector<pair<int, int>> vec;
    for (int i = 2; i * i <= n; i++) {
      int cnt = 0;
      while (n % i == 0) {
        n /= i;
        cnt++;
      }
      if (cnt) vec.push_back({i, cnt});
    }
    if (n > 1) vec.push_back({n, 1});
    return vec;
  }

  int count(int b1, int q1, int n1, int b2, int q2, int n2) {
    vector<int> pr;
    for (auto e : factorization(b1)) {
      pr.push_back(e.first);
    }
    for (auto e : factorization(q1)) {
      pr.push_back(e.first);
    }
    for (auto e : factorization(b2)) {
      pr.push_back(e.first);
    }
    for (auto e : factorization(q2)) {
      pr.push_back(e.first);
    }
    sort(pr.begin(), pr.end());
    pr.erase(unique(pr.begin(), pr.end()), pr.end());

    auto add = [&pr](vector<int>& a, int p, int cnt) {
      a[lower_bound(pr.begin(), pr.end(), p) - pr.begin()] += cnt;
    };
    set<vector<int>> se;
    vector<int> a(pr.size());
    for (auto e : factorization(b1)) {
      add(a, e.first, e.second);
    }
    se.insert(a);
    auto ret = factorization(q1);
    for (int i = 1; i < n1; i++) {
      for (auto e : ret) {
        add(a, e.first, e.second);
      }
      if (b1) {
        se.insert(a);
      }

    }
    fill(a.begin(), a.end(), 0);
    for (auto e : factorization(b2)) {
      add(a, e.first, e.second);
    }
    se.insert(a);
    ret = factorization(q2);
    for (int i = 1; i < n2; i++) {
      for (auto e : ret) {
        add(a, e.first, e.second);
      }
      if (b2) {
        se.insert(a);
      }
    }
    return se.size();
  }
};

// CUT begin
ifstream data("GeometricProgressions.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int b1, int q1, int n1, int b2, int q2, int n2, int __expected) {
    time_t startClock = clock();
    GeometricProgressions *instance = new GeometricProgressions();
    int __result = instance->count(b1, q1, n1, b2, q2, n2);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        int b1;
        from_stream(b1);
        int q1;
        from_stream(q1);
        int n1;
        from_stream(n1);
        int b2;
        from_stream(b2);
        int q2;
        from_stream(q2);
        int n2;
        from_stream(n2);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(b1, q1, n1, b2, q2, n2, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1507942957;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "GeometricProgressions (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
