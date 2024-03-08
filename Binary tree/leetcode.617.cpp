class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
          TreeNode*root = new TreeNode(); // 创建新二叉树
           if(root1==nullptr) return root2;
           if(root2==nullptr)  return root1;
           root->val = root1->val+root2->val;  // 新二叉树的value  中
           root->left = mergeTrees(root1->left,root2->left);  //  左
           root->right = mergeTrees(root1->right,root2->right);  // 右
          return root;
    }
};
