class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
           TreeNode* node = new TreeNode(0);
if(nums.size() == 1)
{
    node->val = nums[0];
    return node;
}

int maxValue = 0;
int index = 0;
for(int i = 0; i < nums.size(); i++)
{
    if(nums[i] > maxValue)
    {
        maxValue = nums[i];
        index = i;
    }
}
node->val = maxValue;

if(index > 0)
{
    vector<int> newVec(nums.begin(), nums.begin() + index);
    node->left = constructMaximumBinaryTree(newVec);
}

if(index < nums.size() - 1)
{
    vector<int> newVec(nums.begin() + index + 1, nums.end());
    node->right = constructMaximumBinaryTree(newVec);
}

return node;
    }
};
