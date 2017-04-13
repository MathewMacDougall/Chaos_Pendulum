#ifndef PENDULUM_H
#define PENDULUM_H

#include <vector>
#include "util/point.hpp"
#include <cmath>

class Pendulum {

private:
    Pendulum *parentPtr;
    // TODO: make childPendulums an unordered set or something with faster access
    std::vector<Pendulum*> childPendulums;
    Point base;
    Point bob;
    double length;
    double angle;
    double mass;
    double angularAccel;// Positive is counter-clockwise
    double angularVel;// Positive is counter-clockwise
    Point centripetalForce; // positive defined as "away" from base of pendulum
    Point tangentForce;
    Point netForce;
    double torgue;
    double rotationalInertia;

    void updateForces(const double delta_t);
    void updatePositions(const double delta_t);

public:
    static constexpr double ANGLE_MODIFIER = 3 * M_PI_2; // Apply to angles to adjust from being relative to "straight down" (3pi/2 rad on the xy-plane)
                                                         // to being relative to the positive x-axis on the xy-plane (o rad)

    /**
     * Constructs a new Pendulum object that anchors to another pendulum. The parent
     * Pendulum must already exist and not be NULL
     *
     * @param length - the length of the arm of the pendulum
     * @param angle - the initial angle of the pendulum
     * @param mass - the mass of the pendulum weight
     * @param parent - the pendulum this Pendulum is attached to - must already exist and not be NULL
     */
    Pendulum(double length, double angle, double mass, Pendulum &parent);

    /**
     * Constructs a new Pendulum object that anchors to a fixed point
     *
     * @param length - the length of the arm of the pendulum
     * @param angle - the initial angle of the pendulum
     * @param mass - the mass of the pendulum weight
     * @param base - the Point that this Pendulum is attached to. Must not be null
     */
    Pendulum(double length, double angle, double mass, Point base);

    /**
     * Destructor for the Pendulum object. Calls the destructor of all child Pendulums
     * (if applicable) and then deletes itself
     */
    ~Pendulum();

    /**
     * Attaches this pendulum as the child to another pendulum,
     * attaching the base of this Pendulum to the bob of the new parent.
     * If this Pendulum is already attached to this parent, does nothing
     *
     * @param newParent - the Pendulum to attach to
     */
    void attachTo(Pendulum &newParent);

    /**
     * Attaches the base of this pendulum to a fixed point. If this Pendulum is
     * already attached to this Point, does nothing
     *
     * @param base - the Point to attach to
     */
    void attachTo(const Point base);

    /**
     * Attaches newChild as a Child to this Pendulum,
     * attachimng the base of newChild to the bob of this
     *
     * @param newChild - the pendulum to attach
     */
    void attachChild(Pendulum &newChild);

    /**
     * Detach the child from this pendulum
     *
     * @param child - the pendulum to detach
     */
    void detachChild(Pendulum &child);

    /**
     * Updates the position of this Pendulum and all children
     * The new position is based on the current position simulated
     * delta_t seconds forward in time
     *
     * @param delta_t - the change in time to update
     */
    void update(const double delta_t);

    /**
     * Returns the force component tangent to the arm of this Pendulum
     *
     * @param force - the force applied to the pendulum
     * @return the tangent force to the arm of this Pendulum
     */
    Point getTangentForce(Point force);

    /**
     * Checks if this pendulum is attached to a parent pendulum
     *
     * @return true if the base of this pendulum is attached to a parent pendulum, and
     *         false otherwise (eg. if it's attached to a fixed point)
     */
    bool isAttachedToPendulum() const;

    /**
     * Checks is this Pendulum has child attached to it
     *
     * @param child - a pointer to the child to be checked
     * @return true if this child is contained in the list of children of this Pendulu,
     *         and false otherwise
     */
    bool hasChild(Pendulum *child) const;

    /**
     * Returns the number of children attached to this Pendulum
     *
     * @return the number of Children attached to this Pendulum
     */
    long getNumChildren() const;

    /**
     * Returns the pointer to the parent pendulum of this
     *
     * @return Returns the pointer ot the parent pendulum of this.
     *         Will returns a NULL pointer if this pendulum is attached to a fixed point
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
     * Returns the total length of the longest path from this pendulum
     * to a "leaf" pendulum that is a child of this pendulum.
     * For example if the pendulums were thought of as a tree, this
     * would return the height of this node/pendulum
     *
     * @return the total length of the longest path from this pendulum to a child "leaf" pendulum
     */
    double getMaxTotalLength() const;

    /**
     * Returns a value 0 <= angle < 2pi representing the angle between the pendulum
     * arm and the negative y direction ("down"). (The angle of the arm relative to the
     * negative y-axis as see on a 2D x-y plane)
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
