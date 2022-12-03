#ifndef LINEMOVE_HXX
#define LINEMOVE_HXX

#include "piece.hxx"
#include "board.hxx"

class LineMove : public Piece {
public:
    using Piece::Position;
    // Constructor to create the line move
    LineMove(Player player, Position pos);
protected:
    // computes all possible moves into a given direction
    void check_move(const Board &board, std::list<Move> &moves, bool &direction, int dx, int dy) const;

private:
    Piece piece;
};
#endif