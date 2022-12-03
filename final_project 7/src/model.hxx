#pragma once
#include <ge211.hxx>
#include "piece.hxx"
#include "board.hxx"
#include "move.hxx"

class Model
{



public:

    using Position = ge211::Posn<int>;

    Model(Board board);

    void create_move(ge211::Posn<int> start, ge211::Posn<int> end);

    void set_game_over();

    //returns the board
    Board board() const;



    //overloaded operator
    Piece operator [] (Position pos) const;

private:

    Piece::Player turn;
    Piece current_piece;
    Board board_;

    void calculate_valid_moves(Piece p);


};
