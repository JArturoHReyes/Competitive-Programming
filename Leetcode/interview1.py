class Solution(object):
    def rotatedDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        invalid = ['3', '4', '7']
        valid = ['2', '5', '6', '9']
        ans = 0
        for number in range(1, n + 1):
            str_number = str(number)
            has_invalid = False
            for actual_invalid in invalid:
                if actual_invalid in str_number:
                    has_invalid = True
                    break
            has_valid = False
            for actual_valid in valid:
                if actual_valid in str_number:
                    has_valid = True
                    break
            if (not has_invalid) and (has_valid):
                ans += 1
        return ans
        
"""

x is a good number if after rotating each digit individually by 180 degrees, we get a valid number that is different from x. Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other (on this case they are rotated in a different direction, in other words 2 or 5 gets mirrored); 6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.

Now given a positive number n, how many numbers x from 1 to n are good?

Example:
Input: 10
Output: 4
Explanation: 
There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.

n will be in range [1, 10000].

Success

"""
