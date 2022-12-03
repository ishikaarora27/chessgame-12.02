#pragma once
#include <iostream>
#include <ge211.hxx>
#include "board.hxx"


class Piece{
public:
    enum Player {Black, White, Neither};
    enum Type{None, Pawn, Rook, Knight, Bishop, Queen, King};
    //bool Captured doesn't need to be enum
    using Position = ge211::geometry::Posn<int>;

    //constructor for an empty piece
    Piece();
    //constructor for the piece: sets invalid to false
    Piece(Player player, Type type, Position pos);

    //constructor that doesn't initialize the type
    Piece(Player player, Position pos);


    //destructor for the piece
    virtual ~Piece() = default;

    // get player
    Player get_player(Player player);
    //set player
    void set_player(Player player);
    // get type
    Type get_type(Type type);
    // set type
    void set_type(Type type);
    // set captured
    void set_captured();
    // get pos
    Position get_position() const;
    // get x_coordinate
    /* how do you implement these? */
    // get y_coord
    // set pos
    void set_position(Position pos);
    // valid move for any piece

    //checks if the piece is empty/invalid
    bool get_invalid();

    //sets the piece to empty
    void set_invalid();


    //I think we should do one definition of valid_move
    // checks if it will be in bounds and the move is unoccupied
    bool valid_move(Position start, Position end, Board board);
    // valid moves for rooks and queens
    bool valid_line_move(Position start, Position end, Board board);
    // valid moves for bishops and queens
    bool valid_diagonal_move(Position start, Position end, Board board);

private:



protected:
    // the type of piece it is (doesn't change)
    Piece::Type type;
    bool invalid;

    // the player (white or black)
    Piece::Player player;
    //
    bool captured;
    //
    Position position;
    //
    int x;
    //
     int y;

    std::string filename_white;
    std::string filename_black;

};



