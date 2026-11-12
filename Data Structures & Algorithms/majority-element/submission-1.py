class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # lowki can just build a dictionary and then whatever has thehighest value then return that key

        # seen = {}

        # for num in nums:
        #     seen[num] = seen.get(num, 0) + 1
        
        # return max(seen, key=seen.get)

        # but this is O(n) time and O(n) space

        # so we can use the boyer moore solution whre its O(n) time but O(1) space complexity
        # this means that the first element is the first candidate and u make that count 1, but if the next candidate is the opposite or the same the u add one or minus one, and when count hits 0 then thats when u make the candidate a new canddiate
        
        candidate = None
        count = 0

        for num in nums:
            if count == 0:
                candidate = num
            count+= 1 if candidate == num else -1

        return candidate
