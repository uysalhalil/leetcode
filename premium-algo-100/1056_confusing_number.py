from typing import List


class Solution:
    def confusingNumber(self, n: int) -> bool:
        confusingDigits = {0: 0, 1: 1, 6: 9, 8: 8, 9: 6}
        
        def isDigitsConfusing(confusingDigits: set, digits: List[int], n: int) -> bool:
            while n > 0:
                d = n % 10
                if d not in confusingDigits:
                    return False
                digits.append(confusingDigits[d])
                n //= 10
            return True
        
        def convert2num(digits: List[int]) -> int:
            n = 0
            for d in digits:
                n = (n * 10) + d

            return n
           
        digits = []
        if isDigitsConfusing(confusingDigits, digits, n):
            isConfusing = convert2num(digits) != n
            return isConfusing

        return False