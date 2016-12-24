#ifndef PENDULUM_H
#define PENDULUM_H

class Pendulum {

    public:
        // Crea tes a new pendulum object
        Pendulum(Point origin, Point position, double mass);

        // Updates the position of the pendulum
        void updatePos();





        // Returns a Point representing the origin of the pendulum
        Point origin();

        // Returns a Point representing the position of the pendulum
        Point pos();

};

#endif
