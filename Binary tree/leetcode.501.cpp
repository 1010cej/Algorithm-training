/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     TreeNode*pre = nullptr;
     int count = 0;
     int Maxcount = 0;
     vector<int>result;

     void search(TreeNode*cur)
     {
               if(cur==nullptr) return;
               search(cur->left); // 左
               if(pre==nullptr){   // 置为1
                     count = 1;
               }
               else if(pre->val==cur->val) {
                     count++;  // 如果前一个遍历的节点的值等于当前节点的值 ，则计数器++
               }
               else {
                    count = 1;  // 重置为1
               }

                pre = cur;
                if(count==Maxcount){
                     result.push_back(cur->val);
               }

                if(count>Maxcount)  // 如果当前最大频率大于出现次数最多次数的频率
                {
                    Maxcount = count;  // 更新频率
                    result.clear();  // 清空不需要的数据
                    result.push_back(cur->val);  // 重新加入元素
                }

                search(cur->right);  //  右
                return;
     }
    vector<int> findMode(TreeNode* root) {

              count = 0;
              Maxcount = 0;
              pre = nullptr; 
              result.clear();

               search(root);
               return result;
    }
};
