class Solution {
public:
    /**
     * @param s: a string
     * @return: the length of the longest substring T that contains at most 2 distinct characters
     */
    int lengthOfLongestSubstringTwoDistinct(string &s) {
        // Write your code here
        unordered_map<char,int> mp;
        int i=0;
        int j=0;
        int maxi=0;
        while(j<s.size()){
            mp[s[j]]++;
            if(mp.size()<=2){
                maxi=max(maxi,j-i+1);
            }
            else if(mp.size()>2){
                while(i<j && mp.size()>2){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
                if(i<j){
                    maxi=max(maxi,j-i+1);
                }
            }
            j++;
        }
        return maxi;
    }
};