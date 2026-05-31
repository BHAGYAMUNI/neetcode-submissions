class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>result;
        int r1 = 0;
        int r2 = matrix.size()-1;
        int c1 = 0;
        int c2 = matrix[0].size()-1;
        while(r1<=r2 && c1<=c2){
            //top
            for(int j = c1;j <= c2;j++){
                result.push_back(matrix[r1][j]);
            }
            //right
            for(int i = r1+1;i <= r2;i++){
                result.push_back(matrix[i][c2]);
            }
            //bottom
            for(int j = c2-1;j >= c1;j--){
                if(r1==r2){
                    break;
                }
                result.push_back(matrix[r2][j]);
            }
            //left
            for(int i = r2-1;i>=r1+1;i--){
                if(c1==c2){
                    break;
                }
                result.push_back(matrix[i][c1]);
            }
            r1++;
            r2--;
            c1++;
            c2--;
        }
        return result;     
    }
};