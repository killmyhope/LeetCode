// 415. Add Strings [Easy] 
// https://leetcode.com/problems/add-strings/ 
// Accepted submission: 1998207418; language: cpp 
// Problem statement (HTML): 
// <p>Given two non-negative integers, <code>num1</code> and <code>num2</code> represented as string, return <em>the sum of</em> <code>num1</code> <em>and</em> <code>num2</code> <em>as a string</em>.</p> 
//  
// <p>You must solve the problem without using any built-in library for handling large integers (such as <code>BigInteger</code>). You must also not convert the inputs to integers directly.</p> 
//  
// <p>&nbsp;</p> 
// <p><strong class="example">Example 1:</strong></p> 
//  
// <pre> 
// <strong>Input:</strong> num1 = &quot;11&quot;, num2 = &quot;123&quot; 
// <strong>Output:</strong> &quot;134&quot; 
// </pre> 
//  
// <p><strong class="example">Example 2:</strong></p> 
//  
// <pre> 
// <strong>Input:</strong> num1 = &quot;456&quot;, num2 = &quot;77&quot; 
// <strong>Output:</strong> &quot;533&quot; 
// </pre> 
//  
// <p><strong class="example">Example 3:</strong></p> 
//  
// <pre> 
// <strong>Input:</strong> num1 = &quot;0&quot;, num2 = &quot;0&quot; 
// <strong>Output:</strong> &quot;0&quot; 
// </pre> 
//  
// <p>&nbsp;</p> 
// <p><strong>Constraints:</strong></p> 
//  
// <ul> 
// 	<li><code>1 &lt;= num1.length, num2.length &lt;= 10<sup>4</sup></code></li> 
// 	<li><code>num1</code> and <code>num2</code> consist of only digits.</li> 
// 	<li><code>num1</code> and <code>num2</code> don&#39;t have any leading zeros except for the zero itself.</li> 
// </ul> 

class Solution
{
   public:
    string addStrings(string num1, string num2)
    {
        string res = "";
        int i = num1.length() - 1, j = num2.length() - 1, temp = 0;
        while (i + 1 || j + 1 || temp)
        {
            int d1 = (i + 1) ? num1[i--] - '0' : 0;
            int d2 = (j + 1) ? num2[j--] - '0' : 0;
            int sum = d1 + d2 + temp;
            res += '0' + sum % 10;
            temp = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
