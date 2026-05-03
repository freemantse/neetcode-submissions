class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        n = len(board[0])

        for i in range(n):
            row_seen = set()
            col_seen = set()
            square_seen = set()
            for j in range(n):
                if board[i][j] == '.':
                    continue
                if board[i][j] in row_seen:
                    return False
                row_seen.add(board[i][j])
            for j in range(n):
                if board[j][i] == '.':
                    continue
                if board[j][i] in col_seen:
                    return False
                col_seen.add(board[j][i])
            for j in range(int(n/3)):
                for k in range(int(n/3)):
                    row = (i//3) * 3 + j
                    col = (i % 3) * 3 + k
                    if board[row][col] == ".":
                        continue
                    if board[row][col] in square_seen:
                        return False
                    square_seen.add(board[row][col])
        return True