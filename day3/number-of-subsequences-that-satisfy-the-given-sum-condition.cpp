#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        vector<int> vec;
        vec.push_back(1);
        for(int i=1;i<nums.size();i++) {
            vec.push_back((vec.back()*2)%mod);
        }
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        int cnt=0;
        while(i<=j) {
            if(nums[i]+nums[j] <= target) {
                int power=j-i;
                cnt=cnt%mod + vec[power]%mod;
                cnt=cnt%mod;
                i++;
            }
            else j--;
        }
        return cnt;
    }
};