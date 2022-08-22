board = [
    [0, 0, 0], 
    [0, 0, 0], 
    [0, 0, 0]
]
glyph = {"cross":1, "circle":2}

def check_winner(move, player):
    if board[move[0]][move[1]] == 0:
        board[move[0]][move[1]] = glyph[player]
    else:
        print("Already moved there.")
        return False, 1

    for i in range(0, 3):
        if board[i][0] == board[i][1] == board[i][2] and not board[i][0] == 0 :
            return False, 0
        if board[0][i] == board[1][i] == board[2][i] and not board[0][i] == 0:
            return False, 0

    if board[0][0] == board[1][1] == board[2][2] and not board[0][0] == 0:
        return False
    if board[2][0] == board[1][1] == board[0][2] and not board[2][0] == 0:
        return False, 0
    
    return True, 0

def game(player1, player2):
    turn = 0
    flag = True
    state = 0

    while turn < 9 and flag:
        move = list(map(int, input("Player {} -> Enter move as coordinates (space seperated) : ".format(turn%2 + 1)).split()))

        if turn % 2:
            flag, state = check_winner(move, player1)
        else:
            flag, state = check_winner(move, player2)
        
        if not flag:
            break
        turn += 1

    if turn == 9:
        print("Tie")
    
    else:
        if state == 0:
            print("Player {} won.".format(turn%2 + 1))
        


if __name__ == "__main__":
    player1 = input("Player 1 : Choose cross or circle : ")

    if player1 == "circle":
        player2 = "cross"
    else:
        player2 = "circle"

    print("Player 2 given : " + player2)

    game(player1, player2)