#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
using namespace __gnu_cxx;
#include <ext/pb_ds/tree_policy.hpp>

#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define fast2 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n";
#define e cout << "\n";
#define fi first
#define se second
#define cout_map(mp)        \
    for (auto &[f, s] : mp) \
        cout << f << " " << s << "\n";
#define Set set<int>
#define Map map<int, int>
#define Vector vector<int>
#define cin_v(a)      \
    for (auto &i : a) \
        cin >> i;
#define cout_v(a)     \
    for (auto &i : a) \
        cout << i << " ";
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define print(v, template) copy(all(v), ostream_iterator<template>(cout, " "));
#define imax INT_MAX
#define imin INT_MIN
#define llmax LLONG_MAX
#define llmin LLONG_MIN
#define pf push_front
#define to_decimal(bin) stoll(bin, nullptr, 2)

#define upper(s) transform(all(s), s.begin(), ::toupper);
#define lower(s) transform(all(s), s.begin(), ::tolower);
#define cnte(c, x) count(all(v), x)
#define mine(v) min_element(all(v))
#define maxe(v) max_element(all(v))
#define v_sort(x) sort(all(x), less<>())
#define r_v_n                  \
    return void(cout << "NO"); \
    e
#define r_v_y                   \
    return void(cout << "YES"); \
    e
#define bool(n) cout << (n ? "YES" : "NO");
#define v_gsort(x) sort(all(x), greater<ll>())
#define v_find(x, num) find(all(x), num)
#define updmin(a, b) a = min(a, b)
#define bp __builtin_popcount
#define em emplace

#define updmax(a, b) a = max(a, b)
#define getmod(x, m) ((x) % (m) + (m)) % m
#define findmod(x, m) x = ((x) % (m) + (m)) % m
#define loop(a, b, c) for (int i = a; i < b; i += c)
#define bool(n) cout << (n ? "YES" : "NO");
#define cin_pair(a)   \
    for (auto &i : a) \
        cin >> i.FI >> i.SE;
#define cout_pair(a)  \
    for (auto &i : a) \
        cout << i.FI << " " << i.SE << nl;
// #define getline(s) getline(cin >> ws, s)
#define NumOfDig(w) ((int)log10(w) + 1)
// #define Pair pair <int,int>
#define MOD 1'000'000'007 // used for modulus big numbers
#define INF 2'000'000'000
#define EPS 1e-9     // EPSON used in comparing double
#define PI1 acos(-1) // used in Geomtry
#define PI2 3.14159265358979323846
#define power_of_2(x) (x && (!(x & (x - 1))))
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
#define rall(s) s.rbegin(), s.rend()
#define fill(x, c) memset(x, c, sizeof(x))
#define getlineCh(s, c) getline(cin >> ws, s, c)
#define Ceil(w, m) (((w) / (m)) + ((w) % (m) ? 1 : 0)) // #define ceil(a, b) (a + b - 1) / b
#define Time cerr << "Time : " << (float)clock() / CLOCKS_PER_SEC << " Secs" \
                  << "\n";
#define Time2 cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#define pb push_back
#define nl cout << "\n";
#define For(i, n) for (int i = 0; i < n; i++)
#define cin(vec, n)                  \
    for (int i = 0; i < (int)n; i++) \
        cin >> vec[i]; // or for(auto &i:vec)cin>>i;
#define cout(vec, n)                 \
    for (int i = 0; i < (int)n; i++) \
        cout << vec[i] << " ";       \
    cout << "\n"; // or for(auto &i:vec)cout<<i<<" "<<"\n";
#define cin_2d(vec, n, m)           \
    for (int i = 0; i < n; i++)     \
    {                               \
        for (int j = 0; j < m; j++) \
        {                           \
            cin >> vec[i][j];       \
        }                           \
    }
#define cout_2d(vec, n, m)                    \
    for (int i = 0; i < n; i++, cout << "\n") \
        for (int j = 0; j < (m) && cout << vec[i][j] << " "; j++)
#define OO 2147483647
#define odd(a) a & 1 // checks if num is odd using & bitwise operator
#define even(a) !(a & 1)
#define runtime() cerr((double)clock() / CLOCKS_PER_SEC) << "\n";
#define MK make_pair
#define cy cout << "Yes\n"
#define cn cout << "No\n"
#define ll long long int
#define fixed(n) cout << fixed << setprecision(n);
#define ull unsigned long long
#define sz(x) int(x.size())
#define all(s) s.begin(), s.end()
#define mod_combine(a, b, m) (((a % m) * (b % m)) % m)
#define debug(x) cout << #x << ": " << (x) << "\n";
#define over 1e18
#define LSB(n) (n & -n) // least segnificant bit
typedef double d;
typedef long double ld;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define pii pair<int, int>
#define pl pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pl>
#define vvi vector<vi>
#define issmall(c) c >= 97 && c <= 122
#define iscapital(c) c >= 65 && c <= 90
#define mid(l, r) l + (r - l) / 2
// from lower to upper char-32
// from upper to lower char+32
// A =65 Z=90  -   a=97  z=122
// ABCDEFGHIJKLMNOPQRSTUVWXYZ
// abcdefghijklmnopqrstuvwxyz
#define test(vect) generate(vect.begin(), vect.end(), [&]() { return rand() % 100; })
#define cin_pair(a)   \
    for (auto &i : a) \
        cin >> i.FI >> i.SE;
