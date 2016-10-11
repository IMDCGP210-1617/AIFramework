#pragma once
#include "BaseEntity.h"
#include <list>
#include "UtilRandom.h"

class SteeringFlee : public BaseEntity
{
public:
	static std::list<SteeringFlee*> Boids;

public:
	SteeringFlee();
	SteeringFlee(std::string file);
	SteeringFlee(std::string file, sf::Color colour);

	virtual ~SteeringFlee();

	void Think();

	void Initialize() override;

private:

	const float minDistance = 100.0f;

	sf::Vector2f acceleration;
	float maxForce;
	const float maxSpeed = 0.1f;
	float angle;
};

