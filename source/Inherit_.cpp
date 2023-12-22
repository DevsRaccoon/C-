#include <iostream>
using namespace std;

//About class inherit in c++

//1. basic class [shape]
class shape
{
	protected:
		int width;
		int height;
	public:
		void setWidth(int w)
		{
			width = w;
		}
		void setHeight(int h)
		{
			height = h;
		}
};

//2. basic class [paintcost]
class PaintCost
{
	public:
		int getCost(int area)
		{
			return area * 70;
		}
};

class Rectangle: public shape, public PaintCost
{
	public:
		int getArea()
		{
			return (width * height);
		}
};

int main(void)
{
	Rectangle Rect;
	int area;
	
	Rect.setWidth(5);
	Rect.setHeight(7);
	
	area = Rect.getArea();
	
	//输出对象的面积
	cout << "Total area " << Rect.getArea() << endl;
	//输出总花费
	cout << "Total paint cost " << Rect.getCost(area) << endl;
	return 0;
}