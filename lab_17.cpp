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
        cout << "�������� � ��� " << cityName << ":" << endl;
        cout << "����� ������: " << getRoomArea() << " ��. �" << endl;
        cout << "����� ����: " << getKitchenArea() << " ��. �" << endl;
    }
};

int main() {
    setlocale(LC_CTYPE, "ukr"); 

    
    Room room(20.0);

    
    OneRoomApartment apartment(room, 7.0);

    
    cout << "���������� ��� ����������� ��������:" << endl;
    cout << "����� ������: " << apartment.getRoomArea() << " ��. �" << endl;
    cout << "����� ����: " << apartment.getKitchenArea() << " ��. �" << endl;
    cout << endl;

    
    CityApartment cityApartment(room, 8.0, "�����");

    
    cityApartment.printInfo();

    return 0;
}
