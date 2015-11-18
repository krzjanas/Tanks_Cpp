#ifndef Stage_hpp
#define Stage_hpp

#include <SFML/Graphics.hpp>

#include "../Configure/GlobalCoordinates.hpp"
#include "Additions/Grid.hpp"

class Stage {
	public:
	
		Stage(GlobalCoordinates const & GC);
		~Stage();
		
		void drawStage(sf::RenderWindow & window);		
		void drawGrid(sf::RenderWindow & window);
	
	private:		

		sf::RectangleShape background;
		sf::RectangleShape borders[4];
		
		const sf::Color color_background = sf::Color(0, 0, 0);
		const sf::Color color_borders    = sf::Color(255, 255, 255);
		const float width_borders = 8;		
		
		Grid grid;			

};







#endif
