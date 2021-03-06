#include <bits/stdc++.h>

using namespace std;

class AcyclicOrientation {
public:
  int count(int n, vector<int> u, vector<int> v) {
    int mod2 = (u.empty() ? 1 : 0);
    vector<vector<int>> g(n);
    for (int i = 0; i < u.size(); i++) {
      g[u[i]].push_back(v[i]);
      g[v[i]].push_back(u[i]);
    }
    vector<int> a(n, -1);
    bool flag = true;
    function<void(int, int)> dfs = [&](int u, int fa) {
      for (auto v : g[u]) {
        if (v != fa) {
          if (a[v] == -1) {
            a[v] = a[u] ^ 1;
            dfs(v, u);
          } else {
            flag &= (a[v] ^ a[u]);
          }
        }
      }
    };
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == -1) {
        cnt++;
        a[i] = 0;
        dfs(i, -1);
      }
    }
    int mod3 = 0;
    if (flag) {
      mod3 = 1;
      for (int i = 0; i < n + cnt; i++) {
        mod3 = mod3 * 2 % 3;
      }
    }
    for (int i = 0; i < 6; i++) {
      if (i % 2 == mod2 && i % 3 == mod3) return i;
    }
    return 0;
  }
};

// CUT begin
ifstream data("AcyclicOrientation.sample");

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

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
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

bool do_test(int n, vector<int> u, vector<int> v, int __expected) {
    time_t startClock = clock();
    AcyclicOrientation *instance = new AcyclicOrientation();
    int __result = instance->count(n, u, v);
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
        int n;
        from_stream(n);
        vector<int> u;
        from_stream(u);
        vector<int> v;
        from_stream(v);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, u, v, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1507209393;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 800 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "AcyclicOrientation (800 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
