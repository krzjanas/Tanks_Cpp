#ifndef GlobalCoordinates_h
#define GlobalCoordinates_h

#include <SFML/System/Vector2.hpp>

class GlobalCoordinates{
	private:
		int m_window_X;
		int m_window_Y;	
	
	public:
		
		GlobalCoordinates() : m_window_X(1152), m_window_Y(720) {};
		GlobalCoordinates(int f_window_Y) : m_window_X(1152*f_window_Y/720), m_window_Y(f_window_Y) {};
		~GlobalCoordinates(){};
		
		int sizeX() const { return m_window_X; }
		int sizeY() const { return m_window_Y; }
		
		sf::Vector2i size() const { return sf::Vector2i(m_window_X,m_window_Y); }
		
		
		int SQ()  const { return m_window_Y / 15; };
		int BSQ() const { return m_window_Y / 15 * 13; };
		
		int midX() const { return m_window_X / 2; };
		int midY() const { return m_window_Y / 2; };
		
		int left()  const { return midX() - BSQ() / 2; }
		int right() const { return midX() + BSQ() / 2; }
		int up()    const { return midY() - BSQ() / 2; }
		int down()  const { return midY() + BSQ() / 2; }
		
		int gX(float xx) const { return  xx * SQ() + midX(); }
		int gY(float yy) const { return -yy * SQ() + midY(); }
		
		sf::Vector2i gl(float xx, float yy) const { return sf::Vector2i( gX(xx), gY(-yy) ); }
		
};


#endif
