/*
* @Description: 93. 递归实现组合型枚举
* @Author: Xiaobin Ren
* @Date:   2020-05-01 20:18:07
* @Last Modified time: 2020-05-01 20:24:43
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i = a; i< n; i++)
#define per(i,a,n) for(int i=n-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod = 1000000007;
int rnd(int x) { return mrand() % x;}
ll mulmod(ll a, ll b) {ll res=0;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=(res+a)%mod;a=2*a%mod;}return res;}
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res*=a%mod;a*=a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
//competitive-programing-snippet-head


int n, m;
VI nums;

void dfs(int k){
	if(nums.size() > m || nums.size() + (n - k + 1) < m) return ;
	if(k == n + 1){
		rep(i, 0, sz(nums)) cout << nums[i] << ' ';
	cout << endl;
	return ;
    }

	nums.push_back(k);
	dfs(k + 1);
	nums.pop_back();
	dfs(k + 1);
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cin >> n>> m;
	dfs(1);

	return 0;
	
}