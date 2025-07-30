//
// Created by MiaKim on 30/07/2025.
//
#include <iostream>
#include <vector>

using namespace std;

class Car {
private:
    string Make{};
    string Model{};
    string Type{};
    string Fuel{};
    int EngineSize{};

public:
    //constructor
    Car(string make, string model, string type, string fuel, int engineSize) {
        Make = make;
        Model = model;
        Type = type;
        Fuel = fuel;
        EngineSize = engineSize;
    }

    //getter
    string getMake() {
        return Make;
    }
    string getModel() {
        return Model;
    }
    string getType() {
        return Type;
    }
    string getFuel() {
        return Fuel;
    }
    int getEngineSize() {
        return EngineSize;
    }

    void details() {
        cout << Make << "," << Model << "," << Type << "," << Fuel << "," << EngineSize<<" (cc)"<< endl;
    }

};


int main() {
    Car Car1("Volvo","XC40","SUV","Petrol",1969);
    Car Car2("Volvo","XC90","SUV","Hybrid",1969);
    Car Car3("Jaguar","I-Pace","SUV","Electric",294);
    Car Car4("Jaguar","F-Pace","SUV","Petrol",2996);
    Car Car5("Range Rover","Evoque","SUV","Diesel",1999);

    vector<Car>carCollections;
    carCollections.push_back(Car1);
    carCollections.push_back(Car2);
    carCollections.push_back(Car3);
    carCollections.push_back(Car4);
    carCollections.push_back(Car5);

    Car4.details();

    for (int i; i < carCollections.size(); i++) {
        if (carCollections[i].getFuel() == "Hybrid" || carCollections[i].getFuel() == "Electric") {
            carCollections[i].details();
        }
    }

}
