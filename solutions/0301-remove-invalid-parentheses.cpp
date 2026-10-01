// 301. Remove Invalid Parentheses [Hard] 
// https://leetcode.com/problems/remove-invalid-parentheses/ 
// Accepted submission: 2165733029; language: cpp 
// Problem statement (HTML): 
// <p>Given a string <code>s</code> that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.</p> 
//  
// <p>Return <em>a list of <strong>unique strings</strong> that are valid with the minimum number of removals</em>. You may return the answer in <strong>any order</strong>.</p> 
//  
// <p>&nbsp;</p> 
// <p><strong class="example">Example 1:</strong></p> 
//  
// <pre> 
// <strong>Input:</strong> s = &quot;()())()&quot; 
// <strong>Output:</strong> [&quot;(())()&quot;,&quot;()()()&quot;] 
// </pre> 
//  
// <p><strong class="example">Example 2:</strong></p> 
//  
// <pre> 
// <strong>Input:</strong> s = &quot;(a)())()&quot; 
// <strong>Output:</strong> [&quot;(a())()&quot;,&quot;(a)()()&quot;] 
// </pre> 
//  
// <p><strong class="example">Example 3:</strong></p> 
//  
// <pre> 
// <strong>Input:</strong> s = &quot;)(&quot; 
// <strong>Output:</strong> [&quot;&quot;] 
// </pre> 
//  
// <p>&nbsp;</p> 
// <p><strong>Constraints:</strong></p> 
//  
// <ul> 
// 	<li><code>1 &lt;= s.length &lt;= 25</code></li> 
// 	<li><code>s</code> consists of lowercase English letters and parentheses <code>&#39;(&#39;</code> and <code>&#39;)&#39;</code>.</li> 
// 	<li>There will be at most <code>20</code> parentheses in <code>s</code>.</li> 
// </ul> 

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        forward(s, res, 0, 0);

        return res;
    }

private:
    void forward(string s, auto& res, int li, int lj) {
        int bal = 0;

        for (int i = li; i < s.length(); i++) {
            bal += (s[i] == '(') - (s[i] == ')');

            if (bal >= 0) continue;

            for (int j = lj; j <= i; j++)
                if (s[j] == ')' && (j == lj || s[j - 1] != ')'))
                    forward(s.substr(0, j) + s.substr(j + 1), res, i, j);

            return;
        }

        backward(s, res, s.length() - 1, s.length() - 1);
    }

    void backward(string s, auto& res, int ri, int rj) {
        int bal = 0;

        for (int i = ri; i >= 0; i--) {
            bal += (s[i] == ')') - (s[i] == '(');

            if (bal >= 0) continue;

            for (int j = rj; j >= i; j--)
                if (s[j] == '(' && (j == rj || s[j + 1] != '('))
                    backward(s.substr(0, j) + s.substr(j + 1), res, i - 1,
                             j - 1);

            return;
        }

        res.push_back(s);
    }
};
