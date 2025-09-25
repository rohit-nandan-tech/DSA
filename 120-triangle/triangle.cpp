class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        for(int i=1;i<tri.size();i++){
            for(int j=0;j<tri[i].size();j++){
                int sum=0;
                if(j==0){
                    sum=tri[i][j]+tri[i-1][j];
                }
                else if(j==tri[i].size()-1){
                    sum=tri[i][j]+tri[i-1][j-1];
                }
                else{
                    int mini=min(tri[i-1][j],tri[i-1][j-1]);
                    sum=tri[i][j]+mini;
                }
                tri[i][j]=sum;
            }
        }
        int last_row=tri.size()-1;
        return *min_element(tri[last_row].begin(),tri[last_row].end());
    }
};