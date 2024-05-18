//
// Created by Veles on 5/1/2023.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H
#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
using namespace std;


#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 960


class Piece {
public:
    // variables
    string color;
    pair<int,int>curr_pos;
    vector<vector<int>> possible_pos;
    sf::Texture piece_texture;
    sf::RectangleShape piece_rec;
    int initial_j;


    //Functions

    Piece();
    virtual void possible_moves();

};

class Rook : public Piece{
public:
    Rook(string c, bool pos);
    bool moved = 0;
    void checker(vector<vector<bool> > &empty, vector<vector<Piece> > &Board, int i_step, int j_step);
    void possible_moves(vector<vector<bool> > &empty, vector<vector<Piece> > &Board);
};

class Bishop : public Piece{
public:
    Bishop(string c, bool pos);
    void checker(vector<vector<bool> > &empty, vector<vector<Piece> > &Board, int i_step, int j_step);
    void possible_moves(vector<vector<bool> > &empty, vector<vector<Piece> > &Board);
};

class Knight : public Piece{
public:
    Knight(string c, bool pos);
    void possible_moves(vector<vector<bool> > &empty, vector<vector<Piece> > &Board);
};

class Queen : public Piece{
public:
    Queen(string c);
    void checker(vector<vector<bool> > &empty, vector<vector<Piece> > &Board, int i_step, int j_step);
    void possible_moves(vector<vector<bool> > &empty, vector<vector<Piece> > &Board);
};

class Pawn : public Piece{
public:
    Pawn(string c, int pos);
    bool moved;
    void capture(vector<vector<bool> > &empty, vector<vector<Piece> > &Board);
    void possible_moves(vector<vector<bool> > &empty, vector<vector<Piece> > &Board);
};

class King : public Piece{
public:
    King(string c);
    void checker(vector<vector<bool> > &empty, vector<vector<Piece> > &Board, int i_step, int j_step);
    void possible_moves(vector<vector<bool> > &empty, vector<vector<Piece> > &Board);
};



#endif //CHESS_PIECE_H
