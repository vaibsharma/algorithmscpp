#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ff first
#define se second
#define pb push_back
#define nn 100100
#define mt make_tuple
#define mp make_pair
#define ll long long int
#define db double
#define ldb long double
#define inf 1000000000000000000ll
#define logn 20
#define mod 1000000007ll
#define mod1 mod
#define mod2 100000009ll
#define sqr(a) a*1ll*a
#define nullp mp(-1,-1)
#define set0(a) memset(a,0,sizeof a)
#define init(a) memset(a,-1,sizeof a)
#define cmp 1e-11
 
using namespace std;
using namespace __gnu_pbds;

typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
typedef pair<long double,long double> pdd;
template<class T>
using max_pq = priority_queue<T>;
template<class T>
using min_pq = priority_queue<T,vector<T>,greater<T>>;
typedef tree<int, null_type, less<int>, rb_tree_tag, 
tree_order_statistics_node_update> OST;

ll toint(const string &s) {stringstream ss; ss << s; ll x; ss >> x; return x;}
string tostring ( ll number ){stringstream ss; ss<< number; return ss.str();}
template<class T> T gcd(T a,T b){return (b==0)? a:gcd(b,a%b); }
ll pow(ll a,ll p,ll m=mod)
{ll res=1;while(p>0){if(p&1)res = (res*a)%m;a=(a*a)%m;p>>=1;}return res;}

const ldb pi=3.141592653589793238462643383;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    int a[n+1],b[n+1];
    for(int i=0;i<n;i++)
    	cin>>a[i];
    std::vector<int> v,v2;
    int mark[nn],ans[nn];
    memset(mark,0,sizeof mark);
    memset(ans,0,sizeof ans);
    for(int i=0;i<n;i++)
    {
    	cin>>b[i];
    	if(b[i]==a[i])
    	{
    		ans[i]=a[i];
    		mark[a[i]]=i+1;
    	}
    	else
    	{
    		v.pb(i);
    	}
    }
    for(int i=1;i<=n;i++)
    {
    	if(!mark[i])
    	{
    		v2.pb(i);
    	}
    }
    
    if(v.size()==1)
    {
    	for(int i=0;i<n;i++)
    	{
    		if(mark[i+1]==0)
    		{
    			ans[v[0]]=i+1;
    		}
    	}
    }
    else if(v.size()==2)
    {
    	int i=v[0],j=v[1];
    	if(mark[a[i]]==0 && mark[b[j]]==0)
    	{
    		ans[i]=a[i];
    		ans[j]=b[j];
    	}
    	else
    	{
    		ans[i]=b[i];
    		ans[j]=a[j];
    	}
    }
    for(int i=0;i<n;i++)
    	cout<<ans[i]<<' ';
    return 0;
}
