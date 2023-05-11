#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& v, vector<int>& arr, int start, int end) {
	int n=end-start+1;
		
	for(int i=0;i<(2^n);i++) {
		int x=i;
		int j=start;
		int sum=0;
		while(x>0) {
			if(x&1) {
				sum+=arr[j];
			}
			j++;
			x=(x>>1);
		}
		v.push_back(sum);
	}
}
int main() {
	// your code goes here
	int n,a,b;
	cin>>n>>a>>b;
	vector<int> v(n);
	for(int i=0;i<n;i++) {
		cin>>v[i];
	}
	vector<int> v1,v2;
	solve(v1,v,0,n/2-1);
	solve(v2,v,n/2,n-1);
	sort(v2.begin(),v2.end());
	int cnt=0;
	for(int i=0;i<v1.size();i++) {
		int lower=lower_bound(v2.begin(),v2.end(),a-v1[i]) - v2.begin();
		int upper=upper_bound(v2.begin(),v2.end(),b-v1[i]) - v2.begin();
		cnt+=(upper-lower);
	}
	// for(int i=0;i<v1.size();i++) {
	// 	if(v1[i]>=a && v1[i]<=b) cnt++;
	// }
	cout<<cnt<<endl;
	
	return 0;
}