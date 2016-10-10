#pragma once

#include <random>

class UtilRandom
{
public:
	UtilRandom();
	~UtilRandom();

	float GetRange(float min, float max);

private:
	std::mt19937 mt;

	static UtilRandom* _instance;
public:
	static UtilRandom* instance()
	{
		if (!_instance)
			_instance = new UtilRandom;
		return _instance;
	}
};

