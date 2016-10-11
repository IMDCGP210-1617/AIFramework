#pragma once

#include <random>

// Util Random is a singleton class that allows us to generate a random number within a fixed range
// it uses elements from the C++11 update to replace the use of rand().
class UtilRandom
{
public:
	UtilRandom();
	~UtilRandom();

	// GetRange returns a random number between min and max
	// it is poorly named, we're not really getting a range...
	float GetRange(float min, float max);

private:
	// we use the mersenne twister implementation to generate our random numbers
	std::mt19937 mt;

	// we have a private static instance of the class
	static UtilRandom* _instance;
public:

	// the static instance() function means we can control the number of instances allowed at any one time (here, one).
	static UtilRandom* instance()
	{
		if (!_instance)
			_instance = new UtilRandom;
		return _instance;
	}
};

