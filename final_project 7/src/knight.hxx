#include "linemove.hxx"
#include <list>
#include "ge211.hxx"

class Knight : public LineMove {
public:
    // constructor for rook
    Knight(Piece::Player player, Position pos);

    // copy constructor.
    virtual Piece* clone() const;
    // returns all possible moves for this figure
    void get_possible_moves(const Board &board) const;

    bool valid_move(Move move, Board board);

private:
    std::list<Move> moves;
};
