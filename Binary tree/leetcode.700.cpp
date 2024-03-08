class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
               if(root==nullptr||root->val==val) return root;
                // 迭代写法
               while(root)
               {
                      if(root->val>val)
                      root = root->left;
                      else if(root->val<val)
                      root = root->right;
                       else return root;
               }
               return nullptr;
    }
};
