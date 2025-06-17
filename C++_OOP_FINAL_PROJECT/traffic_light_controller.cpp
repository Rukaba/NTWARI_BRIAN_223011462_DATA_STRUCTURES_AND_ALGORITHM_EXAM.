#include <iostream> // Includes the iostream library for input/output operations.
#include <cstring> // Includes the cstring library for string manipulation.
#include <chrono> // Includes the chrono library for time-related functions.
#include <thread> // Includes the thread library for managing threads and delays.
using namespace std; // Allows usage of standard library components without prefixing with std::.
using namespace std::chrono; // Allows usage of chrono components without prefixing with std::chrono.

// State struct
struct State { // Defines a struct to represent a traffic light state with a color and duration.
    char color[20]; // Stores the color of the traffic light.
    int duration; // Stores the duration for which the state is active.
};

// Abstract base class
class TrafficLightController { // Defines an abstract base class for traffic light controllers.
public:
    State* states; // Pointer to an array of states.
    int nStates; // Number of states in the controller.

    TrafficLightController() : states(nullptr), nStates(0) {} // Constructor initializing states and nStates.

    virtual void cycleStates() = 0; // Pure virtual function to cycle through states (must be implemented by derived classes).
    virtual const char* getType() = 0; // Pure virtual function to get the type of the controller.

    virtual ~TrafficLightController() { // Virtual destructor to ensure proper cleanup of derived class objects.
        delete[] states; // Deletes the dynamically allocated states array.
    }
};

// UrbanController implementation
class UrbanController : public TrafficLightController { // Derived class for urban traffic light controller.
public:
    UrbanController() { // Constructor initializing states and nStates for urban traffic lights.
        nStates = 3; // Sets the number of states to 3.
        states = new State[nStates]{ // Dynamically allocates and initializes the states array.
            {"Red", 3}, // Red light for 3 seconds.
            {"Green", 4}, // Green light for 4 seconds.
            {"Yellow", 2} // Yellow light for 2 seconds.
        };
    }

    void cycleStates() override { // Overrides the cycleStates function to cycle through urban states.
        cout << "UrbanController cycle:\n"; // Prints the type of controller.
        for (int i = 0; i < nStates; ++i) { // Loops through each state.
            cout << "Color: " << states[i].color << ", Duration: " << states[i].duration << "s\n"; // Prints state details.
            this_thread::sleep_for(seconds(states[i].duration)); // Pauses for the duration of the state.
        }
    }

    const char* getType() override { // Overrides the getType function to return the type of controller.
        return "UrbanController"; // Returns the type as "UrbanController".
    }
};

// PedestrianController implementation
class PedestrianController : public TrafficLightController { // Derived class for pedestrian traffic light controller.
public:
    PedestrianController() { // Constructor initializing states and nStates for pedestrian traffic lights.
        nStates = 2; // Sets the number of states to 2.
        states = new State[nStates]{ // Dynamically allocates and initializes the states array.
            {"Walk", 3}, // Walk signal for 3 seconds.
            {"Don't Walk", 5} // Don't Walk signal for 5 seconds.
        };
    }

    void cycleStates() override { // Overrides the cycleStates function to cycle through pedestrian states.
        cout << "PedestrianController cycle:\n"; // Prints the type of controller.
        for (int i = 0; i < nStates; ++i) { // Loops through each state.
            cout << "Signal: " << states[i].color << ", Duration: " << states[i].duration << "s\n"; // Prints state details.
            this_thread::sleep_for(seconds(states[i].duration)); // Pauses for the duration of the state.
        }
    }

    const char* getType() override { // Overrides the getType function to return the type of controller.
        return "PedestrianController"; // Returns the type as "PedestrianController".
    }
};

// Global array of controllers
TrafficLightController** controllers = nullptr; // Pointer to an array of TrafficLightController pointers.
int controllerCount = 0; // Counter for the number of controllers.

// Add controller
void addController(TrafficLightController* controller) { // Function to add a new controller to the global array.
    TrafficLightController** newControllers = new TrafficLightController*[controllerCount + 1]; // Allocates a new array with one extra slot.
    for (int i = 0; i < controllerCount; ++i) { // Copies existing controllers to the new array.
        newControllers[i] = controllers[i];
    }
    newControllers[controllerCount] = controller; // Adds the new controller to the array.
    delete[] controllers; // Deletes the old array.
    controllers = newControllers; // Updates the global pointer to the new array.
    controllerCount++; // Increments the controller count.
}

// Remove controller by index
void removeController(int index) { // Function to remove a controller by its index.
    if (index < 0 || index >= controllerCount) { // Checks if the index is valid.
        cout << "Invalid index.\n"; // Prints an error message if the index is invalid.
        return; // Exits the function.
    }

    delete controllers[index]; // Deletes the controller at the specified index.

    TrafficLightController** newControllers = new TrafficLightController*[controllerCount - 1]; // Allocates a new array with one less slot.
    int j = 0; // Index for the new array.
    for (int i = 0; i < controllerCount; ++i) { // Copies all controllers except the one being removed.
        if (i != index) {
            newControllers[j++] = controllers[i];
        }
    }

    delete[] controllers; // Deletes the old array.
    controllers = newControllers; // Updates the global pointer to the new array.
    controllerCount--; // Decrements the controller count.
}

int main() { // Main function to simulate the traffic light controllers.
    cout << "=== Traffic Light Controller Simulation ===\n"; // Prints the simulation title.

    addController(new UrbanController()); // Adds an UrbanController to the global array.
    addController(new PedestrianController()); // Adds a PedestrianController to the global array.

    for (int i = 0; i < controllerCount; ++i) { // Loops through all controllers.
        cout << "\nController " << i + 1 << " (" << controllers[i]->getType() << "):\n"; // Prints the controller type.
        controllers[i]->cycleStates(); // Cycles through the states of the controller.
    }

    removeController(0); // Removes the first controller from the global array.

    cout << "\nAfter removing first controller:\n"; // Prints a message indicating a controller was removed.
    for (int i = 0; i < controllerCount; ++i) { // Loops through the remaining controllers.
        cout << "\nController " << i + 1 << " (" << controllers[i]->getType() << "):\n"; // Prints the controller type.
        controllers[i]->cycleStates(); // Cycles through the states of the controller.
    }

    for (int i = 0; i < controllerCount; ++i) { // Loops through all controllers.
        delete controllers[i]; // Deletes each controller.
    }
    delete[] controllers; // Deletes the global array of controllers.

    return 0; // Returns 0 to indicate successful execution.
}
