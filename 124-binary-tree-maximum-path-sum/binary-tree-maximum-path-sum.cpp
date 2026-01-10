
class Solution {
public:
    int solve(TreeNode *root, int &ans){
        if(!root) return 0;
        int left = max(0, solve(root->left, ans));
        int right = max(0, solve(root->right,ans));
        ans = max(ans, root->val + left+ right);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};