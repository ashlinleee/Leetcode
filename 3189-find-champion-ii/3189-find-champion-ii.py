class Solution(object):
    def findChampion(self, n, edges):
        in_degree = [0] * n
        for u, v in edges:
            in_degree[v] += 1
        candidates = [i for i in range(n) if in_degree[i] == 0]
        if len(candidates) == 1:
            return candidates[0]
        return -1
        