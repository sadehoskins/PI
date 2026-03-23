#include <iostream>
#include <limits>
#include <memory>

#include "base_car.h"
#include "sports_car.h"
#include "suv.h"

// Clears invalid input 
void ClearInput() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int ReadChoice(int min, int max) {
    int choice = 0;
    while (true) {
        std::cout << "> ";
        if (std::cin >> choice && choice >= min && choice <= max) {
            return choice;
        }
        std::cout << "Invalid input. Enter a number between "
            << min << " and " << max << ".\n";
        ClearInput();
    }
}

// Select and create concrete car
std::shared_ptr<car::BaseCar> CreateCar() {
    std::cout << "\n============================\n"
        << "  Available Cars:\n"
        << "  1. SportsCar (V6 Engine, Manual Gears,\n"
        << "     Sport Wheels, Disc Brakes,\n"
        << "     Monocoque Frame, Coilover Suspension)\n"
        << "  2. SUV (Electric Motor, Automatic Gears,\n"
        << "     Off-Road Wheels, Drum Brakes,\n"
        << "     Ladder Frame, Air Suspension)\n"
        << "============================\n"
        << "Select a car (1-2): ";

    int choice = ReadChoice(1, 2);
    std::shared_ptr<car::BaseCar> sp_car;

    if (choice == 1) {
        sp_car = std::make_shared<car::SportsCar>();
    }
    else {
        sp_car = std::make_shared<car::Suv>();
    }

    std::cout << "\nUser has created a " << sp_car->car_type()
        << ".\n";
    sp_car->PrintStatus();
    return sp_car;
}

// main loop
void ControlLoop(std::shared_ptr<car::BaseCar>& sp_car) {
    bool running = true;
    while (running) {
        std::cout << "*** " << sp_car->car_type() << " Controls ***\n"
            << "1. Start Engine\n"
            << "2. Accelerate Forward\n"
            << "3. Brake\n"
            << "4. Reverse\n"
            << "5. Turn Left\n"
            << "6. Turn Right\n"
            << "7. Stop Engine\n"
            << "8. Print Status\n"
            << "9. Switch Car\n"
            << "0. Exit\n";

        int choice = ReadChoice(0, 9);

        switch (choice) {
        case 1:
            sp_car->StartEngine();
            break;
        case 2:
            sp_car->Accelerate();
            break;
        case 3:
            sp_car->Brake();
            break;
        case 4:
            sp_car->ReverseAccelerate();
            break;
        case 5:
            sp_car->TurnLeft();
            break;
        case 6:
            sp_car->TurnRight();
            break;
        case 7:
            sp_car->StopEngine();
            break;
        case 8:
            sp_car->PrintStatus();
            break;
        case 9:
            sp_car = CreateCar();
            break;
        case 0:
            running = false;
            std::cout << "Exiting. Goodbye!\n";
            break;
        default:
            break;
        }
        std::cout << "\n";
    }
}

int main() {
    std::cout << "*************************************\n"
        << "  Task 6 — Vehicle Simulation\n"
        << "*************************************\n";

    std::shared_ptr<car::BaseCar> sp_car = CreateCar();
    ControlLoop(sp_car);
    return 0;
}