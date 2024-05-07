#include "Texture.h"

Texture::Texture(const std::string& filePath) : filePath(filePath) {}

Texture::Texture() {
	filePath = "";
}
