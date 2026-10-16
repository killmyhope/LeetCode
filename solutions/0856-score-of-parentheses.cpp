// 856. Score of Parentheses [Medium] 
// https://leetcode.com/problems/score-of-parentheses/ 
// Accepted submission: 2174192580; language: cpp 
// Problem statement (HTML): 
// <p>Given a balanced parentheses string <code>s</code>, return <em>the <strong>score</strong> of the string</em>.</p> 
//  
// <p>The <strong>score</strong> of a balanced parentheses string is based on the following rule:</p> 
//  
// <ul> 
// 	<li><code>&quot;()&quot;</code> has score <code>1</code>.</li> 
// 	<li><code>AB</code> has score <code>A + B</code>, where <code>A</code> and <code>B</code> are balanced parentheses strings.</li> 
// 	<li><code>(A)</code> has score <code>2 * A</code>, where <code>A</code> is a balanced parentheses string.</li> 
// </ul> 
//  
// <p>&nbsp;</p> 
// <p><strong class="example">Example 1:</strong></p> 
//  
// <pre> 
// <strong>Input:</strong> s = &quot;()&quot; 
// <strong>Output:</strong> 1 
// </pre> 
//  
// <p><strong class="example">Example 2:</strong></p> 
//  
// <pre> 
// <strong>Input:</strong> s = &quot;(())&quot; 
// <strong>Output:</strong> 2 
// </pre> 
//  
// <p><strong class="example">Example 3:</strong></p> 
//  
// <pre> 
// <strong>Input:</strong> s = &quot;()()&quot; 
// <strong>Output:</strong> 2 
// </pre> 
//  
// <p>&nbsp;</p> 
// <p><strong>Constraints:</strong></p> 
//  
// <ul> 
// 	<li><code>2 &lt;= s.length &lt;= 50</code></li> 
// 	<li><code>s</code> consists of only <code>&#39;(&#39;</code> and <code>&#39;)&#39;</code>.</li> 
// 	<li><code>s</code> is a balanced parentheses string.</li> 
// </ul> 

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                st.push(0);
            else if (s[i] == ')' && !st.empty()) {
                int temp = st.top();
                st.pop();
                temp == 0 ? st.top() += 1 : st.top() += temp * 2;
            }
        }
        return st.top();
    }
};
