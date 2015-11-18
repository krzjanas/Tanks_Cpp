/*################################*/
/*########## T A N K S ###########*/
/*###### by Krzysztof Janas ######*/
/*################################*/

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Configure/GlobalCoordinates.hpp"
#include "Stage/Stage.hpp"
#include "Tanks/Vis/VisTankBase.hpp"

using namespace std;

int main(){

	GlobalCoordinates GC = GlobalCoordinates(720);
	
	sf::RenderWindow window(sf::VideoMode(GC.sizeX(),GC.sizeY()), ".T.A.N.K.S.");

	Stage stage = Stage(GC);
	

	VisTankBase tank0(GC.SQ(),GC.gX(0), GC.gY(0));
	VisTankBase tank1(GC.SQ(),GC.gX(3), GC.gY(2));
	tank1.rotate( VisTankBase::Direction::Right );
	VisTankBase tank2(GC.SQ(),GC.gX(-4.5), GC.gY(-3));
	
	int i = 0;

	while (window.isOpen()){

		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(70, 70, 70));
		
		stage.drawStage(window);
		
		tank0.draw(window);
		tank1.draw(window);
		tank2.draw(window);
		
		i++;
		if(GC.gY(-3) - 0.00001*i*GC.SQ()>GC.up()+GC.SQ()*0.5){
			tank2.setPosition(GC.gX(-4.5), GC.gY(-3) - 0.00001*i*GC.SQ());
		}

		//~ stage.drawGrid(window);	
		window.display();
		

	}




	return 0;
}
