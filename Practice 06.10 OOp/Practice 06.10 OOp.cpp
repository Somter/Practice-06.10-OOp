// Practice 06.10 OOp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//	
/*дз:
* 1.Создать класс Попугай на основе Animal, реализовать нужные интерфейсы
* 2. Создать класс Самолет, и реализовать нужный интерфейс.
* 3. Создать функцию, который может работать и с объектом класса самолет, и с объектом класса попугай!!
*/

#include <iostream>
#include <cstring>
using namespace std;

struct Weight 
{
    virtual void _Weight() = 0;   
};

struct Speed
{
    virtual void _Speed() = 0;      
};

struct WingSize 
{
    virtual void _WingSize() = 0;   
};

struct FlightAltitude 
{
    virtual void _FlightAltitude() = 0; 
};

class Animal {
protected:
    char* name;
public:
    Animal() = default;
    Animal(const char* n) {
        name = new char[strlen(n) + 1];
        strcpy_s(name, strlen(n) + 1, n);
    }
    virtual void Continent() = 0;
    virtual void Sound() = 0;
    virtual void Eat() = 0;
    ~Animal() {
        delete[] name;
    }
};

class Parrot : public Animal, public Weight, public Speed, public WingSize, public FlightAltitude
{
private:
    char* continent;    
public:

    Parrot(const char* c, const char* n) : Animal(n) {
        continent = new char[strlen(c) + 1];
        strcpy_s(continent, strlen(c) + 1, c);
    }

    void Continent() {
        cout << "Попугай живет в " << continent << endl;
    }

    void Sound() {
        cout << "Попугаи издают какие-то звуки\n";
    }

    void Eat() {
        cout << "Попугай ест корм\n";
    }

    void _Weight() 
    {
        cout << "Вес попугая 7 кг\n";
    }
    void _Speed()
    {
        cout << "Попугай летит со скоростью 20-40 км/ч\n";   
    }
    void _WingSize()
    {
        cout << "Размер кральев 20 см \n";  
    }
    void _FlightAltitude()  
    {
        cout << "Высота полёта 5 - 30 метров\n";
    }

    ~Parrot() {
        delete[] continent;
    }
};

void Rezult(Weight* ptr1, Speed* ptr2, WingSize* ptr3, FlightAltitude* ptr4)        
{
    ptr2->_Speed();
    ptr1->_Weight();
    ptr3->_WingSize();
    ptr4->_FlightAltitude();    
}

class Airplane: public Weight, public Speed, public WingSize, public FlightAltitude
{
public:
    void _Weight()
    {
        cout << "Вес попугая 1.000 - 600.000 кг\n";
    }
    void _Speed()
    {
        cout << "Самолёт летит со скоростью 900 км/ч\n";    
    }
    void _WingSize()
    {
        cout << "Размер кральев 64 метра \n";
    }
    void _FlightAltitude()
    {
        cout << "Высота полёта 10.500 метров\n";
    }
};
int main() {
    setlocale(LC_ALL, "");   
    Parrot obj1("Африка", "Жако");    
    obj1.Continent();   
    obj1.Sound();       
    obj1.Eat();               
    Rezult(&obj1, &obj1, &obj1, &obj1);     
    for (int i = 0; i < 40; i++) { cout << "-"; }   
    cout << endl;   
    Airplane obj2;
    Rezult(&obj2, &obj2, &obj2, &obj2); 
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
