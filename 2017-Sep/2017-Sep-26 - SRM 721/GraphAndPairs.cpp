#include <bits/stdc++.h>

using namespace std;

class GraphAndPairs {
public:

  vector<int> cal(int k) {
    vector<int> ans;
    ans.push_back(1000);
    int cnt = 0;
    while (k) {
      int p = 0;
      for (; p * (p - 1) / 2 <= k; p++);
      p--;
      k -= p * (p - 1) / 2;
      cout << p << endl;
      for (int i = cnt + 1; i <= cnt + p; i++) {
        ans.push_back(cnt);
        ans.push_back(i);
      }
      cnt += p + 1;
    }
    return ans;
  }

  vector<int> construct(int d, int k) {
    if (d == 2) {
      return cal(k);
    }
    vector<int> ans;
    auto add = [&ans](int x, int y) {
      ans.push_back(x);
      ans.push_back(y);
    };
    ans.push_back(1000);
    int p = sqrt(k);
    int cnt = 0;
    k -= p * p;
    int u = 0, v = d - 2;
    for (int i = 1; i <= v; i++) {
      add(i - 1, i);
    }
    for (int i = v + 1; i <= v + p; i++) {
      add(0, i);
    }
    for (int i = v + p + 1; i <= v + 2 * p; i++) {
      add(v, i);
    }
    cnt = v + 2 * p + 1;
    for (int i = cnt + 1; i < cnt + d; i++) {
      add(i - 1, i);
    }
    for (int i = 0; i < k; i++) {
      add(cnt + d + i + 1, cnt + d - 1);
    }
    return ans;
  }
};

// CUT begin
ifstream data("GraphAndPairs.sample");

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

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(int d, int k, vector<int> __expected) {
    time_t startClock = clock();
    GraphAndPairs *instance = new GraphAndPairs();
    vector<int> __result = instance->construct(d, k);
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
        int d;
        from_stream(d);
        int k;
        from_stream(k);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(d, k, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1506441482;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 450 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "GraphAndPairs (450 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
