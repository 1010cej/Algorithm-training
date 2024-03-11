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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
            if(root==nullptr)
            {
                  TreeNode*node =  new TreeNode(val);   // 返回到下面
                  return node;
            }

               if(root->val>val) root->left = insertIntoBST(root->left,val);  // 递归左子树
               if(root->val<val) root->right = insertIntoBST(root->right,val);  // 递归右子树
               return root; // 插入完成返回根节点
    }
};
