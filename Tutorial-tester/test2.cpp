
#include <memory>
#include <iostream>
#include <array>
 


class Rectangle {
private:
    int width;
    int height;
public:
    Rectangle(int w, int h) : width(w), height(h) {
        std::cout << "Rectangle created with width: " << width << " and height: " << height << std::endl;
    }

    ~Rectangle() {
        std::cout << "Rectangle destroyed" << std::endl;
    }
    void printArea(){
        std::cout << "Area: " << width * height << std::endl;
    }


};
void createRectangle(std::unique_ptr<Rectangle>& ptr){
    ptr = std::make_unique<Rectangle>(7,4);
}

void takeOwwnership(std::unique_ptr<Rectangle> r){
    std::cout << "Taking ownership of rectangle" << std::endl;
    r->printArea();
}

std::unique_ptr<Rectangle> makeRect() {
    return std::make_unique<Rectangle>(5, 5);
}

int main() {

    int x = 10;
    int* y = nullptr;
    if (y == nullptr){
        std::cout << "y is null" << std::endl;
    }

    if (!y){
        std::cout << "y is null" << std::endl;
    }

    y = &x;

    if (y) {
        std::cout << "y is not null" << std::endl;
    }

    int **ptr2 = &y; // pointer to pointer

    std::cout << "y: " << y << " | *y: " << *y << std::endl; // Output: 10
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr.at(i) << " ";
    }
    int* p = arr.data(); // Get pointer to the first element

    std::cout << " Initial pointer from list, p: " << p << " | *p: " << *p << std::endl; // Output: 1

    p++; // Move to the next element
    std::cout << "after p++ to the pointer, p: " << p << " | *p: " << *p << std::endl; // Output: 2

    p += 2; // Move two elements forward
    std::cout << "after p += 2 to the pointer, p: " << p << " | *p: " << *p << std::endl; // Output: 4


    int* dyn = new int(42);
    std::cout << "Dynamic memory allocation, dyn: " << dyn << " | *dyn: " << *dyn << std::endl; // Output: 42

    *dyn = 100;

    std::cout << "After changing value, dyn: " << dyn << " | *dyn: " << *dyn << std::endl; // Output: 100

    delete dyn; // Free the allocated memory
    std::cout << "After delete, dyn: " << dyn << std::endl; // Output: address of the deleted memory (undefined behavior if dereferenced)
    dyn = nullptr; // Set pointer to null after deletion

    if (!dyn){
        std::cout << "dyn is null after delete + assign nullptr to the variable" << std::endl;
    }


    std::unique_ptr<Rectangle> rect1 = std::make_unique<Rectangle>(10, 5);

    rect1->printArea();

    std::unique_ptr<Rectangle> rect3 = std::move(rect1);
    if(!rect1){
        std::cout << "rect1 is null after move" << std::endl;
    }
    rect3->printArea();

    std::unique_ptr<Rectangle> rect2;

    createRectangle(rect2);

    rect2->printArea();

    takeOwwnership(std::move(rect2));

    if (!rect2){
        std::cout << "rect2 is null after move" << std::endl;
    } else{
        std::cout << "rect2 is not null after move, ownership returned" << std::endl;
    }
    std::unique_ptr<Rectangle> rect4 = makeRect();
    rect4->printArea();

    return 0;

}

