#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
const int N=100;
ll n,v[N],w[N],W,memo [N][100001];
ll knapsack(ll ind,ll wt)
{
    if(ind >=n) return 0;
    ll &ans=memo[ind][wt];
    if(ans!= -1) return ans;
    ans=knapsack(ind+1 , wt);
    if(w[ind] + wt <= W){
        ans = max( ans,v[ind] + knapsack(ind+1,w[ind]+wt));
    }
    return ans;
}
int32_t main() {

    cin>>n>>W;
    for (ll i = 0; i < n; i++) {
        cin>>w[i]>>v[i];
    }
    memset(memo, -1, sizeof(memo));
    cout<<knapsack(0,0);
    return 0;
    
}
