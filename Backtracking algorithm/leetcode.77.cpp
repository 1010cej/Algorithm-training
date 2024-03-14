class Solution {
public:
    vector<int>path;
    vector<vector<int>>result;
    void dfs(int n,int k,int startIndex){
              if(path.size()==k)  // 回溯终止条件
              {
                 result.push_back(path);
                 return;
              }
              for(int i = startIndex;i<=n;i++)
              {
                      path.push_back(i);
                      dfs(n,k,i+1);
                      path.pop_back();   // 撤销操作
              }
    }
    vector<vector<int>> combine(int n, int k) {
              dfs(n,k,1);
              return result;
    }
};
