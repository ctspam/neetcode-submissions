class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""
        for s in strs:
            res += str(len(s)) + "|" +s

        return res

    def decode(self, s: str) -> List[str]:
        res = []
        # i tracks the current number and where it starts
        i = 0
        while i < len(s):
            k = i
             # this moves j forwar until it lands on the |
            while s[k] != "|":
                k+=1
            # this bringsback the number of the len(s) of that string
            length_string = int(s[i:k])
            # this is where the start of the splice begins
            start = k+1
            # splice exactly this amount of chars
            res.append(s[start:start+length_string])
            # now move i to where the next num starts
            i = start+length_string
        return res
