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

int n, m;
bool outside(int i, int j) {
  return i < 0 || i >= n || j < 0 || j >= m;
}


signed main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    cin >> n >> m;
    vector<vector<char>> c(n, vector<char>(m));
    rep(i, n) {
      rep(j, m) {
        cin >> c[i][j];
      }
    }

    vector<int> di = {0, -1, 0, 1};
    vector<int> dj = {1, 0, -1, 0};


    bool ok = true;
    rep(i, n) {
      rep(j, m) {
        if (c[i][j] == 'B') {
          rep(d, 4) {
            int ni = i + di[d], nj = j + dj[d];
            if (outside(ni, nj) || c[ni][nj] == 'B')
              continue;
            else if (c[ni][nj] == 'G')
              ok = false;
            else
              c[ni][nj] = '#';
          }
        }
      }
    }


    if (!ok) {
      cout << "No\n";
      continue;
    }

    vector<vector<bool>> escape(n, vector<bool>(m, false));

    int si = n - 1, sj = m - 1;
    escape[si][sj] = true;

    queue<int> q;
    q.push(si * m + sj);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      int i = cur / m, j = cur % m;
      if (c[i][j] == '#')
        break;
      rep(d, 4) {
        int ni = i + di[d], nj = j + dj[d];
        if (outside(ni, nj) || c[ni][nj] == '#')
          continue;
        if (escape[ni][nj])
          continue;

        escape[ni][nj] = true;
        q.push(ni * m + nj);
      }
    }

    ok = true;
    rep(i, n) {
      rep(j, m) {
        if (c[i][j] == 'G' && !(escape[i][j]))
          ok = false;
      }
    }

    if (ok)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}