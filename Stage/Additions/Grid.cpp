#include "Grid.hpp"

#include <SFML/System/Vector2.hpp>

Grid::Grid(GlobalCoordinates const & GC){
	
	// Main grid
	for(int i=0; i<12; i++){		
		grid_main[0][i] = sf::RectangleShape( sf::Vector2f( GC.BSQ(), width_grid_main ) );
		grid_main[0][i].setPosition( GC.left(), GC.gY( i - 5.5 ) - 0.5 * width_grid_main );
				
		grid_main[1][i] = sf::RectangleShape( sf::Vector2f( width_grid_main, GC.BSQ() ) );
		grid_main[1][i].setPosition( GC.gX( i - 5.5 ) - 0.5 * width_grid_main, GC.up() );
		
		for(int j=0; j<2; j++){
			grid_main[j][i].setFillColor(color_grid_main);
		}
	}
	
	// Additional grid 
	for(int i=0; i<13; i++){
		grid_addition[0][i] = sf::RectangleShape( sf::Vector2f( GC.BSQ(), width_grid_addition ) );
		grid_addition[0][i].setPosition( GC.left(), GC.gY( i - 6.0 ) - 0.5 * width_grid_addition );
		
		grid_addition[1][i] = sf::RectangleShape( sf::Vector2f( width_grid_addition, GC.BSQ() ) );
		grid_addition[1][i].setPosition( GC.gX( i - 6.0 ) - 0.5 * width_grid_addition, GC.up() );
		
		for(int j=0; j<2; j++){
			grid_addition[j][i].setFillColor(color_grid_addition);
		}
	}
	
}

Grid::~Grid(){	
}

void Grid::drawGrid(sf::RenderWindow & window){
	
	// Main grid
	for(int i=0; i<12; i++){
		for(int j=0; j<2; j++){
			window.draw( grid_main[j][i] );
		}
	}

	// Additional grid 
	for(int i=0; i<13; i++){
		for(int j=0; j<2; j++){
			window.draw( grid_addition[j][i] );
		}
	}
	
}

	
	
	
	
	
