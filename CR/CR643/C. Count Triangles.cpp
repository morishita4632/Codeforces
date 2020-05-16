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

signed main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int ans = 0;
  repp(z, C, D) {
    int Ay = z + 1 - A, By = z + 1 - B, Bx = By, Cx = z + 1 - C;
    if (Cx > B) {
      continue;
    } else if (Cx >= A && By >= B) {
      int e = B - Cx + 1;
      ans += e * (e + 1) / 2;
    } else if (Cx >= A) {
      int e1 = B - Cx + 1, e2 = B - Bx + 1;
      ans += (e1 + e2) * (C - B + 1) / 2;
    } else if (By >= B) {
      int e1 = C - Ay + 1, e2 = C - By + 1;
      ans += (e1 + e2) * (B - A + 1) / 2;
    } else if (Ay > B) {
      int temp = (B - A + 1) * (C - B + 1);
      int e = Ay - B;
      temp -= e * (e + 1) / 2;
      ans += temp;
    } else {
      ans += (B - A + 1) * (C - B + 1);
    }
  }
  cout << ans << endl;
}