#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[505][505];
    int solve(vector<int>& nums1, vector<int>& nums2, int n, int m, int i, int j) {
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int a=0,b=0;
        if(nums1[i]==nums2[j]) {
           a = 1 + solve(nums1,nums2,n,m,i+1,j+1);
        }
        b = solve(nums1,nums2,n,m,i,j+1); // not equal
        int c = solve(nums1,nums2,n,m,i+1,j);
        return dp[i][j]=max({a,b,c});  
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums1,nums2,n,m,0,0);
    }
};