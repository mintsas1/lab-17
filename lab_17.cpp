#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Room {
private:
    double area; 

public:
    
    Room(double area) : area(area) {}

    
    double getArea() const {
        return area;
    }
};

class OneRoomApartment {
private:
    Room room;   
    double kitchenArea; 

public:
    
    OneRoomApartment(const Room& room, double kitchenArea) : room(room), kitchenArea(kitchenArea) {}

    
    double getRoomArea() const {
        return room.getArea();
    }

    
    double getKitchenArea() const {
        return kitchenArea;
    }
};


class CityApartment : public OneRoomApartment {
private:
    string cityName; 

public:
    
    CityApartment(const Room& room, double kitchenArea, const string& cityName)
        : OneRoomApartment(room, kitchenArea), cityName(cityName) {}

    
    void printInfo() const {
        cout << "Квартира в місті " << cityName << ":" << endl;
        cout << "Площа кімнати: " << getRoomArea() << " кв. м" << endl;
        cout << "Площа кухні: " << getKitchenArea() << " кв. м" << endl;
    }
};

int main() {
    setlocale(LC_CTYPE, "ukr"); 

    
    Room room(20.0);

    
    OneRoomApartment apartment(room, 7.0);

    
    cout << "Інформація про однокімнатну квартиру:" << endl;
    cout << "Площа кімнати: " << apartment.getRoomArea() << " кв. м" << endl;
    cout << "Площа кухні: " << apartment.getKitchenArea() << " кв. м" << endl;
    cout << endl;

    
    CityApartment cityApartment(room, 8.0, "Харків");

    
    cityApartment.printInfo();

    return 0;
}
