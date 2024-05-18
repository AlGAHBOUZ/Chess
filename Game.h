//
// Created by Veles on 5/1/2023.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H
#include "Piece.h"

// NOTE: Stick to the naming conventions:
// Functions: Camel Case
// Variables: Underscores
// The name should be representative


class Game {
public:
    // Containers


    // Window variables
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Texture bg_texture;
    sf::Sprite *bg_sprite;

    // Event variable
    sf::Event event;


    // Other Variables
    bool is_window_on_start_frame;
    sf::RectangleShape chessboard_squares [9][9];
    vector<vector<bool> > empty;
    vector<vector<Piece> > Board;





    // Private Functions
    void InitWindow();
    void UpdateBackgroundImage();
    // Constructor
    Game();

    // Destructor
    ~Game();

    // Functions
    bool IsRunning();
    void PollEvents();
    void initialize_pieces();

    // Getters

    // Setters



    // Click function
    void MouseClick();

    // Winning function
    bool CheckWinStatus();



    // Draw to window functions
    void DrawFrame();
    void DrawWinFrame();
    void DrawChessBoard();
};

#endif //CHESS_GAME_H
