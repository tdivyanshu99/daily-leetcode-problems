class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top=0,bottom=n-1,left=0,right=n-1;
        vector<vector<int>> res(n,vector<int>(n));
        int num=1;
        int dir=0;
        while(top<=bottom && left<=right) {
            if(dir==0) {
                for(int i=left;i<=right;i++) {
                    res[top][i]=num;
                    num++;
                }
                top++;
            }
            if(dir==1) {
                for(int i=top;i<=bottom;i++) {
                    res[i][right]=num;
                    num++;
                }
                right--;
            }
            if(dir==2) {
                for(int i=right;i>=left;i--) {
                    res[bottom][i]=num;
                    num++;
                }
                bottom--;
            }
            if(dir==3) {
                for(int i=bottom;i>=top;i--) {
                    res[i][left]=num;
                    num++;
                }
                left++;
            }
            dir=(dir+1)%4;
        }
        return res;
    }
};