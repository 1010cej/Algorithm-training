class Solution {
public:
     TreeNode*tarversal(vector<int>&nums,int left,int right)
     {
             if(left>right) return nullptr;

             int mid = (left+right)/2;  // 计算数组的中间元素的下标

             TreeNode*root = new TreeNode(nums[mid]); // 从中间节点开始构造
             root->left = tarversal(nums,left,mid-1); // 分割区间  left,mid-1
             root->right = tarversal(nums,mid+1,right); // mid+1,right 
             return root;
     }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
           return tarversal(nums,0,nums.size()-1); // 左闭右闭区间  

    }
};
