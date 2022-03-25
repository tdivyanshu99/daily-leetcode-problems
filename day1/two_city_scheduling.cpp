class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& vec) {
       int n=vec.size();
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            //cout<<i<<endl;
            pq.push({(vec[i][1]-vec[i][0]),{vec[i][0],vec[i][1]}});
        }
        cout<<pq.size()<<"+++"<<endl;
        int cntA=0;
        int res=0;
        while(!pq.empty()){
            auto c=pq.top();
            //cout<<c.first<<"-->"<<c.second.first<<"**"<<c.second.second<<endl;
            pq.pop();
            if(cntA<n/2){
                cntA++;
                res+=c.second.first;
                //pq.pop();
            }
            else {
                res+= c.second.second;
            }
        }
        return res;
    }
};