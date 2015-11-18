#ifndef VisTankBase_hpp
#define VisTankBase_hpp

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class VisTankBase{
	
	public: 
		enum Direction{ Up, Right, Down, Left };
	
	public:
		VisTankBase(float const fsize, float const fxPos = 0.0, float const fyPos = 0.0);
		~VisTankBase();
		
		void setPosition(float const xPos, float const yPos);
		void setPosition(sf::Vector2f & pos);
		void draw(sf::RenderWindow & window);
		void setColor(sf::Color const & lTraColor, sf::Color const & rTraColor, sf::Color const & gunColor, sf::Color const & turrColor);
		
		
		void rotate(Direction dir);
		
	private:
		const float size;
		
		sf::RectangleShape 	leftTrack;
		sf::RectangleShape 	rightTrack;
		sf::RectangleShape 	gun;
		sf::CircleShape	turret;
		

};
		
#endif
