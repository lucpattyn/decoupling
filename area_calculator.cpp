#include <iostream>
#include <list>
#include <any>
#include <functional>

#include <cmath>

struct Shape{
	Shape(std::string name, std::any areainfo) : _name(name), _areainfo(areainfo){
		
	}	
	std::function<double(std::any)> areaCalculator = [](std::any info){
		std::cout << "area unknown";
		return 0.0;
	};
	
	// get area 	
	double calculateArea(){
		return areaCalculator(_areainfo);
	}
	// get name/type of shape
	std::string getShapeName(){
		return _name;
	}	
	
	std::any _areainfo;
	std::string _name;
};

struct Rect{
	Rect(double width, double height){
		w = width;
		h = height;
	}
	double w;
	double h;
};

struct Circle{
	Circle(double radius){
		r = radius;
	}
	double r;
};

int main(){

	auto rectAreaCalculator = [](std::any info){
		double d = 0;
		try {
    		Rect r = std::any_cast<Rect>(info);
    		d = r.w * r.h;
		}
		catch(const std::bad_any_cast& e) {
			std::cout << e.what() << '\n';
		}
		
		return d;
	};
	
	auto circleAreaCalculator = [](std::any info){
		double d = 0;
		try {
    		Circle c = std::any_cast<Circle>(info);
    		d = M_PI * c.r * c.r; 
		}
		catch(const std::bad_any_cast& e) {
			std::cout << e.what() << '\n';
		}
		
		return d;
	};   
		
	Shape rectShape("rectangle", Rect(4,4));
	rectShape.areaCalculator = rectAreaCalculator;
	
	Shape circleShape("circle", Circle(1));
	circleShape.areaCalculator = circleAreaCalculator;
	
	std::list<Shape> shapes;
	shapes.push_back(rectShape);
	shapes.push_back(circleShape);
	
	for(auto shape:shapes){
		std::cout << "shape: " << shape.getShapeName() << ", area: " << rectShape.calculateArea() << std::endl;
	}
	
	return 0;

}
