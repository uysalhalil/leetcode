from typing import List


class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        res = []
        for asteroid in asteroids:
            res.append(asteroid)
            while len(res) > 1 and res[-2] > 0 and res[-1] * res[-2] < 0:
                val1 = res.pop()
                val2 = res.pop()
                if abs(val1) > abs(val2):
                    res.append(val1)
                elif abs(val1) < abs(val2):
                    res.append(val2)

        return res