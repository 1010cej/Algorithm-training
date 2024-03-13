class Solution {
public:
     int pre = 0;
     void tarversal(TreeNode*root)
     {
        if(root==nullptr) return;
        tarversal(root->right); // 右
        root->val+=pre;  // 累加 中
        pre = root->val;   // 保存
        tarversal(root->left);  // 左
     }
    TreeNode* bstToGst(TreeNode* root) {
              tarversal(root);
              return root;
    }
};
