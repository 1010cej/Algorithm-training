class Solution {
public:
     vector<int>path;
     vector<vector<int>>result;
    void backtacking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used){
            if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            // 要对同一树层使用过的元素进行跳过
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtacking(candidates, target, sum, i + 1, used); // 和39.组合总和的区别1，这里是i+1，每个数字在每个组合中只能使用一次
            used[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
                          vector<bool>used(candidates.size(),false);
                          path.clear();
                          result.clear();
                         sort(candidates.begin(),candidates.end());
                        backtacking(candidates,target,0,0,used);
                        return result;
    }
};
