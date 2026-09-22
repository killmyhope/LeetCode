// 3286. Find a Safe Walk Through a Grid [Medium] 
// https://leetcode.com/problems/find-a-safe-walk-through-a-grid/ 
// Accepted submission: 2054605206; language: cpp 
// Problem statement (HTML): 
// <p>You are given an <code>m x n</code> binary matrix <code>grid</code> and an integer <code>health</code>.</p> 
//  
// <p>You start on the upper-left corner <code>(0, 0)</code> and would like to get to the lower-right corner <code>(m - 1, n - 1)</code>.</p> 
//  
// <p>You can move up, down, left, or right from one cell to another adjacent cell as long as your health <em>remains</em> <strong>positive</strong>.</p> 
//  
// <p>Cells <code>(i, j)</code> with <code>grid[i][j] = 1</code> are considered <strong>unsafe</strong> and reduce your health by 1.</p> 
//  
// <p>Return <code>true</code> if you can reach the final cell with a health value of 1 or more, and <code>false</code> otherwise.</p> 
//  
// <p>&nbsp;</p> 
// <p><strong class="example">Example 1:</strong></p> 
//  
// <div class="example-block"> 
// <p><strong>Input:</strong> <span class="example-io">grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1</span></p> 
//  
// <p><strong>Output:</strong> <span class="example-io">true</span></p> 
//  
// <p><strong>Explanation:</strong></p> 
//  
// <p>The final cell can be reached safely by walking along the gray cells below.</p> 
// <img alt="" src="https://assets.leetcode.com/uploads/2024/08/04/3868_examples_1drawio.png" style="width: 301px; height: 121px;" /></div> 
//  
// <p><strong class="example">Example 2:</strong></p> 
//  
// <div class="example-block"> 
// <p><strong>Input:</strong> <span class="example-io">grid = [[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]], health = 3</span></p> 
//  
// <p><strong>Output:</strong> <span class="example-io">false</span></p> 
//  
// <p><strong>Explanation:</strong></p> 
//  
// <p>A minimum of 4 health points is needed to reach the final cell safely.</p> 
// <img alt="" src="https://assets.leetcode.com/uploads/2024/08/04/3868_examples_2drawio.png" style="width: 361px; height: 161px;" /></div> 
//  
// <p><strong class="example">Example 3:</strong></p> 
//  
// <div class="example-block"> 
// <p><strong>Input:</strong> <span class="example-io">grid = [[1,1,1],[1,0,1],[1,1,1]], health = 5</span></p> 
//  
// <p><strong>Output:</strong> <span class="example-io">true</span></p> 
//  
// <p><strong>Explanation:</strong></p> 
//  
// <p>The final cell can be reached safely by walking along the gray cells below.</p> 
//  
// <p><img alt="" src="https://assets.leetcode.com/uploads/2024/08/04/3868_examples_3drawio.png" style="width: 181px; height: 121px;" /></p> 
//  
// <p>Any path that does not go through the cell <code>(1, 1)</code> is unsafe since your health will drop to 0 when reaching the final cell.</p> 
// </div> 
//  
// <p>&nbsp;</p> 
// <p><strong>Constraints:</strong></p> 
//  
// <ul> 
// 	<li><code>m == grid.length</code></li> 
// 	<li><code>n == grid[i].length</code></li> 
// 	<li><code>1 &lt;= m, n &lt;= 50</code></li> 
// 	<li><code><font face="monospace">2 &lt;= m * n</font></code></li> 
// 	<li><code>1 &lt;= health &lt;= m + n</code></li> 
// 	<li><code>grid[i][j]</code> is either 0 or 1.</li> 
// </ul> 

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int hp) 
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> md(n,vector<int> (m,1e9));
        deque<pair<int,int>> dq;

        md[0][0]= grid[0][0];
        dq.push_back({0,0});

        int dr[]={1,-1,0,0}, dc[]= {0,0,1,-1};
        while(!dq.empty())
        {
            auto[r,c]= dq.front();
            dq.pop_front();

            if (r == n-1&& c == m-1) return (hp-md[r][c])>0;
            
            for (int i =0;i<4;i++)
            {
                int nr = r+dr[i],nc= c+dc[i];
                
                if(nr>-1 &&nr<n && nc >-1 && nc<m)
                {
                    int w = grid[nr][nc];
                    if (md[r][c]+w<md[nr][nc])
                    {
                        md[nr][nc]= md[r][c]+w;

                        if(w==0) dq.push_front({nr,nc});
                        else dq.push_back({nr,nc});
                    }
                }
            }
        }   
        return (hp - md[n-1][m-1])>0;
            }
};
