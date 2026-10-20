# 199. Binary Tree Right Side View

Difficulty: Medium
LeetCode URL: https://leetcode.com/problems/binary-tree-right-side-view/submissions/2176966340/

## Problem

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 
Example 1:


Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]

Explanation:




Example 2:


Input: root = [1,2,3,4,null,null,null,5]

Output: [1,3,4,5]

Explanation:




Example 3:


Input: root = [1,null,3]

Output: [1,3]


Example 4:


Input: root = []

Output: []


 
Constraints:


	The number of nodes in the tree is in the range [0, 100].
	-100 <= Node.val <= 100

## Methods

### 1. BFS

File:
`bfs.cpp`

Language: cpp
Status: Accepted
Runtime: 0 ms
Memory: 15.5 MB

Notes:
Using LevelOrder

### 2. DFS

File:
`dfs.cpp`

Language: cpp
Status: Accepted
Runtime: 0 ms
Memory: 14.8 MB

Notes:
Using Reverse PreOrder
