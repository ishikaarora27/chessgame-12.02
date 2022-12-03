

#include "board.hxx"
#include "piece.hxx"
#include "pawn.hxx"
#include "rook.hxx"
#include "knight.hxx"
#include "bishop.hxx"
#include "queen.hxx"
#include "king.hxx"

#include <cmath>
#include <iostream>




static int const board_size = 8;

Board::Board(){
    make_board();
    reset_board();
}



void Board::make_board() {
    board = vector<vector<Piece>>
            ( board_size , vector<Piece> (board_size, Piece()));
}

void Board::reset_board() {
    for (int i = 0; i < board_size; i++) {
        board[1][i] = new Pawn(Piece::Player::White,  {1,i});
        board[6][i] = new Pawn(Piece::Player::Black,  {6,i});
    }
    board[0][0] = Rook(Piece::Player::White, {0,0});
    board[0][7] = Rook(Piece::Player::White, {0,7});
    board[7][0] = Rook(Piece::Player::Black,{7,0});
    board[7][7] = Rook(Piece::Player::Black, {7,7});
    board[0][1] = Knight(Piece::Player::White,  {0,1});
    board[0][6] = Knight(Piece::Player::White,  {0,6});
    board[7][1] = Knight(Piece::Player::Black, {7,1});
    board[7][6] = Knight(Piece::Player::Black,  {7,6});
    board[0][2] = Bishop(Piece::Player::White, {0,2});
    board[0][5] = Bishop(Piece::Player::White,  {0,5});
    board[7][2] = Bishop(Piece::Player::Black,  {7,2});
    board[7][5] = Bishop(Piece::Player::Black,  {7,5});
    board[0][3] = Queen(Piece::Player::White, {0,3});
    board[7][3] = Queen(Piece::Player::Black, {7,3});
    board[0][4] = King(Piece::Player::White, {0,4});
    board[7][4] = King(Piece::Player::Black, {7,4});
}

void make_move(){

}

bool in_check(){

}

bool checkmate() {
    //store each king location
    //iterate through every piece on the board
    // if any piece can move to that location there is check??
}

//returns the piece at [][]
Piece
Board::operator [] (Position pos) const {
    return board[pos.x][pos.y];
}
