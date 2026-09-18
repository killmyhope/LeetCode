// 541. Reverse String II [Easy] 
// https://leetcode.com/problems/reverse-string-ii/ 
// Accepted submission: 1997350772; language: cpp 
// Problem statement (HTML): 
// <p>Given a string <code>s</code> and an integer <code>k</code>, reverse the first <code>k</code> characters for every <code>2k</code> characters counting from the start of the string.</p> 
//  
// <p>If there are fewer than <code>k</code> characters left, reverse all of them. If there are less than <code>2k</code> but greater than or equal to <code>k</code> characters, then reverse the first <code>k</code> characters and leave the other as original.</p> 
//  
// <p>&nbsp;</p> 
// <p><strong class="example">Example 1:</strong></p> 
// <pre><strong>Input:</strong> s = "abcdefg", k = 2 
// <strong>Output:</strong> "bacdfeg" 
// </pre><p><strong class="example">Example 2:</strong></p> 
// <pre><strong>Input:</strong> s = "abcd", k = 2 
// <strong>Output:</strong> "bacd" 
// </pre> 
// <p>&nbsp;</p> 
// <p><strong>Constraints:</strong></p> 
//  
// <ul> 
// 	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li> 
// 	<li><code>s</code> consists of only lowercase English letters.</li> 
// 	<li><code>1 &lt;= k &lt;= 10<sup>4</sup></code></li> 
// </ul> 

class Solution
{
   public:
    string reverseStr(string s, int k)
    {
        int n = s.length();
        for (int i = 0; i < n; i += 2 * k)
        {
            int end = min(i + k, n);
            reverse(s.begin() + i, s.begin() + end);
        }
        return s;
    }
};
