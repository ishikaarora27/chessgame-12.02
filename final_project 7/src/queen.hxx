#include "linemove.hxx"
#include <list>


class Queen : public LineMove {
public:
    // constructor for rook
    Queen(Piece::Player player, Position pos);
    // copy constructor.
    virtual Piece* clone() const;
    // returns all possible moves for this figure
    void get_possible_moves(const Board board) const;
    //called to check if a move is valid
    bool valid_move(Move move, Board board);

private:

    std::list<Move> moves;
};