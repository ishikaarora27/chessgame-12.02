#include "bishop.hxx"
#include "board.hxx"
#include <string>

Bishop::Bishop(Piece::Player player, Position pos)
        : LineMove(player, pos) {
    this->type = Piece::Bishop;
    this->filename_white = "white bishop.png";
    this->filename_black = "black bishop.png";
}

Piece* Bishop::clone() const {
    return new Bishop(*this);
}

void Bishop::get_possible_moves(const Board board) const {
    if (!invalid) {
        bool up = true;
        bool right = true;
        bool down = true;
        bool left = true;
        int i = 1;
        while (up || right || down || left) {
            check_move(board, moves, up, i, 0);
            check_move(board, moves, right, 0, i);
            check_move(board, moves, down, -i, 0);
            check_move(board, moves, left, 0, -i);
            i++;
        }
    }
}

bool
Bishop::valid_move(Move move, Board board){
    for (Move m: moves) {
        if(m == move){
            return true;
        }
    }
    return false;
}