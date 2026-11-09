class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        
        # to set this you would probably want to do the up down righ tand left neighbors of the 0s and turn it into 0s, maybe ine o(1) lookup so maybe like building soem type of hashmap 

        rows, cols = len(matrix), len(matrix[0])
        rowzero = False

        # determine which rows/cols need to be zero

        for r in range(rows):
            for c in range(cols):
                if matrix[r][c] == 0:
                    matrix[0][c] = 0

                    if r > 0:
                        matrix[r][0] = 0
                    else: 
                        rowzero = True

        for r in range(1, rows):
            for c in range(1, cols):
                if matrix[0][c] == 0 or matrix[r][0] == 0:
                    matrix[r][c] = 0

        if matrix[0][0] == 0:
            for r in range(rows):
                matrix[r][0] = 0

        if rowzero:
            for c in range(cols):
                matrix[0][c] = 0

