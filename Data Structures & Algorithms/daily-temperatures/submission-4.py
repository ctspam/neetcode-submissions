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



            