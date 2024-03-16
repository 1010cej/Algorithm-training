class Solution {
public:
          const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };

      string s;
      vector<string>result;
      void Backtracking(string digits,int index)
      {
            if(index==digits.size())
            {
                 result.push_back(s);
                 return;
            }
            int digit = digits[index]-'0';
            string letter = letterMap[digit];
            for(int i = 0;i<letter.size();i++)
            {
                    s.push_back(letter[i]);
                    Backtracking(digits,index+1);
                    s.pop_back();
            }
      }
    vector<string> letterCombinations(string digits) {
            if(digits.size()==0){
                  return  result;
            }
             Backtracking(digits,0);
             return result;
    }
};
