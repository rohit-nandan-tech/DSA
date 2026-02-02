// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size(), m = arr[0].size();
        
        int row = -1;
        int j = m - 1;
        
        
        for(int i =  0 ; i  < n ; i++){
            while(j >=0 and arr[i][j] == 1){
                j--;
                row = i;
            }
        }
        
        return row;
        
    }
};