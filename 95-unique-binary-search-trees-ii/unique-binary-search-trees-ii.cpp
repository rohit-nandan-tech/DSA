/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    unordered_map<string, vector<TreeNode*>> dp;

    vector<TreeNode*> solve(int start, int end){
        if(start > end) return {nullptr};

        string str = to_string(start) + "," + to_string(end);

        if (dp.count(str)) return dp[str];

        vector<TreeNode*> ans;

        for(int i =  start; i <= end; i++){
            vector<TreeNode*> left = solve(start, i - 1);
            vector<TreeNode*> right = solve(i + 1, end);
            for(auto lNodes: left){
                for(auto rNodes: right){
                    TreeNode* node = new TreeNode(i);
                    node->left = lNodes;
                    node->right = rNodes;

                    ans.push_back(node);
                }
            }
        }
        return dp[str] = ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};

        return solve(1, n);
    }
};