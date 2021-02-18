int main() {
    Color* color = new RedColor;
    Shape* shape = new Triangle(3, 4, color);
	
    cout << "Kind of structure: ";
    shape->printDetails();
    cout << "Area: " << shape->getArea();
	
	return 0;
}