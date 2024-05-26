#ifndef LOAD_MEDIA_H
#define LOAD_MEDIA_H 1
	#include "define.h"
	#include "sprite.h"
	#include "data.h"
	#include <vector>
	#include <string>
	#include <fstream>
	#include <iostream>
	#include <filesystem>
	#include <system_error>
	#include <SDL2/SDL_image.h>
	#include <nlohmann/json_fwd.hpp>

	class Load_Media{
	public:
		/// @brief Here all the images are saved.
		std::map<std::string,SDL_Surface*>images;
		/// @brief This is where all the sprites are saved
		std::map<std::string,Sprite_*>sprites;
		/*std::vector<Data*> persons,
		maps,
		weapons;*/
		/**!
		 * Read a file and convert it to JSON class
		 * 
		 * @param[in] path The path of the file
		 * @param[out] root Where to save JSON data
		 * @return bool There were no errors?
		 */
		static bool load_json(std::string path, nlohmann::json* root);
		bool loads();
		Load_Media();
		~Load_Media();
		/** Frees memory from images stored in global variables (resource_images) */
		static void clear();
	};
	/** Loads an image and saves it in the global "resource_images" variable
	 * @brief I don't upload an image
	 * 
	 * @param[in] path url of imagen
	 * @return A copy of SDL_Surface* or nullptr on error.
	 */
	SDL_Surface* add_resource_img(const std::string* path);
#endif