#define set_val(v, x) memset(v, x, sizeof(v));
#define remove_Dublicates(v) v.erase(unique(v.begin(), v.end()), v.end()) // بس ورا بعضه
#define to_binary(bin) stoll(bin, nullptr, 10)
#define vvl vector<vll>
#define Floor(n, m) (((n) / (m)) - ((n) % (m) ? 0 : 1))
#define round(x, m) round(x / m) * m
#define fr(i, n) for (ll i = 0; i < n; i++)
#define fr1(i, n) for (ll i = 1; i <= n; i++)
#define clr(v, d) memset(v, d, sizeof(v));
// #define ordered_set tree<ll, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>
#define multi_ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define area_of_triangle sqrt((sum / 2) * (sum / 2 - arr[0]) * (sum / 2 - arr[1]) * (sum / 2 - arr[2]))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) return a / gcd(a, b) * b;
// #define put(s) return void(cout << s << dl);
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define vbo vector<bool>

#define pref(v) partial_sum(all(v), v.begin()) // بتعمل بيرفيكس بس في نفس الفيكتور
const ll mod = 1e9 + 7, N = 1e6 + 5;
const int M = 2 * 1e5 + 5;
template <typename T = int>
using Pair = pair<T, T>;
vector<string> RET = {"NO", "YES"};
#define SIZE 32
template <typename T = int>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}

template <typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const T &x : v)
        out << x << ' ';
    return out;
}
void AboooD()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}


void solve()
{
 // todo: add info about the algorithm.

  // Read the message to be encoded
  string mgs;
  cin >> mgs;

  // Calculate the number of bits needed for parity bits
  ll k = int(mgs.size());
  ll r = 0;
  while (1 << r < k + r + 1) r++;

  // Calculate the total number of bits in the code word
  ll n = k + r;

  // Initialize the code word with all zeros
  string codeWord(n, '0');

  int a = 0;
  // Fill the data bits in the code word
  for (int i = n - 1, j = 0; i >= 0; i--, j++) {
    // Skip the positions that are powers of 2 (parity bits)
    if (!(i + 1 and (!(i + 1 & i)))) {
      codeWord[j] = mgs[a++];
    }
  }

  // Calculate the values of parity bits
  vector<long long> res_of_Ps(r);
  int x = 1;
  reverse(codeWord.begin(), codeWord.end());
  for (int i = 0; i < r; i++) {
    // res_of_Ps[i] = 0;
    int cnt = (1 << i) - 1;
    bool check = true;
    for (int k = cnt; k < n; k += x) {
      if (check) {
        for (int t = k; t < k + x && t < n; t++) {
          res_of_Ps[i] ^= (codeWord[t] - '0');
        }
      }
      check = !check;
    }
    x *= 2;
  }

  // Update the code word with the values of parity bits
  x = 0;
  for (int i = 0; i < r; i++) {
    codeWord[(1 << i) - 1] = res_of_Ps[x] + '0';
    x++;
  }
  reverse(codeWord.begin(), codeWord.end());

  // Print the encoded code word
  cout << "Encoded codeWord is: " << codeWord;
  cout << "\n";
  cout << "*******************\n";

  //   Read the received code word
  string recivedCodeWord;
  cin >> recivedCodeWord;
  vector<long long> res_of_Ps_InResivedCodeWord(r);
  int error = 0;
  x = 1;
  reverse(recivedCodeWord.begin(), recivedCodeWord.end());
  // Calculate the values of parity bits in the received code word
  for (int i = 0; i < r; i++) {
    // res_of_Ps_InResivedCodeWord[i] = 0;
    int cnt = (1 << i) - 1;
    bool check = 1;
    for (int k = cnt; k < n; k += x) {
      if (check) {
        for (int t = k; t < k + x && t < n; t++) {
          if (k == cnt && k == t) continue;
          res_of_Ps_InResivedCodeWord[i] ^= (recivedCodeWord[t] - '0');
        }
      }
      check = !check;
    }

    x *= 2;
  }

  for (int i = 0; i < r; i++) {
    int a = (1 << i);
    // todo: check this handling :)
    if (res_of_Ps_InResivedCodeWord[i] != (recivedCodeWord[a - 1] - '0')) {
      error += a;
    }
  }

  reverse(recivedCodeWord.begin(), recivedCodeWord.end());

  // If no error is detected and the received code word matches the original code word
  if (error == 0 && recivedCodeWord == codeWord) {
    cout << "No error";
    cout << "\n";
    cout << "Code word: " << recivedCodeWord;
    cout << "\n";
  } else {
    cout << "Error in bit number " << error;
    cout << "\n";

    // Flip the bit at the detected error position to correct the error
    if (recivedCodeWord[n - error] == '0')
      recivedCodeWord[n - error] = '1';
    else
      recivedCodeWord[n - error] = '0';

    cout << "Correct code word: " << recivedCodeWord;
    cout << "\n";
  }
}

int main()
{
    AboooD();

    ll t = 1;
    // cin >> t;
    while (t--)
    {

        solve();
    }
    Time
        Time2
}
