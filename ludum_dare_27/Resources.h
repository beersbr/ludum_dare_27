#pragma once

#include <iostream>
#include <FreeImage.h>
#include <map>

class Resources
{
public:
	static Resources* instance();

	void createPngResource(std::string path, std::string tag);
	FIBITMAP* getResource();

private:
	Resources(void);
	static Resources* instance_;

	std::map<std::string, FIBITMAP*> resourses;
};

