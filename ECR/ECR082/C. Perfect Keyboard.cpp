#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
#define len(x) ((ll)(x).size())
#define debug(var) cout << "[" << #var << "]\n" << var << endl
#define int long long
typedef long long ll;
const int INF = 1001001001001001001ll;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;

template <typename T>
ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i];
    if (i < len - 1)
      s << ' ';
  }
  return s;
}

template <typename T>
ostream& operator<<(ostream& s, const vector<vector<T>>& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i];
    if (i != len - 1)
      s << '\n';
  }
  return s;
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

__attribute__((constructor)) void initial() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}

template <typename T>
struct nvector {
  int edge, tot;
  vector<T> vec;

  nvector(int edge) : edge(edge), tot(edge * 2 + 1), vec(tot) {
  }
  nvector(int edge, T init) : edge(edge), tot(edge * 2 + 1), vec(tot, init) {
  }

  T& operator[](int pos) {
    return vec[pos + edge];
  }
};

template <typename T>
ostream& operator<<(ostream& s, const nvector<T>& nvector) {
  s << nvector.vec;
  return s;
}

signed main() {
  int T;
  cin >> T;
  while (T-- > 0) {
    string s;
    cin >> s;
    nvector<char> conf(26, '.');
    conf[0] = s[0];

    vector<bool> used(150, false);
    used[s[0]] = true;

    bool ok = true;
    rep(i, len(s) - 1) {
      char l = s[i], r = s[i + 1];
      int l_pos = 100;
      repp(i, -26, 26) {
        if (conf[i] == l)
          l_pos = i;
      }

      if (used[r]) {
        if (conf[l_pos - 1] != r && conf[l_pos + 1] != r) {
          ok = false;
          break;
        }
      } else {
        if (conf[l_pos - 1] == '.')
          conf[l_pos - 1] = r;
        else if (conf[l_pos + 1] == '.')
          conf[l_pos + 1] = r;
        else {
          ok = false;
          break;
        }
        used[r] = true;
      }
    }

    if (!ok) {
      cout << "NO\n";
      continue;
    }

    string ans;
    repp(i, -26, 26) {
      if (conf[i] != '.')
        ans.pb(conf[i]);
    }

    repp(c, 'a', 'z') {
      if (!used[c])
        ans.pb((char)c);
    }
    cout << "YES\n";
    cout << ans << endl;
  }
}