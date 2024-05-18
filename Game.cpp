//
// Created by Veles on 5/1/2023.
//
#include "Game.h"

Rook rooks[4] = {Rook("black", 0), Rook("black", 1), Rook("white", 0), Rook("white", 1)};
Bishop bishops[4] = {Bishop("black", 0), Bishop("black", 1), Bishop("white", 0), Bishop("white", 1)};
Knight knights[4] = {Knight("black", 0), Knight("black", 1), Knight("white", 0), Knight("white", 1)};
Queen queens[2] = {Queen("black"),Queen("white")};
King kings[2] = {King("black"),King("white")};
Pawn pawns[16] = {Pawn("black", 1), Pawn("black", 2), Pawn("black", 3), Pawn("black", 4), Pawn("black", 5),Pawn("black", 6),Pawn("black", 7),Pawn("black", 8),Pawn("white", 1),Pawn("white", 2),Pawn("white", 3),Pawn("white", 4),Pawn("white", 5),Pawn("white", 6),Pawn("white", 7),Pawn("white", 8)};

Game::Game() {
    cout << "Game Constructor" << endl;
    is_window_on_start_frame = 1;
    // Initialize variables
    empty = vector<vector<bool> > (9, vector<bool>(9, 0));
    Board = vector<vector<Piece> > (9, vector<Piece>(9));
    // Call Initializing functions
    InitWindow();
}


// Destructor
Game::~Game() {
    delete window;
    delete bg_sprite;
    // delete the pointers

}

// Private Functions
void Game::InitWindow() {
    // Initialize window variables
    cout << "InitWindow" << endl;

    videoMode.width = WINDOW_WIDTH;
    videoMode.height = WINDOW_HEIGHT;
    window = new sf::RenderWindow(videoMode, "Chess", sf::Style::Titlebar | sf::Style::Close);
    window->setFramerateLimit(144);
    // Load the background images
    if (!bg_texture.loadFromFile("PNG/bg.png")) {
        std::cout << "Load failed" << std::endl;
        system("pause");
    }

    // Load the background image
    UpdateBackgroundImage();
}



void Game::UpdateBackgroundImage() {
    cout << "UpdateBackgroundImage" << endl;
    // Load the background image
    bg_sprite = new sf::Sprite(bg_texture);

    bg_sprite->setTextureRect(sf::IntRect(0, 0, 1280, 960));
    bg_sprite->setColor(sf::Color(255, 255, 255));
}

bool Game::IsRunning() {
    cout << "IsRunning" << endl;
    return window->isOpen();
}

void Game::PollEvents() {
    cout << "PollEvents" << endl;
    // Event Polling
    while (window->pollEvent(event)) {
        switch (event.type) {
            // If the user closed the program
            case sf::Event::Closed:
                window->close();
                break;
                // If the user clicked escape key and closed the program
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    window->close();
                break;
                // Event of clicking the mouse
            case sf::Event::MouseButtonPressed: {
                if (sf::Mouse::Button::Left == event.mouseButton.button) {
                    // Checking if the user clicked
                }
                break;
            }
        }
    }
}

bool Game::CheckWinStatus() {
    // Check here

}

void Game::DrawChessBoard() {
    cout << "DrawChessBoard" << endl;
    sf::RectangleShape square(sf::Vector2f(80.0f, 80.0f));
    sf::Rect<float> globalBounds = square.getGlobalBounds();
    square.setOrigin( sf::Vector2f(globalBounds.width/2, globalBounds.height/2));

    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            square.setPosition(80.0f * i, 80.0f * j);
            if ((i + j) % 2 == 0) {
                square.setFillColor(sf::Color(255, 206, 158));
            } else {
                square.setFillColor(sf::Color(209, 139, 71));
            }
            chessboard_squares[i][j] = square;
        }
    }
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            window->draw(chessboard_squares[i][j]);
        }
    }
}

void Game::initialize_pieces() {
    cout << "initialize_pieces" << endl;
    for (int i = 0; i < 4; i++) {
        int row = (i < 2) ? 1 : 8;
        rooks[i].piece_rec.setPosition(sf::Vector2f(chessboard_squares[rooks[i].initial_j][row].getPosition()));
        bishops[i].piece_rec.setPosition(sf::Vector2f(chessboard_squares[bishops[i].initial_j][row].getPosition()));
        knights[i].piece_rec.setPosition(sf::Vector2f(chessboard_squares[knights[i].initial_j][row].getPosition()));
    }

    for (int i = 0; i < 2; i++) {
        int row = (i < 1) ? 1 : 8;
        queens[i].piece_rec.setPosition(sf::Vector2f(chessboard_squares[queens[i].initial_j][row].getPosition()));
        kings[i].piece_rec.setPosition(sf::Vector2f(chessboard_squares[kings[i].initial_j][row].getPosition()));
        cout << chessboard_squares[1 + 7 * (i / 2)][kings[i].initial_j].getPosition().x << " : " << chessboard_squares[1 + 7 * (i / 2)][kings[i].initial_j].getPosition().y << endl;
    }

    for (int i = 0; i < 16; i++) {
        int row = (i < 8) ? 2 : 7;
        pawns[i].piece_rec.setPosition(sf::Vector2f(chessboard_squares[pawns[i].initial_j][row].getPosition()));
    }

}

void Game::DrawFrame() {
    cout << "DrawFrame" << endl;
    // Drawing
    window->clear();
    UpdateBackgroundImage();
    window->draw(*bg_sprite);
    DrawChessBoard();
    cout << "After Draw Chess Board" << endl;
    initialize_pieces();
    for (int i = 0; i < 4; i++){
        window->draw(rooks[i].piece_rec);
        window->draw(bishops[i].piece_rec);
        window->draw(knights[i].piece_rec);
    }
    for (int i = 0; i < 16; i++){
        window->draw(pawns[i].piece_rec);
    }
    for (int i = 0; i < 2; i++){
        window->draw(kings[i].piece_rec);
        window->draw(queens[i].piece_rec);
    }


    // Display
    window->display();
}

void Game::DrawWinFrame() {
    window->clear();
    // Load the image here
}