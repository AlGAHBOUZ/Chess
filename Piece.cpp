//
// Created by Veles on 5/1/2023.
//
#include "Piece.h"


Piece::Piece(){
    possible_pos = vector<vector<int> > (9, vector<int>(9, 0));

}

Rook::Rook(string c, bool pos) {
    color = c;

    if (pos == 0)
        initial_j = 1;
    else
        initial_j = 8;

    if (!piece_texture.loadFromFile("PNG/" + color + "Rook.png")) {
        std::cout << "Load failed" << std::endl;
        system("pause");
    }
    piece_rec.setTexture(&piece_texture);
    piece_rec.setSize(sf::Vector2f(80,80));
    sf::Rect<float> globalBounds = piece_rec.getGlobalBounds();
    piece_rec.setOrigin( sf::Vector2f(globalBounds.width/2, globalBounds.height/2));
}

Bishop::Bishop(string c, bool pos) {
    color = c;
    if (pos == 0)
        initial_j = 3;
    else
        initial_j = 6;

    if (!piece_texture.loadFromFile("PNG/" + color + "Bishop.png")) {
        std::cout << "Load failed" << std::endl;
        system("pause");
    }
    piece_rec.setTexture(&piece_texture);
    piece_rec.setSize(sf::Vector2f(80,80));
    sf::Rect<float> globalBounds = piece_rec.getGlobalBounds();
    piece_rec.setOrigin( sf::Vector2f(globalBounds.width/2, globalBounds.height/2));
}

Knight::Knight(string c, bool pos) {
    color = c;

    if (pos == 0)
        initial_j = 2;
    else
        initial_j = 7;

    if (!piece_texture.loadFromFile("PNG/" + color + "Knight.png")) {
        std::cout << "Load failed" << std::endl;
        system("pause");
    }
    piece_rec.setTexture(&piece_texture);
    piece_rec.setSize(sf::Vector2f(80,80));
    sf::Rect<float> globalBounds = piece_rec.getGlobalBounds();
    piece_rec.setOrigin( sf::Vector2f(globalBounds.width/2, globalBounds.height/2));
}

Queen::Queen(string c) {
    color = c;

    initial_j = 4;

    if (!piece_texture.loadFromFile("PNG/" + color + "Queen.png")) {
        std::cout << "Load failed" << std::endl;
        system("pause");
    }
    piece_rec.setTexture(&piece_texture);
    piece_rec.setSize(sf::Vector2f(80,80));
    sf::Rect<float> globalBounds = piece_rec.getGlobalBounds();
    piece_rec.setOrigin( sf::Vector2f(globalBounds.width/2, globalBounds.height/2));
}

King::King(string c) {
    color = c;

    initial_j = 5;

    if (!piece_texture.loadFromFile("PNG/" + color + "King.png")) {
        std::cout << "Load failed" << std::endl;
        system("pause");
    }
    piece_rec.setTexture(&piece_texture);
    piece_rec.setSize(sf::Vector2f(80,80));
    sf::Rect<float> globalBounds = piece_rec.getGlobalBounds();
    piece_rec.setOrigin( sf::Vector2f(globalBounds.width/2, globalBounds.height/2));
}

Pawn::Pawn(string c, int pos) {
    color = c;

    initial_j = pos;

    if (!piece_texture.loadFromFile("PNG/" + color + "Pawn.png")) {
        std::cout << "Load failed" << std::endl;
        system("pause");
    }
    piece_rec.setTexture(&piece_texture);
    piece_rec.setSize(sf::Vector2f(80,80));
    sf::Rect<float> globalBounds = piece_rec.getGlobalBounds();
    piece_rec.setOrigin( sf::Vector2f(globalBounds.width/2, globalBounds.height/2));
}

void Piece::possible_moves() {

}

void Rook::checker(vector<vector<bool> > &empty, vector<vector<Piece> > &Board, int i_step, int j_step) {
    for (int i = curr_pos.first + i_step, j = curr_pos.second + j_step; i > 0 && i < 9 && j > 0 && j < 9; i += i_step, j += j_step) {
        if (empty[i][j]) {
            possible_pos[i][j] = true;
        } else if (Board[i][j].color != color) {
            possible_pos[i][j] = true;
            break;
        } else {
            break;
        }
    }
}

void Rook::possible_moves(vector<vector<bool> > &empty, vector<vector<Piece> > &Board) {
    checker(empty, Board, 1, 0);
    checker(empty, Board, -1, 0);
    checker(empty, Board, 0, 1);
    checker(empty, Board, 0, -1);
}

void Bishop::checker(vector<vector<bool> > &empty, vector<vector<Piece> > &Board, int i_step, int j_step) {
    for (int i = curr_pos.first + i_step, j = curr_pos.second + j_step; i > 0 && i < 9 && j > 0 && j < 9; i += i_step, j += j_step) {
        if (empty[i][j]) {
            possible_pos[i][j] = true;
        } else if (Board[i][j].color != color) {
            possible_pos[i][j] = true;
            break;
        } else {
            break;
        }
    }
}

void Bishop::possible_moves(vector<vector<bool> > &empty, vector<vector<Piece> > &Board) {
    checker(empty, Board, 1, 1);
    checker(empty, Board, -1, -1);
    checker(empty, Board, -1, 1);
    checker(empty, Board, 1, -1);
}

