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

void step(int f, string s) {
  cout << f << ' ' << s << endl;
}

string S;

void add(int n, char c) {
  rep(i, n) {
    S.pb(c);
  }
}

signed main() {
  int n, m, k;
  cin >> n >> m >> k;
  int roads = 4 * n * m - 2 * n - 2 * m;

  if (k > roads) {
    cout << "NO\n";
    return 0;
  }


  // k<=1e+5
  add(m - 1, 'R');

  rep(i, n - 1) {
    add(m - 1, 'L');
    add(1, 'D');
    add(m - 1, 'R');
  }

  rep(i, m - 1) {
    add(n - 1, 'U');
    add(n - 1, 'D');
    add(1, 'L');
  }

  add(n, 'U');

  string raw = S.substr(0, k);
  raw.pb('.');

  typedef pair<int, char> P;
  vector<P> ans;

  char now = raw[0];
  int seq = 1;

  repp(i, 1, k) {
    if (raw[i] == now)
      seq++;
    else {
      ans.pb(mp(seq, now));
      now = raw[i];
      seq = 1;
    }
  }

  cout << "YES\n";
  cout << len(ans) << endl;
  for (auto elem : ans) {
    cout << elem.fi << ' ' << elem.se << endl;
  }
}