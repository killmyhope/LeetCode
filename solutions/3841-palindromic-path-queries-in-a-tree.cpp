// 3841. Palindromic Path Queries in a Tree [Hard] 
// https://leetcode.com/problems/palindromic-path-queries-in-a-tree/ 
// Accepted submission: 2184688084; language: cpp 
// Problem statement (HTML): 
// <p>You are given an undirected tree with <code>n</code> nodes labeled 0 to <code>n - 1</code>. This is represented by a 2D array <code>edges</code> of length <code>n - 1</code>, where <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code> indicates an undirected edge between nodes <code>u<sub>i</sub></code> and <code>v<sub>i</sub></code>.</p> 
//  
// <p>You are also given a string <code>s</code> of length <code>n</code> consisting of lowercase English letters, where <code>s[i]</code> represents the character assigned to node <code>i</code>.</p> 
//  
// <p>You are also given a string array <code>queries</code>, where each <code>queries[i]</code> is either:</p> 
//  
// <ul> 
// 	<li><code>&quot;update u<sub>i</sub> c&quot;</code>: Change the character at node <code>u<sub>i</sub></code> to <code>c</code>. Formally, update <code>s[u<sub>i</sub>] = c</code>.</li> 
// 	<li><code>&quot;query u<sub>i</sub> v<sub>i</sub>&quot;</code>: Determine whether the string formed by the characters on the <strong>unique</strong> path from <code>u<sub>i</sub></code> to <code>v<sub>i</sub></code> (inclusive) can be <strong>rearranged</strong> into a <strong><span data-keyword="palindrome-string">palindrome</span></strong>.</li> 
// </ul> 
//  
// <p>Return a boolean array <code>answer</code>, where <code>answer[j]</code> is <code>true</code> if the <code>j<sup>th</sup></code> query of type <code>&quot;query u<sub>i</sub> v<sub>i</sub>&quot;​​​​​​​</code> can be rearranged into a <strong>palindrome</strong>, and <code>false</code> otherwise.</p> 
//  
// <p>&nbsp;</p> 
// <p><strong class="example">Example 1:</strong></p> 
//  
// <div class="example-block"> 
// <p><strong>Input:</strong> <span class="example-io">n = 3, edges = [[0,1],[1,2]], s = &quot;aac&quot;, queries = [&quot;query 0 2&quot;,&quot;update 1 b&quot;,&quot;query 0 2&quot;]</span></p> 
//  
// <p><strong>Output:</strong> <span class="example-io">[true,false]</span></p> 
//  
// <p><strong>Explanation:</strong></p> 
//  
// <ul> 
// 	<li><code>&quot;query 0 2&quot;</code>: Path <code>0 &rarr; 1 &rarr; 2</code> gives <code>&quot;aac&quot;</code>, which can be rearranged to form <code>&quot;aca&quot;</code>, a palindrome. Thus, <code>answer[0] = true</code>.</li> 
// 	<li><code>&quot;update 1 b&quot;</code>: Update node 1 to <code>&#39;b&#39;</code>, now <code>s = &quot;abc&quot;</code>.</li> 
// 	<li><code>&quot;query 0 2&quot;</code>: Path characters are <code>&quot;abc&quot;</code>, which cannot be rearranged to form a palindrome. Thus, <code>answer[1] = false</code>.</li> 
// </ul> 
//  
// <p>Thus, <code>answer = [true, false]</code>.</p> 
// </div> 
//  
// <p><strong class="example">Example 2:</strong></p> 
//  
// <div class="example-block"> 
// <p><strong>Input:</strong> <span class="example-io">n = 4, edges = [[0,1],[0,2],[0,3]], s = &quot;abca&quot;, queries = [&quot;query 1 2&quot;,&quot;update 0 b&quot;,&quot;query 2 3&quot;,&quot;update 3 a&quot;,&quot;query 1 3&quot;]</span></p> 
//  
// <p><strong>Output:</strong> <span class="example-io">[false,false,true]</span></p> 
//  
// <p><strong>Explanation:</strong></p> 
//  
// <ul> 
// 	<li><code>&quot;query 1 2&quot;</code>: Path <code>1 &rarr; 0 &rarr; 2</code> gives <code>&quot;bac&quot;</code>, which cannot be rearranged to form a palindrome. Thus, <code>answer[0] = false</code>.</li> 
// 	<li><code>&quot;update 0 b&quot;</code>: Update node 0 to <code>&#39;b&#39;</code>, now <code>s = &quot;bbca&quot;</code>.</li> 
// 	<li><code>&quot;query 2 3&quot;</code>: Path <code>2 &rarr; 0 &rarr; 3</code> gives <code>&quot;cba&quot;</code>, which cannot be rearranged to form a palindrome. Thus, <code>answer[1] = false</code>.</li> 
// 	<li><code>&quot;update 3 a&quot;</code>: Update node 3 to <code>&#39;a&#39;</code>, <code>s = &quot;bbca&quot;</code>.</li> 
// 	<li><code>&quot;query 1 3&quot;</code>: Path <code>1 &rarr; 0 &rarr; 3</code> gives <code>&quot;bba&quot;</code>, which can be rearranged to form <code>&quot;bab&quot;</code>, a palindrome. Thus, <code>answer[2] = true</code>.</li> 
// </ul> 
//  
// <p>Thus, <code>answer = [false, false, true]</code>.</p> 
// </div> 
//  
// <p>&nbsp;</p> 
// <p><strong>Constraints:</strong></p> 
//  
// <ul> 
// 	<li><code>1 &lt;= n == s.length &lt;= 5 * 10<sup>4</sup></code></li> 
// 	<li><code>edges.length == n - 1</code></li> 
// 	<li><code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code></li> 
// 	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n - 1</code></li> 
// 	<li><code>s</code> consists of lowercase English letters.</li> 
// 	<li>The input is generated such that <code>edges</code> represents a valid tree.</li> 
// 	<li><code>1 &lt;= queries.length &lt;= 5 * 10<sup>4</sup></code>​​​​​​​ 
// 	<ul> 
// 		<li><code>queries[i] = &quot;update u<sub>i</sub> c&quot;</code> or</li> 
// 		<li><code>queries[i] = &quot;query u<sub>i</sub> v<sub>i</sub>&quot;</code></li> 
// 		<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n - 1</code></li> 
// 		<li><code>c</code> is a lowercase English letter.</li> 
// 	</ul> 
// 	</li> 
// </ul> 

