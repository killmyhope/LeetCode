// 3886. Sum of Sortable Integers [Hard] 
// https://leetcode.com/problems/sum-of-sortable-integers/ 
// Accepted submission: 2177090487; language: cpp 
// Problem statement (HTML): 
// <p>You are given an integer array <code>nums</code> of length <code>n</code>.</p> 
//  
// <p>An integer <code>k</code> is called <strong>sortable</strong> if <code>k</code> <strong>divides</strong> <code>n</code> and you can sort <code>nums</code> in <strong>non-decreasing</strong> order by sequentially performing the following operations:</p> 
//  
// <ul> 
// 	<li>Partition <code>nums</code> into <strong>consecutive <span data-keyword="subarray-nonempty">subarrays</span></strong> of length <code>k</code>.</li> 
// 	<li><strong>Cyclically rotate each subarray independently</strong> any number of times to the left or to the right.</li> 
// </ul> 
//  
// <p>Return an integer denoting the sum of all possible sortable integers <code>k</code>.</p> 
//  
// <p>&nbsp;</p> 
// <p><strong class="example">Example 1:</strong></p> 
//  
// <div class="example-block"> 
// <p><strong>Input:</strong> <span class="example-io">nums = [3,1,2]</span></p> 
//  
// <p><strong>Output:</strong> <span class="example-io">3</span></p> 
//  
// <p><strong>Explanation:</strong>​​​​​​​</p> 
//  
// <ul> 
// 	<li>For <code>n = 3</code>, possible divisors are 1 and 3.</li> 
// 	<li>For <code>k = 1</code>: each subarray has one element. No rotation can sort the array.</li> 
// 	<li>For <code>k = 3</code>: the single subarray <code>[3, 1, 2]</code> can be rotated once to produce <code>[1, 2, 3]</code>, which is sorted.</li> 
// 	<li>Only <code>k = 3</code> is sortable. Hence, the answer is 3.</li> 
// </ul> 
// </div> 
//  
// <p><strong class="example">Example 2:</strong></p> 
//  
// <div class="example-block"> 
// <p><strong>Input:</strong> <span class="example-io">nums = [7,6,5]</span></p> 
//  
// <p><strong>Output:</strong> <span class="example-io">0</span></p> 
//  
// <p><strong>Explanation:</strong></p> 
//  
// <ul> 
// 	<li>For <code>n = 3</code>, possible divisors are 1 and 3.</li> 
// 	<li>For <code>k = 1</code>: each subarray has one element. No rotation can sort the array.</li> 
// 	<li>For <code>k = 3</code>: the single subarray <code>[7, 6, 5]</code> cannot be rotated into non-decreasing order.</li> 
// 	<li>No <code>k</code> is sortable. Hence, the answer is 0.</li> 
// </ul> 
// </div> 
//  
// <p><strong class="example">Example 3:</strong></p> 
//  
// <div class="example-block"> 
// <p><strong>Input:</strong> <span class="example-io">nums = [5,8]</span></p> 
//  
// <p><strong>Output:</strong> <span class="example-io">3</span></p> 
//  
// <p><strong>Explanation:</strong>​​​​​​​</p> 
//  
// <ul> 
// 	<li>For <code>n = 2</code>, possible divisors are 1 and 2.</li> 
// 	<li>Since <code>[5, 8]</code> is already sorted, every divisor is sortable. Hence, the answer is <code>1 + 2 = 3</code>.</li> 
// </ul> 
// </div> 
//  
// <p>&nbsp;</p> 
// <p><strong>Constraints:</strong></p> 
//  
// <ul> 
// 	<li><code>1 &lt;= n == nums.length &lt;= 10<sup>5</sup></code></li> 
// 	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li> 
// </ul> 

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> desc(n);  // desc[i]: number of descents nums[j] > nums[j + 1] with j < i
        for (int i = 1; i < n; i++) desc[i] = desc[i - 1] + (nums[i - 1] > nums[i]);
        vector<int> premax(n), sufmin(n);
        inclusive_scan(nums.begin(), nums.end(), premax.begin(), [](int a, int b) { return max(a, b); });  // premax[i]: max of nums[0..i]
        inclusive_scan(nums.rbegin(), nums.rend(), sufmin.rbegin(), [](int a, int b) { return min(a, b); });  // sufmin[i]: min of nums[i..n-1]
        vector<bool> cut(n, true);  // cut[m]: nums[0..m-1] holds exactly the m smallest values
        for (int m = 1; m < n; m++) cut[m] = premax[m - 1] <= sufmin[m];

        auto rotatable = [&](int l, int r) {  // nums[l..r] is a rotated sorted run: at most one cyclic descent
            return desc[r] - desc[l] + (nums[r] > nums[l]) <= 1;
        };
        auto sortable = [&](int k) {  // every block starts at a valid cut and can be rotated into order
            for (int l = 0; l < n; l += k)
                if (!cut[l] || !rotatable(l, l + k - 1)) return false;
            return true;
        };

        vector<int> divisors;
        for (int k = 1; k <= n; k++) if (n % k == 0) divisors.push_back(k);
        auto good = divisors | views::filter(sortable);
        return accumulate(good.begin(), good.end(), 0);
    }
};
