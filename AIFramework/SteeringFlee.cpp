#include "SteeringFlee.h"

std::list<SteeringFlee*> SteeringFlee::Boids;

SteeringFlee::SteeringFlee() 
{
	SetTextureFile("assets\\boid.png");
	SetColour(sf::Color::White);
	Initialize();
}

SteeringFlee::SteeringFlee(std::string file)
{
	SetTextureFile(file);
	SetColour(sf::Color::White);
	Initialize();
}

SteeringFlee::SteeringFlee(std::string file, sf::Color colour) 
{
	SetTextureFile(file);
	SetColour(colour);
	Initialize();
}

SteeringFlee::~SteeringFlee()
{
	Boids.remove(this);
}

void SteeringFlee::Think()
{
	acceleration = sf::Vector2f(0.0f, 0.0f);
	sf::Vector2f steer = sf::Vector2f(0.0f, 0.0f);
	int count = 0;

	// loop all the boids, we'll only check those within a certain distance to us.
	for (SteeringFlee *boid : Boids) 
	{
		sf::Vector2f boidPos = boid->getPosition();
		sf::Vector2f direction = getPosition() - boidPos;
		float magnitude = sqrt((direction.x * direction.x) + (direction.y * direction.y));

		// we don't care if the boid is outside our minimum distance.
		if (magnitude > minDistance || boid == this)
			continue;

		count++;
		
		// normalize the direction
		direction /= magnitude;

		steer += direction;
	}

	if (count > 0)
	{
		steer /= (float)count;
		float steerMag = sqrt((steer.x * steer.x) + (steer.y * steer.y));
		steer /= steerMag;
		steer *= maxSpeed;
		steer -= velocity;

		acceleration += steer;
	}
	
	sf::Vector2f currentPos = getPosition();
	velocity += acceleration;
	
	float mag = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
	velocity /= mag;

	velocity *= maxSpeed;

	setPosition(currentPos + velocity);
	
}

void SteeringFlee::Initialize()
{
	Boids.push_back(this);

	float x = UtilRandom::instance()->GetRange(0, 800);
	float y = UtilRandom::instance()->GetRange(0, 600);

	angle = UtilRandom::instance()->GetRange(0, 361);
	setRotation(angle);

	velocity = sf::Vector2f(cos(angle * M_PI / 180), sin(angle * M_PI / 180));

	float mag = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
	velocity /= mag;
	velocity *= maxSpeed;

	setPosition(x, y);
}
