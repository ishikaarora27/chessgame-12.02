#include "king.hxx"
#include "board.hxx"

King::King(Piece::Player player, Piece::Position pos)
        : Piece(player, Piece::King, pos) {
    this->type = Piece::King;
}
/*
Piece* King::clone() const {
    return new King(*this);
} */

void King::get_possible_moves(const Board board) const {
    std::list <Move> moves;
    if (this.invalid) { //what is is_taken
        int x = this->position.x;
        int y = this->position.y;
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                int dst_x = x + i;
                int dst_y = y + j;
                if (dst_x >= 0 && dst_x < 8 && dst_y >= 0 && dst_y < 8) {
                    if (board.get_piece({dst_x, dst_y}).invalid();
                        && board.get_piece({dst_x, dst_y})->get_player() !=
                        this->get_player()) {
                        moves.push_back(Move({x, y}, {dst_x, dst_y}));
                    }
                    else if (board.get_piece({dst_x, dst_y}).invalid()) {
                        moves.push_back(Move({x, y}, {dst_x, dst_y}));
                    }
                }
            }
        }
    }
}