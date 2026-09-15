// 387. First Unique Character in a String [Easy] 
// https://leetcode.com/problems/first-unique-character-in-a-string/ 
// Accepted submission: 1995838725; language: cpp 
// Problem statement (HTML): 
// <p>Given a string <code>s</code>, find the <strong>first</strong> non-repeating character in it and return its index. If it <strong>does not</strong> exist, return <code>-1</code>.</p> 
//  
// <p>&nbsp;</p> 
// <p><strong class="example">Example 1:</strong></p> 
//  
// <div class="example-block"> 
// <p><strong>Input:</strong> <span class="example-io">s = &quot;leetcode&quot;</span></p> 
//  
// <p><strong>Output:</strong> <span class="example-io">0</span></p> 
//  
// <p><strong>Explanation:</strong></p> 
//  
// <p>The character <code>&#39;l&#39;</code> at index 0 is the first character that does not occur at any other index.</p> 
// </div> 
//  
// <p><strong class="example">Example 2:</strong></p> 
//  
// <div class="example-block"> 
// <p><strong>Input:</strong> <span class="example-io">s = &quot;loveleetcode&quot;</span></p> 
//  
// <p><strong>Output:</strong> <span class="example-io">2</span></p> 
// </div> 
//  
// <p><strong class="example">Example 3:</strong></p> 
//  
// <div class="example-block"> 
// <p><strong>Input:</strong> <span class="example-io">s = &quot;aabb&quot;</span></p> 
//  
// <p><strong>Output:</strong> <span class="example-io">-1</span></p> 
// </div> 
//  
// <p>&nbsp;</p> 
// <p><strong>Constraints:</strong></p> 
//  
// <ul> 
// 	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li> 
// 	<li><code>s</code> consists of only lowercase English letters.</li> 
// </ul> 

class Solution 
{
public:
    int firstUniqChar(string s)
     {
        int b[26] = {0};
        for (char c : s) b[c - 'a']++;
        for (int i; i < s.length(); i++) 
        {
            if (b[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
