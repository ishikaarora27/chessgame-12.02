#include "model.hxx"


Model::Model(Board board)
: board_(board)
{}

//returns the board
Board
Model::board(){
    return board_;
}

Piece
Model::operator [] (Position pos) const {
    return board_[pos];
}