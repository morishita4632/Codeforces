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
#pragma endregion

int n, m;
vector<vector<char>> A;
vector<vector<bool>> seen;

bool in(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

vector<int> di = {0, -1, 0, 1};
vector<int> dj = {1, 0, -1, 0};


void dfs(int i, int j) {
  seen[i][j] = true;
  rep(d, 4) {
    int ni = i + di[d], nj = j + dj[d];
    if (in(ni, nj) && !seen[ni][nj] && A[ni][nj] == '#')
      dfs(ni, nj);
  }
}

signed main() {
  cin >> n >> m;
  A = vector<vector<char>>(n, vector<char>(m));
  rep(i, n) {
    rep(j, m) {
      cin >> A[i][j];
    }
  }

  vector<vector<bool>> l(n, vector<bool>(m + 1, false));
  auto r = l;

  vector<vector<bool>> u(n + 1, vector<bool>(m, false));
  auto d = u;


  rep(i, n) {
    rep(j, m) {
      l[i][j + 1] = l[i][j] || (A[i][j] == '#');
      u[i + 1][j] = u[i][j] || (A[i][j] == '#');
    }
  }
  rep(i, n) {
    repr(j, m, 1) {
      r[i][j - 1] = r[i][j] || (A[i][j - 1] == '#');
    }
  }

  rep(j, m) {
    repr(i, n, 1) {
      d[i - 1][j] = d[i][j] || (A[i - 1][j] == '#');
    }
  }

  rep(i, n) {
    rep(j, m) {
      if (A[i][j] == '#')
        continue;

      if ((l[i][j] && r[i][j + 1]) || (u[i][j] && d[i + 1][j])) {
        cout << -1 << '\n';
        return 0;
      }
    }
  }

  bool hasAllWhiteRow = false, hasAllWhiteColumn = false;
  rep(i, n) {
    if (!r[i][0])
      hasAllWhiteRow = true;
  }
  rep(j, m) {
    if (!d[0][j])
      hasAllWhiteColumn = true;
  }

  if (hasAllWhiteRow ^ hasAllWhiteColumn) {
    cout << -1 << '\n';
    return 0;
  }

  int ans = 0;
  seen = vector<vector<bool>>(n, vector<bool>(m, false));
  rep(i, n) {
    rep(j, m) {
      if (A[i][j] == '#' && !seen[i][j]) {
        ans++;
        dfs(i, j);
      }
    }
  }
  cout << ans << endl;
}