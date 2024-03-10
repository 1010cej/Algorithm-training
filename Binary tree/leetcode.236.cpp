class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
          if(root==NULL) return root;
          if(root==p||root==q) return root;

         
          TreeNode*left = lowestCommonAncestor(root->left,p,q);
          TreeNode*right = lowestCommonAncestor(root->right,p,q);
           if(left!=NULL&&right!=NULL)  // 左子树和右子树都不为空的情况下
           return root;


          if(left==NULL&&right!=NULL){   // 包含p或q
               return right;
          }
          else if(left!=NULL&&right==NULL) 
          {
               return left;
          }
          else {
               return NULL;  
          }

    }
};
