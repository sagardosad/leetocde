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

class BSTIterator {
public:
    stack<TreeNode*> st;
    bool reverse;

    void pushall(TreeNode* root) {
        while (root != NULL) {
            st.push(root);

            if (!reverse)
                root = root->left;
            else
                root = root->right;
        }
    }

    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushall(root);
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();

        if (!reverse)
            pushall(temp->right);
        else
            pushall(temp->left);

        return temp->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator N(root, false);
        BSTIterator B(root, true);

        int i = N.next();
        int j = B.next();

        while (i < j) {
            if (i + j == k)
                return true;

            else if (i + j > k)
                j = B.next();

            else
                i = N.next();
        }

        return false;
    }
};
