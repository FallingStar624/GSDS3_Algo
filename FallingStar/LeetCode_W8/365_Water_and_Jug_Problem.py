class Solution:
    def gcd(self, x, y):
        c = x % y
        if c == 0:
            return y
        return self.gcd(y, c)

    def canMeasureWater(self, jug1Capacity: int, jug2Capacity: int, targetCapacity: int) -> bool:
        if jug1Capacity < jug2Capacity:
            j1, j2 = jug2Capacity, jug1Capacity
        else:
            j1, j2 = jug1Capacity, jug2Capacity
        t = targetCapacity
        if j1+j2 < t:
            return False
        if j1+j2 == t:
            return True
        if self.gcd(j1, j2) == 1:
            return True
        if t % self.gcd(j1, j2) == 0:
            return True
        return False
