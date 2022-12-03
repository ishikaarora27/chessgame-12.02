#include "linemove.hxx"
#include "board.hxx"

LineMove::LineMove(Piece::Player player, Position pos)
        : piece (player, pos) {
}

void LineMove::check_move(const Board board, std::list<Move> &moves,
                                  bool &direction, int dx, int dy) const {
    int x = piece.get_position().x;
    int y = piece.get_position().x;

    if (!direction) { return; }
    Position p = {x + dx, y + dy};
    if (!p.in_bounds()) {
        direction = false;
        return;
    }
    if (!board[p].get_invalid()) {
        direction = false;
        if (board[p].get_player() != piece.get_player()) {
            moves.push_back(Move(Tile(x, y), t));
        }
    } else {
        moves.push_back(Move(Tile(x, y), t));
    }
}