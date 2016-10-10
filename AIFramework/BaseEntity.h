#pragma once

/**
 * BaseEntity, the basic building block of any AI agent in the framework.
 * 
 * This is the parent class for any agents desired to be added to the system,
 * it inherits from sf::Transformable to give us access to set / get position and related functionality.
 */

#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#define _USE_MATH_DEFINES

#include <math.h>

class BaseEntity : public sf::Transformable
{
public:
	/**
	 * static std vector of BaseEntity pointers, currently used to loop all entities for rendering and ticking.
	 */
	static std::vector<BaseEntity*> Renderables;
public:
	/**
	 * Base constructor, defaults all variables.
	 */
	explicit BaseEntity();
	/**
	 * Constructor that accepts a texture file name
	 * @param file a string filename
	 */
	explicit BaseEntity(std::string file);
	/**
	 * Constructor that accepts a texture file name and a colour tint
	 * @param file a string filename
	 * @param colour a sf::Color value
	 */
	explicit BaseEntity(std::string file, sf::Color colour);

	/**
	 * Deconstructor
	 */
	virtual ~BaseEntity();

	/** 
	 * Think is the standard "update" function for all agents
	 * All agents must implement their own Think function - there is nothing provided in the base class.
	 */
	virtual void Think();

	/**
	 * GetSprite provides access to the entities sprite object
	 * @return sf::Sprite current entities sprite
	 */
	sf::Sprite GetSprite() { return sprite; }

	/**
	 * SetColour allows for post-construction alteration of the colour tint
	 * @param colour a sf::Colour value
	 */
	void SetColour(sf::Color colour) { colourTint = colour; }

	/**
	* SetTextureFile is used to set the filename variable
	* @param string a filename
	*/
	void SetTextureFile(std::string file) { filename = file; }

protected:
	std::string filename;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Color colourTint;

	sf::Vector2f velocity;

protected:
	/**
	 * Initialize assures our texture is loaded using the assigned file name and initial colour tint
	 */
	virtual void Initialize();
};


