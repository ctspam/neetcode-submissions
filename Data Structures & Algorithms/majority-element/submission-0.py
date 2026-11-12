class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # lowki can just build a dictionary and then whatever has thehighest value then return that key

        seen = {}

        for num in nums:
            seen[num] = seen.get(num, 0) + 1
        
        return max(seen, key=seen.get)