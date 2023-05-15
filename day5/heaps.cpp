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

void insert(vector<int>& v, int num) {

    v.push_back(num);
    int end=v.size()-1;
    while(end>0 && v[(end-1)/2] < v[end]) {
        swap(v[end],v[(end-1)/2]);
        end=(end-1)/2;
    }
}
// heapify means top to bottom
void heapify(vector<int>& v, int i) {
    int largest=i;
    int left=2*i+1;
    int right=2*i+1;
    if(left<v.size() && v[left] > v[largest]) largest=left;
    if(right<v.size() && v[right] > v[largest]) largest=right;

    if(largest!=i) {
        swap(v[largest],v[i]);
        heapify(v,largest);
    }
}

int remove(vector<int>& v) {
    int n=v.size();
    int a=v[0];
    v[0]=v[n-1];
    v.pop_back();
    heapify(v,0);
    return a;
}
void replace(vector<int>& v, int i, int num) {

    if(num < v[i]) {
        v[i]=num;
        heapify(v,i);
    }
    else {
        int end=i;
        v[i]=num;
        while(end>0 && v[(end-1)/2] < v[end]) {
            swap(v[(end-1)/2], v[end]);
            end=(end-1)/2;
        }
    }
}
void solve(){
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        insert(v,a);
    }
    forn(i,0,n) cout<<v[i]<<" ";
    cout<<endl;
    // cout<<remove(v)<<endl;
    // cout<<remove(v)<<endl;
    // cout<<remove(v)<<endl;
    // cout<<remove(v)<<endl;
    replace(v,2,100);
    forn(i,0,n) cout<<v[i]<<" ";
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}