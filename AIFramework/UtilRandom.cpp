#include "UtilRandom.h"

UtilRandom *UtilRandom::_instance = 0;

UtilRandom::UtilRandom() : mt(std::random_device()())
{
	
}

UtilRandom::~UtilRandom()
{
}

float UtilRandom::GetRange(float min, float max)
{
	std::uniform_real_distribution<float> dist(min, max);
	return dist(mt);
}
