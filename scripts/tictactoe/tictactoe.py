import random, time

class TicTacToe:
    def __init__(self):
        self.board = [['-' for _ in range(3)] for _ in range(3)]
        self.current_player = 'X'

    def switch_player(self):
        self.current_player = 'O' if self.current_player == 'X' else 'X'

    def check_win(self, player) -> bool:
        for i in range(3):
            if all(self.board[i][j] == player for j in range(3)):
                return True
            if all(self.board[j][i] == player for j in range(3)):
                return True
        if all(self.board[i][i] == player for i in range(3)):
            return True
        if all(self.board[i][2 - i] == player for i in range(3)):
            return True
        return False

    def is_full(self):
        return all(self.board[i][j] != '-' for i in range(3) for j in range(3))

    def get_random_move(self):
        available_moves = [(i, j) for i in range(3) for j in range(3) if self.board[i][j] == '-']
        return random.choice(available_moves)

    def display_board(self):
        for row in self.board:
            print(' '.join(row))
        print()

    def play_game(self):
        while True:
            move = self.get_random_move()
            self.board[move[0]][move[1]] = self.current_player
            self.display_board()
            if self.check_win(self.current_player):
                print(f"Player {self.current_player} wins!\n")
                return self.current_player
            if self.is_full():
                print("It's a draw!\n")
                return '-'
            self.switch_player()

if __name__ == "__main__":
    shit: int = 100
    x_wins, o_wins, draws = 0, 0, 0

    start_time = time.time()

    for i in range(shit):
        print(f"Game {i + 1}")
        game = TicTacToe()
        result = game.play_game()
        if result == 'X':
            x_wins += 1
        elif result == 'O':
            o_wins += 1
        else:
            draws += 1

    end_time = time.time()
    total_time = end_time - start_time

    print(f"""Final Results:
    X Wins: {x_wins}
    O Wins: {o_wins}
    Draws: {draws}
    Total Time: {1000 * total_time:.3f} seconds
    """)
