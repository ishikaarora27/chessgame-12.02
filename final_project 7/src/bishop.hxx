#include "linemove.hxx"
#include <list>
#include "board.hxx"

class Bishop : public LineMove {
public:
    // constructor for bishop
    Bishop(Piece::Player player, Position pos);
    // copy constructor.
    virtual Piece* clone() const;
    // returns all possible moves for this figure
    void get_possible_moves(const Board board)
    const;

    bool valid_move(Move move, Board board); //override, equivalent to
    // valid:diagonal_move
    //should check if the move is in bounds and that it is in the list

private:

    static std::list<Move> moves;

};
