// 20. Valid Parentheses [Easy] 
// https://leetcode.com/problems/valid-parentheses/ 
// Accepted submission: 2170323599; language: cpp 
// Problem statement (HTML): 
// <p>Given a string <code>s</code> containing just the characters <code>&#39;(&#39;</code>, <code>&#39;)&#39;</code>, <code>&#39;{&#39;</code>, <code>&#39;}&#39;</code>, <code>&#39;[&#39;</code> and <code>&#39;]&#39;</code>, determine if the input string is valid.</p> 
//  
// <p>An input string is valid if:</p> 
//  
// <ol> 
// 	<li>Open brackets must be closed by the same type of brackets.</li> 
// 	<li>Open brackets must be closed in the correct order.</li> 
// 	<li>Every close bracket has a corresponding open bracket of the same type.</li> 
// </ol> 
//  
// <p>&nbsp;</p> 
// <p><strong class="example">Example 1:</strong></p> 
//  
// <div class="example-block"> 
// <p><strong>Input:</strong> <span class="example-io">s = &quot;()&quot;</span></p> 
//  
// <p><strong>Output:</strong> <span class="example-io">true</span></p> 
// </div> 
//  
// <p><strong class="example">Example 2:</strong></p> 
//  
// <div class="example-block"> 
// <p><strong>Input:</strong> <span class="example-io">s = &quot;()[]{}&quot;</span></p> 
//  
// <p><strong>Output:</strong> <span class="example-io">true</span></p> 
// </div> 
//  
// <p><strong class="example">Example 3:</strong></p> 
//  
// <div class="example-block"> 
// <p><strong>Input:</strong> <span class="example-io">s = &quot;(]&quot;</span></p> 
//  
// <p><strong>Output:</strong> <span class="example-io">false</span></p> 
// </div> 
//  
// <p><strong class="example">Example 4:</strong></p> 
//  
// <div class="example-block"> 
// <p><strong>Input:</strong> <span class="example-io">s = &quot;([])&quot;</span></p> 
//  
// <p><strong>Output:</strong> <span class="example-io">true</span></p> 
// </div> 
//  
// <p><strong class="example">Example 5:</strong></p> 
//  
// <div class="example-block"> 
// <p><strong>Input:</strong> <span class="example-io">s = &quot;([)]&quot;</span></p> 
//  
// <p><strong>Output:</strong> <span class="example-io">false</span></p> 
// </div> 
//  
// <p>&nbsp;</p> 
// <p><strong>Constraints:</strong></p> 
//  
// <ul> 
// 	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li> 
// 	<li><code>s</code> consists of parentheses only <code>&#39;()[]{}&#39;</code>.</li> 
// </ul> 

class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        int n = s.size();
        for (int i =0;i<n;i++)
        {
            if (s[i]=='{' || s[i]=='(' || s[i]=='[')
            st.push(s[i]);
            else if (!st.empty()&& (st.top()=='{'&& s[i]=='}'||st.top()=='(' && s[i]==')'||st.top()=='[' &&s[i]==']'))
                st.pop();
            else return false;
        }
        if (!st.empty()) return false;
        else return true;
    }
};
