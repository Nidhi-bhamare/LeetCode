class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int r0, int c0) {
        vector<vector<int>> ans(rows*cols);
        ans[0]={{r0, c0}};
        int layer=max({rows-r0, cols-c0, r0+1, c0+1});
        vector<array<vector<vector<int>>, 4>> ring(layer);
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                int d=max(abs(i-r0), abs(j-c0));
                int region;
                if (j-c0==d && i>=r0-d+1) region=0;//downward
                else if (i-r0==d) region=1;//leftward
                else if (j-c0==-d) region=2;//upward
                else region=3;//rightward
                ring[d][region].push_back({i, j});
            }
        }
        int idx=1;
        for(int m=1; m<layer; m++){
            for(int region=0; region<4; region++){
                int sz=ring[m][region].size();
                if (region==1 || region==2) //these 2 parts should be reversed
                    reverse(ring[m][region].begin(), ring[m][region].end());
                copy(ring[m][region].begin(), ring[m][region].end(), ans.begin()+idx);
                idx+=sz;
            }
        }
        return ans;
    }
};