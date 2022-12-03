#include "board.hxx"
#include "piece.hxx"
#include <string>

Piece::Piece()
    : invalid(true),
    position(0,0)
{}

Piece::Piece(Player player, Type type, Position pos)
        : player(player),
          type(type),
          position(pos),
          captured(false),
          invalid(false)
{}

Piece::Piece(Player player, Position pos)
: player(player),
position(pos)
{}

Piece::Player
Piece::get_player(Player player){
    return player;
}

void Piece::set_player(Player player){
    this->player = player;
}

Piece::Type
Piece::get_type(Type type){
    return type;
}

void Piece::set_type(Type type){
    this->type = type;
}

void Piece::set_captured(){
    this->captured = true;
}

Piece::Position
Piece::get_position() const
{
    return this->position;
}

void Piece::set_position(Position pos){
    this->position = pos;
}

bool Piece::get_invalid(){
    return invalid;
}

void Piece::set_invalid(){
    invalid = true;
}



//if the piece is in bounds of the board
bool Piece::valid_move(Position start, Position end, Board board) {
    Piece destination = board[end];
    if ((end.x < 8 && end.y < 8 && end.x >= 0 && end.y >= 0
         && destination.get_player() == Neither) || player !=
                                                    destination.get_player
                                                                       ()) {
        return true;
    } else {
        return false;
    }
}



