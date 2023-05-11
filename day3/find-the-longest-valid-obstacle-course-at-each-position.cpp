#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        int n=nums.size();
        vector<int> v;
        vector<int> res(n);
        for(int i=0;i<nums.size();i++) {
            int idx=upper_bound(v.begin(),v.end(),nums[i]) - v.begin();
            if(idx==v.size()) {
                v.push_back(nums[i]);
                res[i]=idx+1;
            }
            else {
                v[idx]=nums[i];
                res[i]=idx+1;
            }
        }
        return res;
    }
};
// 1 2 3 2