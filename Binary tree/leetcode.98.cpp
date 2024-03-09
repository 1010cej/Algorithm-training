class Solution {
public:
     vector<int>vec;
     void serch(TreeNode*root)  // 根据中序遍历的顺序放入数组
     {
          if(root==nullptr) return;
           serch(root->left);
          vec.push_back(root->val);
          serch(root->right);
     }
    bool isValidBST(TreeNode* root) {
           serch(root);

           for(int i = 1;i<vec.size();i++)
           {
                    if(vec[i]<=vec[i-1]) return false;  // 判断是否有序，但是效率并不高
                     
           }
           return true;
    }
};

// 双指针优化
class Solution {
public:
   TreeNode*pre = NULL;  // 前一个指针
    bool isValidBST(TreeNode* root) {
            if(root==nullptr) return true;
            bool left = isValidBST(root->left);  // 左
            if(pre!=NULL&&pre->val>=root->val) return false;  // 比较前一个结点和当前节点值  中
            pre = root;
            bool right = isValidBST(root->right);  // 右
            return left&&right;
    }
};
