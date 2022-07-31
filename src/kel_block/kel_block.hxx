/*
	Project Kelnoid.
	
	This is a project for showing how C++ Game Code works.
	
	This is the Header File for the Kel_Block Class.
*/

#define KELNOID_RED_BLOCK		0x01
#define KELNOID_BLUE_BLOCK		0x02
#define KELNOID_YELLOW_BLOCK	0x03
#define KELNOID_ORANGE_BLOCK	0x04
#define KELNOID_GREY_OUT_BLOCK	0x05
#define KELNOID_HEAVY_OUT_BLOCK 0x06

class Kel_Block {
	private:
		short type;
		int points;
		float xPosition;
		float yPosition;
		
		/*
			to be used later ... 
		*/
		float length;
		float breadth;
		int health;
	public:
		Kel_Block(short, int, float, float);
		
		short getType();
		
		int getPoints();
		
		float getXPosition();
		
		float getYPosition();
};
