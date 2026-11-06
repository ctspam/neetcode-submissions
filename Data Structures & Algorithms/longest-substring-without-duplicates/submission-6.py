class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # counts = {}
        # left,best = 0,0
        # for right in range(len(s)):
        #     ch = s[right]
        #     counts[ch] = counts.get(ch, 0)+1
        #     #oly ch can be over 1, so shrink from the left unitil its back to 1
        #     while counts[ch] > 1:
        #         # remove the leftmost letter
        #         counts[s[left]]-=1
        #         # move the left edge right
        #         left +=1
        #     # the window s[left::right+1] has no repeats here
        #     # updates every step, not only on a repepat
        #     best = max(best, right-left+1)

        # return best

        # ALSO cna use a set
        seen = set()
        left,best = 0,0
        for right in range(len(s)):
            while s[right] in seen:
                seen.remove(s[left])
                left+=1
            seen.add(s[right])
            best = max(best, right-left+1)

        return best