#include "SpriteManager.hpp"

#include "Common.hpp"

bool SpriteManager::addSpriteFromSheet(const sf::Image& sprite_sheet,
	                                      const std::string& name,
						                  const sf::IntRect& area) {
	
	auto texture = std::make_shared<sf::Texture>();

	if (!texture->loadFromImage(sprite_sheet, area)) {
		sf::err() << "Encountered a problem trying to load sprite \"" << name << "\",\n"
			<< "\tUnable to load area,"
			<< "\t\tleft:   " << area.left
			<< "\t\ttop:    " << area.top
			<< "\t\twidth:  " << area.width
			<< "\t\theight: " << area.height
			<< "\tfrom sprite_sheet." << std::endl;
		return false;
	}
	
	textures_.push_back(texture);
	
	auto pair = sprite_map_.emplace(name, sf::Sprite(*texture));

	// std::unordered_map::emplace returns a std::pair containing an iterator and a bool.
	// That bool is false if it couldn't insert it for some reason, but otherwise true.
	if (!pair.second) {
		// Remove that last texture. It turns out, we don't need it.
		textures_.pop_back();
		sf::err() << "Encountered a problem trying to load sprite \"" << name << "\",\n"
			<< "\tunable to insert new sprite into the sprite map.\n" << std::endl;
		return false;
	}
	return true;
}

sf::Sprite SpriteManager::getSprite(const std::string& name) const {
	auto result = sprite_map_.find(name);
	if (result != sprite_map_.end()) {
		return result->second;
	}
	throw std::exception("Unable to load the sprite.");
}
