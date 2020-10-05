class Solution:
    def rotatedDigits(self, N: int) -> int:
        d = [0, 0, 1, -1, -1, 1, 1, -1, 0, 1] + [0] * (N - 9)
        for i in range(N + 1):
            if d[i // 10] == -1 or d[i % 10] == -1:
                d[i] = -1
            elif d[i // 10] == 1 or d[i % 10] == 1:
                d[i] = 1
        return d[:N+1].count(1)