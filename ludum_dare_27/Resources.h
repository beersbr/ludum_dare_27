#pragma once

#include <iostream>
#include <FreeImage.h>
#include <map>

class Resources
{
public:
	static Resources* instance();

	void createPngResource(std::string path, int id);
	FIBITMAP* getResource(int id);
	BYTE* getBytesFromResource(int id);

public:
	unsigned int textures[16];

private:
	Resources(void);
	static Resources* instance_;

	std::map<int, FIBITMAP*> resources;

};