struct Tree {  // Euler tour: the subtree of x is tin[x] .. tout[x] - 1; LCA by a sparse table over the DFS order
    vector<int> parent, tin, tout, order;  // the root is its own parent; order: the nodes in DFS order
    vector<vector<int>> first;  // first[k][i]: the earliest parent among order[i .. i + 2^k - 1]

    Tree(int n, vector<vector<int>>& edges) : parent(n), tin(n), tout(n) {
        vector<int> head(n + 1), adj(2 * n);  // the neighbors of x are adj[head[x] .. head[x + 1] - 1]
        for (auto& e : edges) head[e[0] + 1]++, head[e[1] + 1]++;
        partial_sum(head.begin(), head.end(), head.begin());
        vector<int> pos(head.begin(), head.end() - 1);
        for (auto& e : edges) adj[pos[e[0]]++] = e[1], adj[pos[e[1]]++] = e[0];

        vector<int> stack = {0};
        while (!stack.empty()) {  // DFS without recursion; ~x marks the moment x's subtree is done
            int x = stack.back();
            stack.pop_back();
            if (x < 0) {
                tout[~x] = order.size();
                continue;
            }
            tin[x] = order.size();
            order.push_back(x);
            stack.push_back(~x);
            for (int i = head[x]; i < head[x + 1]; i++)
                if (int y = adj[i]; y != parent[x]) {
                    parent[y] = x;
                    stack.push_back(y);
                }
        }

        first.emplace_back(n);
        for (int i = 0; i < n; i++) first[0][i] = tin[parent[order[i]]];
        for (int k = 1; 1 << k <= n; k++) {
            first.emplace_back(n - (1 << k) + 1);
            for (int i = 0; i + (1 << k) <= n; i++) first[k][i] = min(first[k - 1][i], first[k - 1][i + (1 << (k - 1))]);
        }
    }

    int lca(int u, int v) {  // the parent that comes first in DFS order among the nodes after u up to v
        if (u == v) return u;
        auto [l, r] = minmax(tin[u], tin[v]);
        int k = bit_width(unsigned(r - l)) - 1;
        return order[min(first[k][l + 1], first[k][r - (1 << k) + 1])];
    }
};

struct RootPaths {  // paths[x]: XOR of the letter bits from the root down to x
    Tree& tree;
    vector<int> start, fenwick;  // the masks for the initial letters, and a Fenwick tree over the Euler tour with the changes since the start

    RootPaths(Tree& tree, vector<int>& bit) : tree(tree), start(bit), fenwick(bit.size() + 1) {
        for (int x : tree.order)  // a parent comes before its children in DFS order
            if (x != tree.parent[x]) start[x] ^= start[tree.parent[x]];
    }

    void flip(int x, int d) {  // XOR d into the root path of every node in x's subtree
        for (int i : {tree.tin[x] + 1, tree.tout[x] + 1})  // d starts at x's subtree and cancels out after it
            for (; i < (int)fenwick.size(); i += i & -i) fenwick[i] ^= d;
    }

    int operator[](int x) {
        int mask = start[x];
        for (int i = tree.tin[x] + 1; i > 0; i -= i & -i) mask ^= fenwick[i];
        return mask;
    }
};

class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        Tree tree(n, edges);
        vector<int> bit(n);  // bit[x]: the bit of x's letter
        for (int x = 0; x < n; x++) bit[x] = 1 << (s[x] - 'a');
        RootPaths paths(tree, bit);

        vector<bool> ans;
        for (auto& q : queries) {
            if (q[0] == 'u') {  // "update x c"
                int x = number(q, 7), newBit = 1 << (q.back() - 'a');
                paths.flip(x, bit[x] ^ newBit);  // the new letter changes the root path of every node in x's subtree
                bit[x] = newBit;
            } else {  // "query u v"
                int u = number(q, 6), v = number(q, q.rfind(' ') + 1);
                int mask = paths[u] ^ paths[v] ^ bit[tree.lca(u, v)];  // the LCA cancels out in paths[u] ^ paths[v], so add it back
                ans.push_back(popcount(unsigned(mask)) <= 1);  // at most one letter is odd
            }
        }
        return ans;
    }

private:
    static int number(const string& q, int i) {  // the number that starts at q[i]
        int x = 0;
        for (; i < (int)q.size() && isdigit(q[i]); i++) x = x * 10 + (q[i] - '0');
        return x;
    }
};
