class Solution {
public:
    int ans=0;
    int dfs(TreeNode* root) {
        if(!root)
            return 0;
        int lh=dfs(root->left);
        int rh=dfs(root->right);
        ans=max(ans, lh+rh+1);
        return max(lh, rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans-1;
    }
};
