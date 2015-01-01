#pragma once

#include "SFML/Graphics.hpp"

#include <memory>
#include <unordered_map>

class SpriteManager {
public:
	SpriteManager() = default;
	SpriteManager(const SpriteManager&) = default;

	// This *should* work, but doesn't in VS2013. Such is life.
	// As long as we don't define them anywhere, the compiler will continue to
	//   generate default versions.
//	SpriteManager& operator=(const SpriteManager& other) = default;
//	SpriteManager& operator=(SpriteManager&& other) = default;

	// Return true when we succeed in loading the sprite.
	bool addSpriteFromSheet(const sf::Image& sprite_sheet,
	                           const std::string& name,
	                           const sf::IntRect& area);

	// Retrieve a sprite by name.
	sf::Sprite getSprite(const std::string& name) const;

	void setCurrent(const std::string& name) {
		current_sprite_ = getSprite(name);
	}

	const sf::Sprite& current() const {
		return current_sprite_;
	}

private:
	using Shared_Texture = std::shared_ptr<sf::Texture>;
	// It's only important that the textures live as long as the sprites.
	// We won't be accessing them later, so we don't care where they go. Just as long as they live.
	std::vector<Shared_Texture> textures_;

	// The sprite which this object's owner is currently using. Might be worth using
	//   in animations.
	sf::Sprite current_sprite_;

	std::unordered_map<std::string, sf::Sprite> sprite_map_;
	
	// TODO: Handle animations.
	// Maybe have sprite_map_ map from strings to vectors, which we then cycle through for
	//   animation?
};
