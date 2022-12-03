#include "knight.hxx"
#include "board.hxx"
#include <string>

Knight::Knight(Piece::Player player, Position pos)
        : LineMove(player, pos) {
    this->type = Piece::Knight;
}

Piece* Knight::clone() const {
    return new Knight(*this);
}

std::list<Move> Knight::get_possible_moves(const Board &board) const {
    std::list<Move> moves;
    if (!is_taken()) {
        int x = this->get_current_tile().get_x();
        int y = this->get_current_tile().get_y();
        std::list<Tile> tiles = {
                Tile(x + 2, y - 1), Tile(x + 1, y - 2), Tile(x + 2, y + 1),
                Tile(x + 1, y + 2), Tile(x - 2, y - 1), Tile(x - 1, y - 2),
                Tile(x - 2, y + 1),  Tile(x - 1, y + 2)
        };

        for (Tile t : tiles) {
            if (t.valid_tile())
            { moves.push_back(Move(Tile(x, y), t)); }
        }
    }
    return moves;
}