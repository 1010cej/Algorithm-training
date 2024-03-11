class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
           if(root==NULL) return root;
           while(root)
           {
                 if(root->val>p->val&&root->val>q->val)  // 在左子树内查找
                 {
                     root = root->left;
                 }
                else  if(root->val<p->val&&root->val<q->val)  // 在右子树内查找
                 {
                     root = root->right;
                 }
                  else return root;
           }
           return root;
    }
};
