#include "Stage.hpp"

#include <SFML/Graphics/Color.hpp>

#include <SFML/System/Vector2.hpp>

Stage::Stage(GlobalCoordinates const & GC) : grid(Grid(GC)) {

	background = sf::RectangleShape( sf::Vector2f( GC.BSQ(), GC.BSQ() ) );
	background.setPosition( GC.left(), GC.up() );
	background.setFillColor(color_background);
	
	borders[0] = sf::RectangleShape( sf::Vector2f( GC.BSQ() + width_borders, width_borders ) );
	borders[1] = sf::RectangleShape( sf::Vector2f( width_borders, GC.BSQ() + width_borders ) );
	borders[2] = sf::RectangleShape( sf::Vector2f( GC.BSQ() + width_borders, width_borders ) );
	borders[3] = sf::RectangleShape( sf::Vector2f( width_borders, GC.BSQ() + width_borders) );
	borders[0].setPosition( GC.left() - 0.5*width_borders, GC.up() - 0.5*width_borders );
	borders[1].setPosition( GC.right() - 0.5*width_borders, GC.up() - 0.5*width_borders );
	borders[2].setPosition( GC.left() - 0.5*width_borders, GC.down() - 0.5*width_borders );
	borders[3].setPosition( GC.left() - 0.5*width_borders, GC.up() - 0.5*width_borders );
	
	for(int i=0; i<4; i++){
		borders[i].setFillColor(color_borders);
	}
}
	
Stage::~Stage(){	
}

void Stage::drawStage(sf::RenderWindow & window){
	window.draw(background);
	for(int i=0; i<4; i++){
	//~ int i =3;
		window.draw(borders[i]);
	}		
}
	
void Stage::drawGrid(sf::RenderWindow & window){
	grid.drawGrid(window);
}
