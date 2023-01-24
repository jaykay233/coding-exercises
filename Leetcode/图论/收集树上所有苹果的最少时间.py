class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        graph = collections.defaultdict(set)
        for u,v in edges:
            graph[u].add(v)
            graph[v].add(u)
        
        visited = set()
        def dfs(root):
            visited.add(root)
            for nex in graph[root]:
                if nex in visited:
                    continue
                dfs(nex)
                if hasApple[nex]:
                    hasApple[root] = True
        
        dfs(0)
        res = 0
        for u,v in edges:
            if hasApple[u] and hasApple[v]:
                res += 1
        return res * 2