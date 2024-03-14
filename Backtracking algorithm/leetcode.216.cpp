class Solution {
public:
   vector<vector<int>>result;
   vector<int>path;  
   void dfs(int targetSum,int k,int sum,int startIndex)
   {
               if(path.size()==k)
               {
                    if(sum==targetSum)
                      result.push_back(path);
                      return;
               }
              for(int i = startIndex;i<=9;i++)
              {
                      sum+=i;      
                      path.push_back(i);
                      dfs(targetSum,k,sum,i+1);  // 下一层递归
                      sum-=i;  // 撤销操作
                      path.pop_back();
              }
   }
    vector<vector<int>> combinationSum3(int k, int n) {
                    dfs(n,k,0,1);
                    return result;
    }
};
