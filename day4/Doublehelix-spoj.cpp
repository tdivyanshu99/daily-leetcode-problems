//@kakovic
#include <bits/stdc++.h> 
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define pb push_back 
#define all(v) v.begin(),v.end()
#define forn(i, a, n) for (int i = a; i < int(n); ++i)
typedef long long ll;
typedef pair<ll,ll> pll;
typedef map<int,int> mi;
typedef unordered_map<int,int> umi;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pi;

void solve(){
    
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t=1;
    
    while(true){
        //res=INT_MAX;
        int n,m;
        cin>>n;
        if(n==0) break;
        vector<int> first(n);
        unordered_map<int,int> mp;
        forn(i,0,n) {
        cin>>first[i];
        mp[first[i]]=i;  
        } 
        cin>>m;
        vector<int> second(m);
        vector<int> vfir,vsec;
        forn(i,0,m) {
            cin>>second[i];
            if(mp.find(second[i])!=mp.end()) {
                vfir.push_back(mp[second[i]]);
                vsec.push_back(i);
            }
        } 
        for(int i=1;i<n;i++) {
            first[i]+=first[i-1];
        }
        for(int i=1;i<m;i++) {
            second[i]+=second[i-1];
        }
        if(vfir.size()>0) {
            int sumA = first[vfir[0]];
            int sumB = second[vsec[0]];
            int sum=max(sumA,sumB);
            for(int i=1;i<vfir.size();i++) {
                int idx = vfir[i];
                int prevIdx = vfir[i-1];
                int idx1 = vsec[i];
                int prevIdx1 = vsec[i-1];
                int a = first[idx] - first[prevIdx];
                int b = second[idx1] - second[prevIdx1];
                sum+=max(a,b);
            }
            int c = first[n-1] - first[vfir[vfir.size()-1]];
            int d = second[m-1] - second[vsec[vsec.size()-1]];
            sum+=max(c,d);
            cout<<sum<<endl;
        }
        else {
            cout<<max(first[n-1],second[m-1])<<endl;
        }
       //solve();
    }
}