//Nick Krisulevicz
//Lab 2, part 3, findpoint class
//09/14/2021

#include <iostream>
#include <cmath>
using namespace std;

class Point{
	private:
		float x;
		float y;
	public:
		Point(){
			x = 0;
			y = 0;
		}
		Point(float x1, float y1){
			x = x1;
			y = y1;
		}
		void setX(float xc){
			x = xc;
		}
		void setY(float yc){
			y = yc;
		}
		float getX()const{
			return x;
		}
		float getY()const{
			return y;
		}
		Point operator+(const Point& p){
			Point pdist;
			pdist.x = this -> x + p.x;
			pdist.y = this -> y + p.y;
			return pdist;
		}


};

int main(){
	Point point1;
	Point point2;
	float one;
	float two;

	cout << "Enter the first coordinate in first point: " << endl;
	cin >> one;

	cout << "Enter the second coordinate in forst point: " << endl;
	cin >> two;

	point1.setX(one);
	point1.setY(two);

	cout << "Enter the first coordinate in second point: " << endl;
	cin >> one;

	cout << "Enter the second coordinate in second point: " << endl;
	cin >> two;

	point2.setX(one);
	point2.setY(two);

	cout << "Point 1's coordinates are: " << point1.getX() << ", " << point1.getY() << endl;
	cout << "Point 2's coordinates are: " << point2.getX() << ", " << point2.getY() << endl;

	Point point3 = point1 + point2;
	cout << "The distance point between point 1 and point 2 is: " << point3.getX() << ", " << point3.getY() << endl;

	return 0;
}

