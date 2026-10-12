// 22. Generate Parentheses [Medium] 
// https://leetcode.com/problems/generate-parentheses/ 
// Accepted submission: 2170329237; language: cpp 
// Problem statement (HTML): 
// <p>Given <code>n</code> pairs of parentheses, write a function to <em>generate all combinations of well-formed parentheses</em>.</p> 
//  
// <p>&nbsp;</p> 
// <p><strong class="example">Example 1:</strong></p> 
// <pre><strong>Input:</strong> n = 3 
// <strong>Output:</strong> ["((()))","(()())","(())()","()(())","()()()"] 
// </pre><p><strong class="example">Example 2:</strong></p> 
// <pre><strong>Input:</strong> n = 1 
// <strong>Output:</strong> ["()"] 
// </pre> 
// <p>&nbsp;</p> 
// <p><strong>Constraints:</strong></p> 
//  
// <ul> 
// 	<li><code>1 &lt;= n &lt;= 8</code></li> 
// </ul> 

class Solution {
private:
    vector<string> ans;
    void backtrack(string &s, int op, int cl)
    {
        if (cl==0 && op==0)
        {
            ans.push_back(s);
            return;
        }
        if(op>0)
        {
            s.push_back('(');
            backtrack(s,op-1,cl);
            s.pop_back();
        }
        if (cl>op)
        {
            s.push_back(')');
            backtrack(s,op,cl-1);
            s.pop_back();
        }
    }



public:
    vector<string> generateParenthesis(int n) 
    {
        string s = "";
        backtrack (s,n,n);
        return ans;    
    }
};
