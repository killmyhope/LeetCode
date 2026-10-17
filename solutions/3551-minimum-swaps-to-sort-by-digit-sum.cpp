// 3551. Minimum Swaps to Sort by Digit Sum [Medium] 
// https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/ 
// Accepted submission: 2174819991; language: cpp 
// Problem statement (HTML): 
// <p>You are given an array <code>nums</code> of <strong>distinct</strong> positive integers. You need to sort the array in <strong>increasing</strong> order based on the sum of the digits of each number. If two numbers have the same digit sum, the <strong>smaller</strong> number appears first in the sorted order.</p> 
//  
// <p>Return the <strong>minimum</strong> number of swaps required to rearrange <code>nums</code> into this sorted order.</p> 
//  
// <p>A <strong>swap</strong> is defined as exchanging the values at two distinct positions in the array.</p> 
//  
// <p>&nbsp;</p> 
// <p><strong class="example">Example 1:</strong></p> 
//  
// <div class="example-block"> 
// <p><strong>Input:</strong> <span class="example-io">nums = [37,100]</span></p> 
//  
// <p><strong>Output:</strong> <span class="example-io">1</span></p> 
//  
// <p><strong>Explanation:</strong></p> 
//  
// <ul> 
// 	<li>Compute the digit sum for each integer: <code>[3 + 7 = 10, 1 + 0 + 0 = 1] &rarr; [10, 1]</code></li> 
// 	<li>Sort the integers based on digit sum: <code>[100, 37]</code>. Swap <code>37</code> with <code>100</code> to obtain the sorted order.</li> 
// 	<li>Thus, the minimum number of swaps required to rearrange <code>nums</code> is 1.</li> 
// </ul> 
// </div> 
//  
// <p><strong class="example">Example 2:</strong></p> 
//  
// <div class="example-block"> 
// <p><strong>Input:</strong> <span class="example-io">nums = [22,14,33,7]</span></p> 
//  
// <p><strong>Output:</strong> <span class="example-io">0</span></p> 
//  
// <p><strong>Explanation:</strong></p> 
//  
// <ul> 
// 	<li>Compute the digit sum for each integer: <code>[2 + 2 = 4, 1 + 4 = 5, 3 + 3 = 6, 7 = 7] &rarr; [4, 5, 6, 7]</code></li> 
// 	<li>Sort the integers based on digit sum: <code>[22, 14, 33, 7]</code>. The array is already sorted.</li> 
// 	<li>Thus, the minimum number of swaps required to rearrange <code>nums</code> is 0.</li> 
// </ul> 
// </div> 
//  
// <p><strong class="example">Example 3:</strong></p> 
//  
// <div class="example-block"> 
// <p><strong>Input:</strong> <span class="example-io">nums = [18,43,34,16]</span></p> 
//  
// <p><strong>Output:</strong> <span class="example-io">2</span></p> 
//  
// <p><strong>Explanation:</strong></p> 
//  
// <ul> 
// 	<li>Compute the digit sum for each integer: <code>[1 + 8 = 9, 4 + 3 = 7, 3 + 4 = 7, 1 + 6 = 7] &rarr; [9, 7, 7, 7]</code></li> 
// 	<li>Sort the integers based on digit sum: <code>[16, 34, 43, 18]</code>. Swap <code>18</code> with <code>16</code>, and swap <code>43</code> with <code>34</code> to obtain the sorted order.</li> 
// 	<li>Thus, the minimum number of swaps required to rearrange <code>nums</code> is 2.</li> 
// </ul> 
// </div> 
//  
// <p>&nbsp;</p> 
// <p><strong>Constraints:</strong></p> 
//  
// <ul> 
// 	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li> 
// 	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li> 
// 	<li><code>nums</code> consists of <strong>distinct</strong> positive integers.</li> 
// </ul> 

class Solution {
    int susm(int n)
    {   
        int sum=0;
        while(n)
        {
            sum+=n%10;
            n/=10;
        }
        return sum;
    }

    void helper(vector<int> &nums,vector<pair<int,int>> &temp)
    {
        for (int i=0;i<nums.size();i++)
        {
            int sum = susm(nums[i]);
            temp.push_back({sum,nums[i]});
        }
    }

public:
    int minSwaps(vector<int>& nums) 
    {
        vector<pair<int,int>> temp;
        helper(nums,temp);
        sort(temp.begin(),temp.end(),[](pair<int,int> &a, pair<int,int> b){return(a.first!=b.first)? a.first<b.first : a.second<b.second;});
        vector<int> a;
        for (int i=0;i<temp.size();i++)
        a.push_back(temp[i].second);

         int n=nums.size();
    unordered_map<int,int>mp2;
    for( int i=0;i<n;i++){
        mp2[a[i]]=i;
    }
    unordered_map<int,int>mp;
      for(int i=0;i<n;i++){
          mp[i]=mp2[nums[i]];
      }
    vector<bool>visited(n,false);
    int cnt=0;
    for (int i=0;i<n;i++){
        if(visited[i] || mp[i]==i) continue;
        int cycle_size=0;
        int j=i;
        while(!visited[j]){
            visited[j]=true;
            j=mp[j];
            cycle_size++;
        }
        if(cycle_size>1){
            cnt+=(cycle_size-1);
        }
    }
    return cnt;

    }
};
