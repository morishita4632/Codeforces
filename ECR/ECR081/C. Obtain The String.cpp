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
const int INF = 1001001001;
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

signed main() {
  int T;
  cin >> T;
  while (T-- > 0) {
    string s;
    cin >> s;
    string t;
    cin >> t;

    unordered_set<char> ss, tt;
    for (char c : s) {
      ss.insert(c);
    }
    for (char c : t) {
      tt.insert(c);
    }

    bool ok = true;
    for (char c : tt) {
      if (ss.find(c) == ss.end())
        ok = false;
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }

    vector<vector<int>> place(26);
    rep(i, len(s)) {
      int c = s[i] - 'a';
      place[c].pb(i);
    }

    int ans = 1;

    int now = -1;
    rep(i, len(t)) {
      int c = t[i] - 'a';

      auto iter = upper_bound(all(place[c]), now);
      int pos = distance(place[c].begin(), iter);

      if (iter == place[c].end()) {
        ans++;
        now = place[c][0];
      } else {
        now = *iter;
      }
    }
    cout << ans << endl;
  }
}