// 56. Merge Intervals [Medium] 
// https://leetcode.com/problems/merge-intervals/ 
// Accepted submission: 2046204261; language: cpp 
// Problem statement (HTML): 
// <p>Given an array&nbsp;of <code>intervals</code>&nbsp;where <code>intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]</code>, merge all overlapping intervals, and return <em>an array of the non-overlapping intervals that cover all the intervals in the input</em>.</p> 
//  
// <p>&nbsp;</p> 
// <p><strong class="example">Example 1:</strong></p> 
//  
// <pre> 
// <strong>Input:</strong> intervals = [[1,3],[2,6],[8,10],[15,18]] 
// <strong>Output:</strong> [[1,6],[8,10],[15,18]] 
// <strong>Explanation:</strong> Since intervals [1,3] and [2,6] overlap, merge them into [1,6]. 
// </pre> 
//  
// <p><strong class="example">Example 2:</strong></p> 
//  
// <pre> 
// <strong>Input:</strong> intervals = [[1,4],[4,5]] 
// <strong>Output:</strong> [[1,5]] 
// <strong>Explanation:</strong> Intervals [1,4] and [4,5] are considered overlapping. 
// </pre> 
//  
// <p><strong class="example">Example 3:</strong></p> 
//  
// <pre> 
// <strong>Input:</strong> intervals = [[4,7],[1,4]] 
// <strong>Output:</strong> [[1,7]] 
// <strong>Explanation:</strong> Intervals [1,4] and [4,7] are considered overlapping. 
// </pre> 
//  
// <p>&nbsp;</p> 
// <p><strong>Constraints:</strong></p> 
//  
// <ul> 
// 	<li><code>1 &lt;= intervals.length &lt;= 10<sup>4</sup></code></li> 
// 	<li><code>intervals[i].length == 2</code></li> 
// 	<li><code>0 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt;= 10<sup>4</sup></code></li> 
// </ul> 

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        for(auto interval : intervals)
        {
            if(output.empty() || output.back()[1] < interval[0]) output.push_back(interval);
            else output.back()[1] = max(output.back()[1], interval[1]);
        }
        return output;    
    }
};
