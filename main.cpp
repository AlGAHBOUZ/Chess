#include "Game.h"

int main() {
    // Initializing the Solitaire game
    Game game;

    // Game loop
    while (game.IsRunning()) {
        // Events Loop
        game.PollEvents();

        // Draw
        game.DrawFrame();
    }
}
