
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<TreeNode*> qe;
        qe.push(root);

        bool leftright = true;

        while(!qe.empty()) {
            int size = qe.size();
            vector<int> row(size);

            for(int i = 0; i < size; i++) {
                TreeNode* node = qe.front();
                qe.pop();

                int index = leftright ? i : size - i - 1;
                row[index] = node->val;

                if(node->left) {
                    qe.push(node->left);
                }

                if(node->right) {
                    qe.push(node->right);
                }
            }

            leftright = !leftright;
            ans.push_back(row);
        }

        return ans;
    }
};
