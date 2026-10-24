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
    int maxPathdown(TreeNode* node,int&maxi){
        if(node==NULL) return 0;
        int left_sum=max(0,maxPathdown(node->left,maxi));
        int right_sum=max(0,maxPathdown(node->right,maxi));
        maxi=max(maxi,node->val+left_sum+right_sum);
        return node->val+max(left_sum,right_sum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxPathdown(root,maxi);
        return maxi;
    }
};