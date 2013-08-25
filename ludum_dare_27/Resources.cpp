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

void Resources::createPngResource(std::string path, int id)
{
	FIBITMAP* r = FreeImage_Load(FIF_PNG, path.c_str());
	if(!r)
		return;

	resources[id] = r;
}

FIBITMAP* Resources::getResource(int id)
{
	return nullptr;
}

BYTE* Resources::getBytesFromResource(int id)
{
	if(resources[id] != nullptr)
	{
		BYTE* image = FreeImage_GetBits(resources[id]);
		return image;
	}
	return nullptr;
}