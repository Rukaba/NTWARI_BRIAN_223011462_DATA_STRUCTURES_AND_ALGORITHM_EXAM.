
README - Traffic Light Controller Simulation Project

Assigned Task:
The assigned task was to simulate traffic light systems using object-oriented programming in C++. The simulation must demonstrate the use of polymorphism, pointer arithmetic, and dynamic memory allocation. Each controller should maintain a dynamic array of State structs, and the simulation must handle multiple types of controllers such as Urban and Pedestrian traffic lights. The implementation must allow controllers to be added or removed dynamically and cycle through their states using polymorphic behavior.

How It Was Completed:
1. Defined a struct `State` with `char color[10]` and `int duration` to represent each traffic light state.
2. Created an abstract base class `TrafficLightController` with a pure virtual function `cycleStates()` and a dynamic array of `State` elements.
3. Implemented two derived classes:
   - `UrbanController`: Cycles through Red, Green, and Yellow states.
   - `PedestrianController`: Cycles through Walk and Don't Walk states.
4. Used pointer arithmetic to access and update elements in the dynamic `State*` arrays.
5. Created dynamic array `TrafficLightController** controllers` to manage multiple controllers.
6. Implemented `addController()` and `removeController()` to dynamically manage the controller array.
7. Added real-time simulation using `std::this_thread::sleep_for()` so that each light state holds for its duration.
8. Included all source code with comments detailing the purpose of each section.

Annotated Code:
Please refer to the file `traffic_light_controller.cpp` which includes line-by-line comments explaining:
- Class structure and inheritance
- Dynamic memory handling
- Pointer operations for `State*`
- Polymorphism via `cycleStates()` execution
- Real-time simulation using sleep functions






