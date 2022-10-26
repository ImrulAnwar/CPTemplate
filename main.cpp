#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define getDoubleTill(x, y) fixed<<setprecision(y)<<x
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define full(x) x.begin(), x.end()
#define clr(x) memset(x, -1, sizeof(x))
#define sortall(x) sort(full(x))
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x) // how many zeroes in right of the first one
#define PI 3.1415926535897932384626
#define inf 1e18
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
// to shuffle the array, pass this as an argument
const int mod = 1'000'000'007;

bool isEven(ll x);

bool isOdd(ll x);

ll _ceil(ll n, ll y);

ll _floor(ll n, ll y);

ll gcd(ll a, ll b);

ll lcm(ll a, ll b);

ll power(ll base, ll exp);

ll random(ll lim);

bool isPrime(ll n);

bool isDivisible(ll x, ll y);

ll nextPrime(ll x);

ll floorSqrt(ll x);

void printVector(const vector<ll> &r);

void printVectorOfPairs(const vector<pair<ll, ll>> &r);

void prefixSum(vector<ll> &org, vector<ll> &ps);

void allPremutations(vector<ll> arr);

void solution() {

}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t = 1;
	ll ct = 1;
	cin >> t;
	while (t--) {
//		cout << "Case " << ct++ << ": ";
		solution();
	}
	return 0;
}

bool isEven(ll x) {
	//	O(1)
	return x % 2LL == 0LL;
}

bool isOdd(ll x) {
	//	O(1)
	return x % 2LL != 0LL;
}

ll _ceil(ll n, ll y) {
	//	O(1)
	return (n % y == 0) ? n / y : n / y + 1;
}

ll _floor(ll n, ll y) {
	//	O(1)
	return n / y;
}

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return (a * b) / gcd(a, b);
}

ll power(ll base, ll exp) {
	//binary exponentiation
	base %= mod;
	ll result = 1;
	while (exp > 0) {
		if (exp & 1) result = (result * base) % mod;
		base = (base * base) % mod;
		exp >>= 1;
	}
	return result;
}

ll random(ll lim) {
	uniform_int_distribution<ll> uid(0, lim - 1);
	return uid(rang);
}

bool isPrime(ll n) {
	// O(sqrt(n))
	if (n < 2) return false;
	if (n < 4) return true;
	if (n % 2 == 0) return false;
	for (ll i = 3; i * i <= n; i += 2)
		if (n % i == 0) return false;
	return true;
}

bool isDivisible(ll x, ll y) {
	return x % y == 0;
}

ll nextPrime(ll x) {
	while (true) {
		if (isPrime(x)) return x;
		x++;
	}
}

ll floorSqrt(ll x) {
	// O(log n)
	if (x == 0 || x == 1) return x;
	ll start = 1, end = x / 2, ans;
	while (start <= end) {
		ll mid = (start + end) / 2;
		ll sqr = mid * mid;
		if (sqr == x) return mid;
		if (sqr <= x) {
			start = mid + 1;
			ans = mid;
		} else
			end = mid - 1;
	}
	return ans;
}

void printVector(const vector<ll> &r) {
	for (int i = 0; i < r.size(); i++) {
		cout << r[i] << " ";
	}
	cout << endl;
}

void printVectorOfPairs(const vector<pair<ll, ll>> &r) {
	for (int i = 0; i < r.size(); i++) {
		cout << r[i].first << " " << r[i].second << endl;
	}
}

void prefixSum(vector<ll> &org, vector<ll> &ps) {
	while (!ps.empty()) ps.pop_back();
	ll sum = 0;
	for (ll i = 0; i < org.size(); i++) {
		sum += org[i];
		ps.push_back(sum);
	}
}

void printAllPremutations(vector<ll> &arr) {
	sortall(arr);
	do {
		printVector(arr);
	} while (next_permutation(full(arr)));
}