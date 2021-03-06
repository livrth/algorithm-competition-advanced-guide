/*
* @Description: 106. 动态中位数
* @Author: Xiaobin Ren
* @Date:   2020-07-12 22:38:32
* @Last Modified time: 2020-07-12 22:50:42
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
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
//snippet-head




int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);

	int t, n, m;
	cin >> t;
	while(t --){
		priority_queue<int> q;  //大根堆
		priority_queue<int, vector<int>, greater<int> > p; //小根堆

		cin >> n >> m;
		cout << n << ' ' << (m + 1) / 2 << endl;
		int cnt = 0;
		for(int i = 1; i <= m; i++){  //读取样例所有数字
			cin >> n;
			p.push(n);
			if(q.size() && q.top() > p.top()){
				int a = p.top(), b = q.top();
				p.pop(); q.pop();
				p.push(b); q.push(a);
			}
			if(p.size() > q.size() + 1){
				q.push(p.top());
				p.pop();
			}
			if(i & 1)  printf("%d%c",p.top(),++cnt%10==0 ? '\n':' ');//每10个数换一行
		}
		if(cnt % 10) cout << endl;
	}
}