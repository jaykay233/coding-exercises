from ast import List
from collections import Counter
from itertools import combinations
class Solution:
    def coopDevelop(self, skills: List[List[int]]) -> int:
        cnt = Counter()
        ans = 0
        skills.sort(key=lambda x:len(x))
        for i, skill in enumerate(skills):
            skill.sort()
            for j in range(len(skill)):
                for c in combinations(skill,j+1):
                    i -= cnt[tuple(c)]
            cnt[tuple(skill)] += 1
            ans = (ans + i) % 1_000_000_007
        return ans