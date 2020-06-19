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
#define test(s) \
  if (!(s))     \
    cout << "Line " << __LINE__ << ": [" << #s << "] is false" << endl;
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

int n, m, k;
vector<vector<int>> g, col;
vector<int> path, cyc, pos;

bool dfs(int cur) {
  pos[cur] = len(path);
  col[pos[cur] % 2].pb(cur + 1);
  path.pb(cur);

  int nearest = -1;
  for (int next : g[cur]) {
    if (pos[next] != -1 && pos[cur] - pos[next] > 1) {
      chmax(nearest, pos[next]);
    }
  }

  if (nearest != -1) {
    repp(i, nearest, pos[cur]) {
      cyc.pb(path[i] + 1);
    }
    return true;
  }

  for (int next : g[cur]) {
    if (pos[next] != -1)
      continue;

    if (dfs(next))
      return true;
  }

  path.pop_back();
  return false;
}

signed main() {
  int n, m, k;
  cin >> n >> m >> k;
  int kk = (k + 1) / 2;
  vector<int> u(m), v(m);
  g = vector<vector<int>>(n);
  rep(i, m) {
    cin >> u[i] >> v[i];
    u[i]--, v[i]--;
    g[u[i]].pb(v[i]);
    g[v[i]].pb(u[i]);
  }

  pos = vector<int>(n, -1);
  col = vector<vector<int>>(2);
  dfs(0);

  if (len(cyc) == 0) {
    if (len(col[1]) > len(col[0]))
      swap(col[1], col[0]);

    vector<int> ans;
    rep(i, kk) {
      ans.pb(col[0][i]);
    }

    cout << 1 << endl;
    cout << ans << endl;
  } else {
    if (len(cyc) <= k) {
      cout << 2 << endl;
      cout << len(cyc) << endl;
      cout << cyc << endl;
    } else {
      vector<int> ans;
      rep(i, kk) {
        ans.pb(cyc[i * 2]);
      }

      cout << 1 << endl;
      cout << ans << endl;
    }
  }
}