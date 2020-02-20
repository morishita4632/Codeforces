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

map<char, int> dx = {{'R', 1}, {'L', -1}, {'U', 0}, {'D', 0}};
map<char, int> dy = {{'R', 0}, {'L', 0}, {'U', 1}, {'D', -1}};

signed main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    typedef pair<int, int> P;
    P now = mp(0, 0);

    map<P, int> m;
    m[now] = 0;

    int mn = INF;

    int l = -1, r = -1;
    rep(i, n) {
      now.fi += dx[s[i]];
      now.se += dy[s[i]];

      if (m.find(now) == m.end()) {
        m[now] = i + 1;
      } else {
        if (chmin(mn, i + 1 - m[now]))
          l = m[now] + 1, r = i + 1;
        m[now] = i + 1;
      }
    }

    if (l == -1)
      cout << -1 << '\n';
    else
      cout << l << ' ' << r << endl;
  }
}