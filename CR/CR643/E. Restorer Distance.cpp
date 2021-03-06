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

#pragma region slope_search
const double Golden = 2.0 / (3.0 + sqrt(5));

int f(int trial);
int slope_search(int inc, int dec) {
  bool isMax = inc < dec;
  while (abs(dec - inc) > 1) {
    int mid = (inc + dec) / 2;
    (f(mid) - f(mid - 1) > 0 ? inc : dec) = mid;
  }
  return isMax ? inc : dec;
}
#pragma endregion

int N, A, R, M;
vector<int> h;

int f(int H) {
  int inc = 0;
  int dec = 0;

  int cost = 0;
  rep(i, N) {
    if (h[i] > H)
      dec += h[i] - H;
    else
      inc += H - h[i];
  }

  if (M < A + R) {
    int temp = min(inc, dec);
    cost += M * temp;
    inc -= temp, dec -= temp;
  }
  cost += inc * A + dec * R;
  return cost;
}

signed main() {
  cin >> N >> A >> R >> M;
  h = vector<int>(N);
  rep(i, N) {
    cin >> h[i];
  }

  int H = slope_search((int)1e+10, 0);
  int ans = f(H);
  cout << ans << endl;
}