class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        # need two pointers where ones tracking one before and one after and if the right pointer is on the hashtag , and left pointer is on the left of that then anything from s[:l] and s[r:] is the new string compared to s or t


        # or u can use a stack where u push everything thats not a # but when there is a $ then u can pop the stack and then keep appending whatever that meets that condiiotn

        # want a helper function because either s or t cna have the ting in it and call it in the reutnr statement
        def build(string):
            stack = []

            for ch in string:
                if ch != '#':
                    stack.append(ch)
                
                elif ch == "#" and len(stack) > 0:
                    stack.pop()
            return stack
        return build(s) == build(t)

