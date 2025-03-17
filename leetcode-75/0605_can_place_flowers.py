from typing import List


class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        # greedy
        for i in range(len(flowerbed)):
            if flowerbed[i] == 0:
                if (i == 0) and (i + 1 == len(flowerbed) or flowerbed[i + 1] == 0):
                    flowerbed[i] = 1
                    n = max(n - 1, 0)
                elif (i == len(flowerbed) - 1) and flowerbed[i - 1] == 0:
                    flowerbed[i] = 1
                    n = max(n - 1, 0)
                elif flowerbed[i - 1] == 0 and flowerbed[i + 1] == 0:
                    flowerbed[i] = 1
                    n = max(n - 1, 0)

        return n == 0