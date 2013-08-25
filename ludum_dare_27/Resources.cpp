#include "Resources.h"


Resources* Resources::instance_ = nullptr;

Resources* Resources::instance()
{
	if(Resources::instance_ == nullptr)
		Resources::instance_ = new Resources();

	return Resources::instance_;
}

Resources::Resources(void)
{

}

void Resources::createPngResource(std::string path, std::string tag)
{
	//FIBITMAP* r = FreeImage_Load(FIF_PNG, path.c_str());
	//resources[tag] = r;
}

FIBITMAP* Resources::getResource(std::string tag)
{
	return nullptr;
}

BYTE* Resources::getOpenGLTExture(std::string tag)
{
	return nullptr;
}