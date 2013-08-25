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



