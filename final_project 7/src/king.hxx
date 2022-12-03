
#include "piece.hxx"

#include <list>

class King : public Piece {
public:
    // king constructor

    King(Player player, Position pos);

    // copy constructor.
    Piece* clone() const;
    // all possible moves for the king
    void get_possible_moves(const Board board) const;


private:

    std::list<Move> moves;


};
