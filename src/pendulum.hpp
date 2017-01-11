#ifndef PENDULUM_H
#define PENDULUM_H

#include <vector>
#include "util/point.hpp"


class Pendulum {

private:
    Pendulum *parentPtr;
    // TODO: make this an unordered set or something with faster access
    std::vector<Pendulum*> childPendulums;
    Point base;
    Point bob;
    double length;
    double angle;
    double mass;

    // TODO: track angular velocity and acceleration

    /**
     * Detached the child from this pendulum
     *
     * @param child - the pendulum to detach
     */
    void detachChild(Pendulum &child);

public:
    static constexpr double ANGLE_MODIFIER = 3 * M_PI_2; // Apply to angles to adjust from being relative to "straight down" (3pi/2 rad on the xy-plane)
    // to being relative to the positive x-axis on the xy-plane (o rad)

    /**
     * Constructs a new Pendulum object that anchors to another pendulum
     *
     * @param length - the length of the arm of the pendulum
     * @param angle - the initial angle of the pendulum
     * @param mass - the mass of the pendulum weight
     * @param parent - the pendulum this pendulum is attached to
     */
    Pendulum(double length, double angle, double mass, Pendulum &parent);

    /**
     * Constructs a new Pendulum object that anchors to a fixed point
     *
     * @param length
     * @param angle
     * @param mass
     * @param base
     */
    Pendulum(double length, double angle, double mass, Point base);

    /**
     * Attaches this pendulum as the child to another pendulum
     * Attaches the base of this Pendulum to the bob of the new parent
     *
     * @param newParent - the Pendulum to attach to
     */
    void attachTo(Pendulum &newParent);

    /**
     * Attaches the base of this pendulum to a fixed point
     *
     * @param newParent - the Pendulum to attach to
     */
    void attachTo(const Point base);

    /**
     * Attaches newChild as a Child to this
     * Attaches the base of newChild to the bob of this
     *
     * @param newChild - the pendulum to attach
     */
    void attachChild(Pendulum &newChild);

    /**
     * Updates the position of this Pendulum and all children
     * The new position is based on the current position simluated
     * delta_t seconds forward in time
     *
     * @param delta_t - the change in time to update
     */
    Point update(const double delta_t);

    /**
     * Returns pointers to all the child pendulums of this
     *
     * @return pointers to all child pendulums of this
     */
    const std::vector<Pendulum*>& getChildPendulums();

    /**
     * Checks if this pendulum is attached to a parent pendulum
     *
     * @return true if the base of this pendulum is attached to a parent pendulum, and
     *         false otherwise (eg. if it's attached to a fixed point)
     */
    bool isAttachedToPendulum() const;

    /**
     * Returns the pointer to the parent pendulum of this
     *
     * @return Returns the pointer ot the parent pendulum of this.
     *         Will return 0 if this pendulum is attached to a fixed point
     */
    Pendulum* getParentPendulum() const;

    /**
     * Returns the position of the base of this pendulum
     *
     * @return the position of the bse of this pendulum
     */
    Point getBasePosition() const;

    /**
     * Returns the position of the bob of this pendulum
     *
     * @return the position of the bob of this pendulum
     */
    Point getBobPosition() const;

    /**
     * Returns the length of the arm of this pendulum
     *
     * @return the length of the arm of this pendulum
     */
    double getLength() const;

    /**
     * Returns a value 0 <= angle < 2pi representing the angle between the pendulum
     * arm and the positive x direction. (The angle of the arm relative tothe positive
     * x-axis as see on a 2D xy plane)
     *
     * @return a value 0 <= angle < 2pi representing the angle of the pendulum arm
     */
    double getAngle() const;

    /**
     * Returns the mass of the pendulum
     *
     * @return the mass of the pendulum
     */
    double getMass() const;

    /**
     * Compares this pendulum and other for equality
     * Returns true if this equals other
     *
     * @param other - the other pendulum to compare to
     * @return true if and only if this equals other
     */
    bool operator==(const Pendulum &other) const;

    /**
     * Compares this pendulum and other for equality
     * Returns true if this is not equal to other
     *
     * @param other - the other pendulum to compare to
     * @return true if and only if this is not equal to other
     */
    bool operator!=(const Pendulum &other) const;

};

#endif