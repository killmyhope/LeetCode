// 2916. Subarrays Distinct Element Sum of Squares II [Hard] 
// https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/ 
// Accepted submission: 2173813223; language: cpp 
// Problem statement (HTML): 
// <p>You are given a <strong>0-indexed </strong>integer array <code>nums</code>.</p> 
//  
// <p>The <strong>distinct count</strong> of a subarray of <code>nums</code> is defined as:</p> 
//  
// <ul> 
// 	<li>Let <code>nums[i..j]</code> be a subarray of <code>nums</code> consisting of all the indices from <code>i</code> to <code>j</code> such that <code>0 &lt;= i &lt;= j &lt; nums.length</code>. Then the number of distinct values in <code>nums[i..j]</code> is called the distinct count of <code>nums[i..j]</code>.</li> 
// </ul> 
//  
// <p>Return <em>the sum of the <strong>squares</strong> of <strong>distinct counts</strong> of all subarrays of </em><code>nums</code>.</p> 
//  
// <p>Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p> 
//  
// <p>A subarray is a contiguous <strong>non-empty</strong> sequence of elements within an array.</p> 
//  
// <p>&nbsp;</p> 
// <p><strong>Example 1:</strong></p> 
//  
// <pre> 
// <strong>Input:</strong> nums = [1,2,1] 
// <strong>Output:</strong> 15 
// <strong>Explanation:</strong> Six possible subarrays are: 
// [1]: 1 distinct value 
// [2]: 1 distinct value 
// [1]: 1 distinct value 
// [1,2]: 2 distinct values 
// [2,1]: 2 distinct values 
// [1,2,1]: 2 distinct values 
// The sum of the squares of the distinct counts in all subarrays is equal to 1<sup>2</sup> + 1<sup>2</sup> + 1<sup>2</sup> + 2<sup>2</sup> + 2<sup>2</sup> + 2<sup>2</sup> = 15. 
// </pre> 
//  
// <p><strong>Example 2:</strong></p> 
//  
// <pre> 
// <strong>Input:</strong> nums = [2,2] 
// <strong>Output:</strong> 3 
// <strong>Explanation:</strong> Three possible subarrays are: 
// [2]: 1 distinct value 
// [2]: 1 distinct value 
// [2,2]: 1 distinct value 
// The sum of the squares of the distinct counts in all subarrays is equal to 1<sup>2</sup> + 1<sup>2</sup> + 1<sup>2</sup> = 3.</pre> 
//  
// <p>&nbsp;</p> 
// <p><strong>Constraints:</strong></p> 
//  
// <ul> 
// 	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li> 
// 	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li> 
// </ul> 

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> cnt(n + 1), tot(n + 1);  // Fenwick trees over previous-copy positions, stored right to left
        unordered_map<int, int> last;
        long long ans = 0;
        for (int r = 0; r < n; r++) {
            int p = last.count(nums[r]) ? last[nums[r]] : -1;
            long long c = 0, s = 0;
            for (int i = n - p - 1; i > 0; i -= i & -i)  // boxes 1..n-p-1 hold the positions > p
                c += cnt[i], s += tot[i];
            long long gain = (long long)(r - p) * (r - p) - 2 * (s - p * c);  // at most 1e10
            ans = (ans + (n - r) * gain) % MOD;
            for (int i = n - p; i <= n; i += i & -i)  // insert p; p = -1 lands past the end and is skipped
                cnt[i]++, tot[i] += p;
            last[nums[r]] = r;
        }
        return ans;
    }
};
