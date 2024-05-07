#pragma once

#include <string>

class Texture {
public:
	virtual void Bind() const = 0;
	virtual void UnBind() const = 0;
	virtual ~Texture() = default;;

private:
	std::string filePath;

protected:
	std::string getFilePath() const { return filePath; }
	explicit Texture(const std::string& filePath);
	Texture();
};

