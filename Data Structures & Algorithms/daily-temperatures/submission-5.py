class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        # so im guessing the brute force to this is running thbe list every single time its there so to have 2 for loops and then keep track ofwhich index is the greater than that if not then append 0 to the result

        # result = []

        # for i in range(len(temperatures)):
        #     index = 0 
        #     for j in range(i+1, len(temperatures)):
        #         if temperatures[j] > temperatures[i]:
        #             index = j-i
        #             break
        #     result.append(index)
        # return result

    # this is the brute force solution with O(n^2) of tC but O(1) complexity

    # a better way to solve this is using a monotonic stack
        n = len(temperatures)
        # lets make a list of all static array of the lenght of temps oto replace like all the values of the index of dyas that are warmr
        result = [0] *n
        stack = []
        # im going right to left where the last day down to day 0
        for i in range(n-1, -1, -1):
            #then i remove days that aren't warmer than today
            # <= because it must be strictly warmer

            while stack and temperatures[stack[-1]] <= temperatures[i]:
                stack.pop()

            # if anything is left, the top is the nearest warmer day
            if stack:
                result[i] = stack[-1]-i
            # today could be the warmer day for an earlierday
            stack.append(i)
        return result


""" or u can do the backwards version since this is TC of O(n+m) and space of O(n+m)
Read both strings from the end.
Every time you pass a #, add 1 to a counter. The counter tells you how many of the next letters to ignore.
When you reach a letter and the counter is above 0, ignore that letter and subtract 1.
When you reach a letter and the counter is 0, that letter is part of the final text. Compare it to the next such letter from the other string.
If two letters don’t match, or one string runs out of letters before the other, return False. If they match all the way and run out together, return True.


"""

"""
class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:

        def next_valid(string, index):
            # starting at index, move left until reaching a letter that gets used
            skip = 0  # how many upcoming letters to ignore
            while index >= 0:
                if string[index] == '#':
                    skip += 1        # one more letter to ignore
                    index -= 1       # move left 1
                elif skip > 0:
                    skip -= 1        # ignore this letter
                    index -= 1       # move left 1
                else:
                    break            # skip is 0 and this is a letter: use it
            return index             # index of that letter, or -1 if none are left

        i = len(s) - 1   # start at the last character of s
        j = len(t) - 1   # start at the last character of t

        while i >= 0 or j >= 0:
            i = next_valid(s, i)   # move i to the next letter of s that gets used
            j = next_valid(t, j)   # move j to the next letter of t that gets used

            if i < 0 and j < 0:
                return True        # both ran out at the same time
            if i < 0 or j < 0:
                return False       # one ran out before the other
            if s[i] != t[j]:
                return False       # the two letters don't match

            i -= 1   # move past the letter just compared
            j -= 1

        return True   # every letter matched and both ran out together
"""

            