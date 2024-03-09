class Solution {
public:
       TreeNode*pre = NULL;
       int result = INT_MAX;
     void tarversal(TreeNode*cur)
     {
         if(cur==nullptr) return;
         
         tarversal(cur->left); // 左
         if(pre!=NULL)
         {
               result = min(result,cur->val-pre->val); // 中
         }
         pre = cur;  // 在这段代码中隐藏了回溯，刚开始pre是为空的，不为空才会走比较最小值的逻辑
         tarversal(cur->right);  // 右
     }
    int getMinimumDifference(TreeNode* root) {
         tarversal(root);
         return result;
    }
};