void Queen::checker(vector<vector<bool> > &empty, vector<vector<Piece> > &Board, int i_step, int j_step) {
    for (int i = curr_pos.first + i_step, j = curr_pos.second + j_step; i > 0 && i < 9 && j > 0 && j < 9; i += i_step, j += j_step) {
        if (empty[i][j]) {
            possible_pos[i][j] = true;
        } else if (Board[i][j].color != color) {
            possible_pos[i][j] = true;
            break;
        } else {
            break;
        }
    }
}

void Queen::possible_moves(vector<vector<bool> > &empty, vector<vector<Piece> > &Board) {
    checker(empty, Board, 1, 0);
    checker(empty, Board, -1, 0);
    checker(empty, Board, 0, 1);
    checker(empty, Board, 0, -1);
    checker(empty, Board, 1, 1);
    checker(empty, Board, -1, -1);
    checker(empty, Board, -1, 1);
    checker(empty, Board, 1, -1);
}

void Knight::possible_moves(vector<vector<bool> > &empty, vector<vector<Piece> > &Board) {
    int offsets[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

    for (int k = 0; k < 8; k++) {
        int new_i = curr_pos.first + offsets[k][0];
        int new_j = curr_pos.second + offsets[k][1];


        if (new_i >= 1 && new_i <= 8 && new_j >= 1 && new_j <= 8) {
            if (!empty[new_i][new_j] && Board[new_i][new_j].color != color){
                possible_pos[new_i][new_j] = true;
            }
            else if (empty[new_i][new_j]){
                possible_pos[new_i][new_j] = true;
            }
            else{
                continue;
            }
        }
    }
}

void King::checker(vector<vector<bool> > &empty, vector<vector<Piece> > &Board, int i_step, int j_step) {
    int i = curr_pos.first + i_step, j = curr_pos.second + j_step;
    if (i > 0 && i < 9 && j > 0 && j < 9){
        if (empty[i][j]) {
            possible_pos[i][j] = true;
        } else if (Board[i][j].color != color) {
            possible_pos[i][j] = true;
        } else {
            return;
        }
    }
}

void King::possible_moves(vector<vector<bool> > &empty, vector<vector<Piece> > &Board) {
    checker(empty, Board, 1, 0);
    checker(empty, Board, -1, 0);
    checker(empty, Board, 0, 1);
    checker(empty, Board, 0, -1);
    checker(empty, Board, 1, 1);
    checker(empty, Board, -1, -1);
    checker(empty, Board, -1, 1);
    checker(empty, Board, 1, -1);
}

void Pawn::capture(vector<vector<bool>> &empty, vector<vector<Piece>> &Board) {
    if (color == "white"){
        int new_i = curr_pos.first + 1;
        int new_j = curr_pos.first + 1;
        int new_j_2 = curr_pos.first - 1;
        if (new_i > 0 && new_i < 9 && new_j > 8 && new_j_2 < 1){
            if (!empty[new_i][new_j] && Board[new_i][new_j].color != color)
                possible_pos[new_i][new_j] = 1;
            else if (!empty[new_i][new_j_2] && Board[new_i][new_j_2].color != color)
                possible_pos[new_i][new_j_2] = 1;
            else
                return;
        }
    }

    if (color == "black"){
        int new_i = curr_pos.first - 1;
        int new_j = curr_pos.first + 1;
        int new_j_2 = curr_pos.first - 1;
        if (new_i > 0 && new_i < 9 && new_j > 8 && new_j_2 < 1){
            if (!empty[new_i][new_j] && Board[new_i][new_j].color != color)
                possible_pos[new_i][new_j] = 1;
            else if (!empty[new_i][new_j_2] && Board[new_i][new_j_2].color != color)
                possible_pos[new_i][new_j_2] = 1;
            else
                return;
        }
    }
}


void Pawn::possible_moves(vector<vector<bool> > &empty, vector<vector<Piece> > &Board) {
    if (color == "white"){
        int new_i = curr_pos.first + 1;
        int new_i_2 = curr_pos.first + 2;
        if (moved && new_i > 0 && new_i < 9 && empty[new_i][curr_pos.second]){
            possible_pos[new_i][curr_pos.second] = 1;
        }
        else{
            if (new_i > 0 && new_i < 9 && empty[new_i][curr_pos.second])
            possible_pos[new_i][curr_pos.second] = 1;
            if (empty[new_i_2][curr_pos.second])
                possible_pos[new_i_2][curr_pos.second] = 1;
        }
    }

    if (color == "black"){
        int new_i = curr_pos.first - 1;
        int new_i_2 = curr_pos.first - 2;
        if (moved && new_i > 0 && new_i < 9 && empty[new_i][curr_pos.second]){
            possible_pos[new_i][curr_pos.second] = 1;
        }
        else{
            if (new_i > 0 && new_i < 9 && empty[new_i][curr_pos.second])
                possible_pos[new_i][curr_pos.second] = 1;
            if (empty[new_i_2][curr_pos.second])
                possible_pos[new_i_2][curr_pos.second] = 1;
        }
    }

    capture(empty, Board);
}

