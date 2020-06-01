#pragma region head
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
#define double long double
typedef double ld;
const int INF = 1001001001001001001ll;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1.0);

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
#pragma endregion

typedef pair<int, int> P;
vector<int> a, b, c;
vector<vector<int>> G;

struct C_01_10 {
  ll C, zo, oz;
  C_01_10() = default;
  C_01_10(ll C, ll zo, ll oz) : C(C), zo(zo), oz(oz) {
  }

  C_01_10 operator+(const C_01_10& another) const {
    return C_01_10(this->C + another.C, this->zo + another.zo,
                   this->oz + another.oz);
  };
};


C_01_10 dfs(int par, int cur) {
  chmin(a[cur], (par == -1 ? INF : a[par]));
  C_01_10 temp(0, 0, 0);
  for (int next : G[cur]) {
    if (next == par)
      continue;
    temp = temp + dfs(cur, next);
  }

  temp.zo += (b[cur] == 0 && c[cur] == 1);
  temp.oz += (b[cur] == 1 && c[cur] == 0);

  int mn = min(temp.zo, temp.oz);
  temp.C += mn * a[cur] * 2;
  temp.zo -= mn, temp.oz -= mn;
  return temp;
}

signed main() {
  int n;
  cin >> n;

  a = vector<int>(n);
  b = vector<int>(n);
  c = vector<int>(n);

  int B = 0, C = 0;
  rep(i, n) {
    cin >> a[i] >> b[i] >> c[i];
    B += b[i], C += c[i];
  }

  vector<int> u(n - 1), v(n - 1);
  G = vector<vector<int>>(n);
  rep(i, n - 1) {
    cin >> u[i] >> v[i];
    u[i]--, v[i]--;
    G[u[i]].pb(v[i]);
    G[v[i]].pb(u[i]);
  }

  if (B != C) {
    cout << -1 << '\n';
    return 0;
  }

  auto temp = dfs(-1, 0);
  int ans = temp.C;
  cout << ans << endl;
}