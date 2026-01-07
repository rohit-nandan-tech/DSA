class Solution {
public:
    long long totalSum = 0;
    long long ans = 0;
    static const int MOD = 1e9 + 7;

    // First DFS: calculate subtree sums
    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subTreeSum = root->val + left + right;

        // product if we cut above this subtree
        long long product = subTreeSum * (totalSum - subTreeSum);
        ans = max(ans, product);

        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {
        // First pass: get total sum
        totalSum = getTotalSum(root);

        // Second pass: compute max product
        dfs(root);

        return ans % MOD;
    }

private:
    long long getTotalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
    }
};
