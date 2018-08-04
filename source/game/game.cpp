/* Game: A high freedom sandbox game just like Minecraft.
* This name of game is informal.
* Copyright (c) 2018 MurongSama.
*
* This file is a part of Game.
* Game is a open source game and it follows the GPLv3 protocol.
* For more information, see <http://www.gnu.org/licenses/gpl-3.0.html>
*/

#include "./gameCore/base.h"

int main() {
	// Initialize engine
	___output_console_info << "Initializing graphics engine...";
	Game::Core::Backend::initializeEngine();

	// Create a window
	___output_console_info << "Creating window...";
	Game::Core::BaseWindow::Window temp_window($game_name, $window_default_size_x, $window_default_size_y);

	// Initialize renderer
	___output_console_info << "Initializing renderer...";
	Game::Core::BaseRenderer::Renderer temp_renderer = Game::Core::BaseRenderer::initializeRenderer();

	___output_console_info << "Test info message";
	___output_console_warning << "Test warning message: " << 233;
	___output_console_error << "Test error message: " << 1 + 1;

	// Loop
	do {
		//temp_renderer.useProgram();

		Game::Core::Backend::GL::checkError();

		temp_window.refresh();
		Game::Core::Backend::GLFW::poll();
	} while (!temp_window.getQuit());

	// Terminate
	___output_console_info << "Waiting for game to end...";
	Game::Core::Backend::GLFW::quit();
}
