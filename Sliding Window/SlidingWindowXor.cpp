/****************** HEADER FILES ******************/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
/******************* TYPEDEFS ********************/
using ll = long long;
using ld = long double;
using pl = pair<ll,ll>;
using vl = vector<ll>;
using vpl = vector<pl>;
using vvl = vector<vl>;
using ull = unsigned long long;
using sl = set<ll>;
using ml = map<ll, ll>;
 
/******************* DEFINES *********************/
#define PI (3.141592653589)
#define pb push_back
#define f first
#define s second
#define rep(i,k,j) for(ll i = k; i<j; ++i)
#define rrep(i,k,j) for(ll i = j; i>=k; --i)
#define all(x) x.begin(), x.end()
#define out(x) cout << x << '\n'
#define revSort(x) sort(x.rbegin(), x.rend())
#define pqM priority_queue<ll, vl,  greater<ll>>
#define yes cout<<"YES"<<'\n'
#define no cout<<"NO"<<'\n'
#define nl '\n'
#define uml unordered_map<ll, ll, customHash>
#define usl unordered_set<ll, customHash>
#define fastIo() ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
 
/********************* STRING METHODS *******************/
inline void cap(string &s){ transform(all(s), s.begin(), [](unsigned char c){ return toupper(c); }); }
inline void small(string &s){ transform(all(s), s.begin(), [](unsigned char c){ return tolower(c); }); }
 
/******************** DEBUG OVERLOADS ********************/
#ifdef localenv
#define dbg(x) cerr << #x << " = " << (x) << nl;
#else
#define dbg(x)
#endif
 
/*************** Custom hash Function ******************/
struct customHash
{
  static uint64_t splitmix64(uint64_t x)
  {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
 
  size_t operator()(uint64_t x) const
  {
    static const uint64_t randomValue = 
             chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + randomValue);
  }
};
 
/***************** OPERATOR OVERLOADS ******************/
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v)
{for(auto &it : v) cin >> it; return istream;}
 
template<typename T> // cout / cerr << vector<T>
ostream& operator<<(ostream &os, const vector<T> &v)
{for(auto &it : v) os << it << " ";return os;}
 
template <class T>
using ordered_set = tree<
  T,
  null_type,
  less<T>,
  rb_tree_tag,
  tree_order_statistics_node_update
>;
// ordered_set<T> os;
// os.find_by_order(k) -> iterator to k-th element (0-indexed)
// os.order_of_key(x) -> number of elements strictly less than x
 
const ll MOD = 1e9 + 7;
const ll maxN = 1e6 + 5;
 
/*************************** CODE HERE ***************************/
 
vl temp(1e7 + 1);
 
void letsGo()
{
  ll n, k; cin >> n >> k;
  ll x, a, b, c; cin >> x >> a >> b >> c;
  ll sum = x, ans(0);
  temp[0] = x;
  sum = x;
  if(k == 1) ans ^= x;
  
  rep(i, 1, n)
  {
    if(i - k >= 0) sum ^= temp[i  - k];
    ll val = (temp[i - 1] * a + b) % c;
    temp[i] = val;
    sum ^= val;
 
    if(i >= k - 1) ans ^= sum;
  }
 
  out(ans);
}
 
/*************************** ENDS HERE ***************************/
 
int32_t main()
{
  fastIo();

 
  ll tc = 1;
  rep(i, 1, tc + 1) 
  {
    //cout << "Case #" << i << ": ";
    letsGo();
  }
  return 0;
}
