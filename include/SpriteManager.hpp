#pragma once

#include "SFML/Graphics.hpp"

#include <unordered_map>

class SpriteManager {
public:
	// Return True when we succeed in loading the sprite.
	bool add_sprite_from_sheet(const sf::Image& sprite_sheet,
	                           const std::string& name,
	                           const sf::IntRect& area);

	// Retrieve a sprite by name.
	const sf::Sprite& get_sprite(const std::string& name) const;

private:
	// It's only important that the textures live as long as the sprites.
	// We won't be accessing them later, so we don't care where they go. Just as long as they live.
	std::vector<sf::Texture> textures_;

	// Return this sprite whenever we can't find a specific sprite.
	// TODO: Find something useful for this. An empty sprite may make debugging difficult.
	sf::Sprite error_sprite_;

	std::unordered_map<std::string, sf::Sprite> sprite_map_;
	
	// TODO: Handle animations.
	// Maybe have sprite_map_ map from strings to vectors, which we then cycle through for
	//   animation.
};
