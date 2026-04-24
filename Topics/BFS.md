| Problem | Rating | Solution Idea | Implementation |
|--------|---------|---------------------|------|
| [2018C](https://codeforces.com/contest/2018/problem/C) | 1700 | <details><summary>Show</summary><ul><li>For every node we store its depth, the number of nodes below it and its parent.</li><li>Our answer basically depends on just one condition, At any depth `d` would removing the subtrees having depth < `d` be a better choice than removing subtrees with depth > `d` or not.</li><li>We just keep comparing this condition repeatedly and stop at the minimum number of leaves required to be removed according to this.</li></ul></details> | [Code](../Codes/2018C.cpp) |

