// 32. Longest Valid Parentheses [Hard] 
// https://leetcode.com/problems/longest-valid-parentheses/ 
// Accepted submission: 2161070707; language: cpp 
// Problem statement (HTML): 
// <p>Given a string containing just the characters <code>&#39;(&#39;</code> and <code>&#39;)&#39;</code>, return <em>the length of the longest valid (well-formed) parentheses </em><span data-keyword="substring-nonempty"><em>substring</em></span>.</p> 
//  
// <p>&nbsp;</p> 
// <p><strong class="example">Example 1:</strong></p> 
//  
// <pre> 
// <strong>Input:</strong> s = &quot;(()&quot; 
// <strong>Output:</strong> 2 
// <strong>Explanation:</strong> The longest valid parentheses substring is &quot;()&quot;. 
// </pre> 
//  
// <p><strong class="example">Example 2:</strong></p> 
//  
// <pre> 
// <strong>Input:</strong> s = &quot;)()())&quot; 
// <strong>Output:</strong> 4 
// <strong>Explanation:</strong> The longest valid parentheses substring is &quot;()()&quot;. 
// </pre> 
//  
// <p><strong class="example">Example 3:</strong></p> 
//  
// <pre> 
// <strong>Input:</strong> s = &quot;&quot; 
// <strong>Output:</strong> 0 
// </pre> 
//  
// <p>&nbsp;</p> 
// <p><strong>Constraints:</strong></p> 
//  
// <ul> 
// 	<li><code>0 &lt;= s.length &lt;= 3 * 10<sup>4</sup></code></li> 
// 	<li><code>s[i]</code> is <code>&#39;(&#39;</code>, or <code>&#39;)&#39;</code>.</li> 
// </ul> 

class Solution {
public:
    int longestValidParentheses(auto& s) {
        int res = 0;
        vector<int> stack = {-1};
        for (int i = 0; i < s.size(); i++) 
        {
            if (s[i] == '(') stack.push_back(i);
            else 
            {
                stack.pop_back();
                if (stack.empty())stack.push_back(i);
                else res = max(res, i - stack.back());
            }
        }
        return res;
    }
};
