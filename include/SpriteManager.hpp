#pragma once

#include "SFML/Graphics.hpp"

#include <unordered_map>

class SpriteManager {
public:
	// Copying a SpriteManager messes up textures_. Don't do it.
	SpriteManager(const SpriteManager&) = delete;
	SpriteManager& operator=(const SpriteManager& other) = delete;
	
	SpriteManager() {
		// It's very, very important that this doesn't resize. Ever.
		// Otherwise, it invalidates every sprite object depending on these textures.
		// We reserve an obscene amount of space and hope for the best.
		textures_.reserve(500);
	}

	SpriteManager& operator=(SpriteManager&& other) {
		textures_       = std::move(other.textures_);
		current_sprite_ = std::move(other.current_sprite_);
		sprite_map_     = std::move(other.sprite_map_);
		return *this;
	}

	// Return true when we succeed in loading the sprite.
	bool add_sprite_from_sheet(const sf::Image& sprite_sheet,
	                           const std::string& name,
	                           const sf::IntRect& area);

	// Retrieve a sprite by name.
	sf::Sprite get_sprite(const std::string& name) const;

	void setCurrent(const std::string& name) {
		current_sprite_ = get_sprite(name);
	}

	const sf::Sprite& getCurrent() const {
		return current_sprite_;
	}

private:
	// It's only important that the textures live as long as the sprites.
	// We won't be accessing them later, so we don't care where they go. Just as long as they live.
	std::vector<sf::Texture> textures_;

	// The sprite which this object's owner is currently using. Might be worth using
	//   in animations.
	sf::Sprite current_sprite_;

	std::unordered_map<std::string, sf::Sprite> sprite_map_;
	
	// TODO: Handle animations.
	// Maybe have sprite_map_ map from strings to vectors, which we then cycle through for
	//   animation.
};
