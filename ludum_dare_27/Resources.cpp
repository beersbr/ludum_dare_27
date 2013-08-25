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
	textures[0] = 0;
}

void Resources::createPngResource(std::string path, int id)
{

	FREE_IMAGE_FORMAT format = FIF_UNKNOWN;
	format = FreeImage_GetFIFFromFilename(path.c_str());

	if(!FreeImage_FIFSupportsReading(format))
		return;

	FIBITMAP* src = FreeImage_Load(format, path.c_str(), RAW_DISPLAY);

	if(!src)
		return;

	FIBITMAP* dib = FreeImage_ConvertTo32Bits(src);

	resources[id] = dib;
}

FIBITMAP* Resources::getResource(int id)
{
	return nullptr;
}

BYTE* Resources::getBytesFromResource(int id)
{
	if(resources[id] != nullptr)
	{
		FIBITMAP* r = resources[id];

		int width = FreeImage_GetWidth(r);
		int height = FreeImage_GetHeight(r);

		BYTE* bits = (BYTE*)malloc(height * FreeImage_GetPitch(r));
		bits = FreeImage_GetBits(r);
		return bits;
	}
	return nullptr;
}