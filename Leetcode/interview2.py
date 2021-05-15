class Solution(object):
    def maxDistToClosest(self, seats):
        """
        :type seats: List[int]
        :rtype: int
        """
        ans = 0
        n_seats = len(seats)
        occupied = []
        n_occupied = 0
        for i in range(n_seats):
            if seats[i] == 1:
                occupied.append(i)
                n_occupied += 1
        distances = [s - t - 1 for t, s in zip(occupied, occupied[1:])]
        if n_occupied > 1:
            ans = max(distances)
            ans = int(ans // 2) + int(ans & 1)
        if seats[0] == 0:
            ans = max(ans, occupied[0])
        if seats[n_seats - 1] == 0:
            ans = max(ans, n_seats - occupied[n_occupied - 1] - 1)
        return ans

"""
You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to the closest person.

Input: seats = [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.

Success

"""
