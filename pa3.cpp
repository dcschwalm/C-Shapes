#include <iostream>

using namespace std;

int main(void);

class SHAPE
{
	private:
	int width;
	int height;
	int depth;
	
	virtual int space(void) = 0;   //pure virtual function
	
	public:
	int get_width(void){return width;}
	int get_height(void){return height;}
	int get_depth(void){return depth;}
	
	SHAPE(const int w, const int h, const int d){width=w; height=h; depth=d;}
	SHAPE(void){width=-99;height=-99;depth=-99;}
	
	int print_space(void){cout << "Space is = " << space() << endl;}
};

class SQUARE:public SHAPE
{
	private:
	int space(void){ return get_width() * get_height();}
	
	public:
	SQUARE(void);
	SQUARE(const int size):SHAPE(size,size,1)
	{
	};
};

class CUBE:public SHAPE
{
	private:
	int space(void){return get_width() * get_height() * get_depth();}
	
	public:
	CUBE(void);
	CUBE(const int size):SHAPE(size,size,size)
	{
	};
};

SQUARE::SQUARE(void):SHAPE(-99,-99,-99)  // uses the SHAPE const to set w h d
{

}

CUBE::CUBE(void):SHAPE(-99,-99,-99)
{

}

int main(void)
{
	cout <<"Dave Schwalm" <<endl;
	
	SQUARE s1(2);
	CUBE c1(2);
	
	s1.print_space(); //prints 4
	c1.print_space(); //prints 8
	
	SQUARE s2; //set to -99...?
	s2.print_space();
	
	CUBE c2;
	c2.print_space();
	
	return 0;
}
