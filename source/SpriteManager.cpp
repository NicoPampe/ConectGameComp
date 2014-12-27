#include "SpriteManager.hpp"

#include "Common.hpp"

bool SpriteManager::add_sprite_from_sheet(const sf::Image& sprite_sheet,
	                                      const std::string& name,
						                  const sf::IntRect& area) {
	sf::Texture texture;
	return_on_fail(texture.loadFromImage(sprite_sheet, area));
	
	textures_.push_back(texture);

	auto sprite = sf::Sprite(textures_.back());
	auto pair = sprite_map_.insert(std::make_pair(name, sprite));

	// std::unordered_map::insert returns a std::pair: an iterator and a bool.
	// That bool is false if it couldn't insert it for some reason.
	return_on_fail(pair.second);
}

const sf::Sprite& SpriteManager::get_sprite(const std::string& name) const {
	auto result = sprite_map_.find(name);
	if (result != sprite_map_.end()) {
		return result->second;
	}
	// That sprite isn't in here. Maybe we should throw an exception or something?
	// This shouldn't happen.
	return error_sprite_;
}
