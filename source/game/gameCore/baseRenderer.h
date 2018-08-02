/* Game: A high freedom sandbox game just like Minecraft.
* This name of game is informal.
* Copyright (c) 2018 MurongSama.
*
* This file is a part of Game.
* Game is a open source game and it follows the GPLv3 protocol.
* For more information, see <http://www.gnu.org/licenses/gpl-3.0.html>
*/

#ifndef GAME_CORE_RENDERER_H
#define GAME_CORE_RENDERER_H

#include "baseInclude.h"

namespace Game {
	namespace Core {
		namespace BaseRenderer {
			class Renderer {
			public:
				Renderer(std::string in_vertex_source, std::string in_fragment_source, std::vector<double> in_vertex_array);
				~Renderer();

				// Operator
				void compileShader(Game::type_uint in_type);
				void linkProgram();
				void useProgram() const;

				// Get
				std::string getShaderVertexSource() const { return this->shader_vertex_source; }
				std::string getShaderFragmentSource() const { return this->shader_fragment_source; }
				Game::type_id getShaderVAO() const { return this->shader_vao; }
				Game::type_id getShaderVBO() const { return this->shader_vbo; }
				Game::type_id getShaderVertex() const { return this->shader_vertex; }
				Game::type_id getShaderFragment() const { return this->shader_fragment; }
				Game::type_id getShaderProgram() const { return this->shader_program; }
				double getShaderVertexArray() const { return *this->shader_vertex_array; }
			private:
				std::string shader_vertex_source, shader_fragment_source;
				Game::type_id shader_vao, shader_vbo;
				Game::type_id shader_vertex, shader_fragment, shader_program;
				double shader_vertex_array[$GAME_ARRAY_MAX$];
			};

			static double shader_vertex_triangle[9];

			// Operator
			Game::Core::BaseRenderer::Renderer initializeRenderer();
		}
	}
}

#endif // !GAME_CORE_RENDERER_H
