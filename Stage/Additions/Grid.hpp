#ifndef Grid_hpp
#define Grid_hpp

#include <SFML/Graphics.hpp>

#include "../../Configure/GlobalCoordinates.hpp"

class Grid {
	
	public:
	
		Grid(GlobalCoordinates const & GC);
		~Grid();
	
		void drawGrid(sf::RenderWindow & window);
	
	private:	
		sf::RectangleShape grid_main[2][12];
		sf::RectangleShape grid_addition[2][13];
				
		const sf::Color color_grid_main	 = sf::Color(200, 200, 200);
		const sf::Color color_grid_addition = sf::Color(150, 150, 150);
		const float width_grid_main	  = 2;
		const float width_grid_addition = 1;
	
};

#endif
