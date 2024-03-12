class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
      // 通过上层递归返回的节点来达到删除节点的效果
      // 当前节点不满足边界情况时，它的左右子树有可能是满足条件的，所以需要将满足条件的节点返回
                  if(root==nullptr)
                  return root; 
                  if(root->val<low){
                       return trimBST(root->right,low,high);   // 肯定在右边界
                  }
                  if(root->val>high){
                      return trimBST(root->left,low,high);  // 往左边找
                      }
      
      root->left = trimBST(root->left,low,high);  // 向左递归
      root->right =  trimBST(root->right,low,high);  // 向右递归
                return root;
    }
};
