#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& arr, int low, int mid, int high) {

        int gap=high-low;
        while(gap>=1) {
            int idx=low;
            while(idx+gap <= high) {
                if(arr[idx] > arr[idx+gap]) {
                    swap(arr[idx],arr[idx+gap]);
                } 
                idx+=1;
            }
            if(gap==1) break;
            gap=(gap+1)/2;
        }
    }
    void mergeSort(vector<int>& nums, int low, int high) {
        if(low<high) {
            int mid=low+(high-low)/2;
            mergeSort(nums,low,mid);
            mergeSort(nums,mid+1,high);
            merge(nums,low,mid,high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};