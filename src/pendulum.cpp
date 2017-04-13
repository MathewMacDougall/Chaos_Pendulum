#include <algorithm>
#include "pendulum.hpp"
#include "util/physics.hpp"
#include <iostream>

Pendulum::Pendulum(double length, double angle, double mass, Pendulum &parent) {
    this->length = length;
    this->angle = angle;
    this->mass = mass;
    parentPtr = &parent;
    parentPtr->attachChild(*this);
    base = parentPtr->getBobPosition();
    bob = base.add(Point(length * cos(angle + ANGLE_MODIFIER), length * sin(angle + ANGLE_MODIFIER)));
    angularAccel = 0.0;
    angularVel = 0.0;
    rotationalInertia = mass * length * length;
}

Pendulum::Pendulum(double length, double angle, double mass, Point base) {
    this->length = length;
    this->angle = angle;
    this->mass = mass;
    parentPtr = NULL; //There is no parent for this pendulum, so parentPtr points to nothing
    this->base = base;
    bob = base.add(Point(length * cos(angle + ANGLE_MODIFIER), length * sin(angle + ANGLE_MODIFIER)));
    angularAccel = 0.0;
    angularVel = 0.0;
    rotationalInertia = mass * length * length;
}

Pendulum::~Pendulum() {
    // TODO: Create destructor - this code causes SIGABRT in tests?
    //for(Pendulum* child : childPendulums) {
    //    delete(child);
    //}
}

void Pendulum::attachTo(Pendulum &newParent) {
    if(isAttachedToPendulum()) {
        if(*getParentPendulum() != newParent) {
            getParentPendulum()->detachChild(*this);
            parentPtr = &newParent;
            getParentPendulum()->attachChild(*this);
            update(0.0);
        } else {
            // This pendulum is already attached to this parent. Do nothing
        }
    } else {
        parentPtr = &newParent;
        getParentPendulum()->attachChild(*this);
        update(0.0);
    }
}

void Pendulum::attachTo(const Point newBase) {
    if(isAttachedToPendulum()) {
        getParentPendulum()->detachChild(*this);
        parentPtr = NULL;
        base = newBase;
        update(0.0);
    } else {
        if(newBase != base) {
            base = newBase;
            update(0.0);
        } else {
            // This pendulum is already attached to this point. Do nothing
        }
    }
}

void Pendulum::attachChild(Pendulum &newChild) {
    if(hasChild(&newChild)) {
        // This child is already attached. Do nothing
    } else {
        childPendulums.push_back(&newChild);
        newChild.attachTo(*this);
    }
}

void Pendulum::detachChild(Pendulum &child) {
    const std::vector<Pendulum*>::iterator it = std::find(childPendulums.begin(), childPendulums.end(), &child);
    if(it != childPendulums.end()) {
        childPendulums.erase(it);
    }
}

// TODO: add tests for update()?
void Pendulum::update(const double delta_t) {
    updateForces(delta_t); //updates recursively (ish) from tail to rot
    updatePositions(delta_t); // updates from root to tail
}

Point Pendulum::updateForces(const double delta_t) {
    netForce = Point();

    // adds forces of all child pendulums to net force of this pendulum
    // forces from child pendulums only act upon the vector of the child pendulum's arm
    for(unsigned int i = 0; i < childPendulums.size(); i++) {
        netForce = netForce.add(childPendulums[i]->updateForces(delta_t)
                                .projectOnto(childPendulums[i]->getBobPosition().sub(childPendulums[i]->getBasePosition())));

        //std::cout << "in updating child: " << getMass() << ": " << netForce.x() << ", " << netForce.y() << std::endl;
    }

    Point forceGrav = Point(0, mass * -Physics::ACCEL_G); // force vector pointing "down"  

    // add all forces to net force
    netForce = netForce.add(forceGrav);
    std::cout << getMass() << ": " << netForce.x() << ", " << netForce.y() << std::endl;

    // calculate torgue and use to get angular accel
    Point torgueForce = getTangentForce(forceGrav.add(netForce));

    if(torgueForce.isSameDirectionAs(bob.sub(base).perp(), M_PI / 16.0))
        torgue = fabs(torgueForce.len()) * length;
    else
        torgue = -fabs(torgueForce.len()) * length;

    angularAccel = torgue / rotationalInertia;

    /* perp() always returns pointing "counterclockwise", so if the tangent force is the same direction
     * as it, is the force (and therefore accel) will be in the counterclockwise direction and therefore positive.
     * Vice-versa for negative
     */
//    if(tangentForce.isSameDirectionAs(bob.sub(base).perp(), M_PI / 16.0))
//        angularAccel = tangentForce.len() / mass / length;
//    else
//        angularAccel = -tangentForce.len() / mass / length;

    angularVel += angularAccel * delta_t;

    return netForce;
}

void Pendulum::updatePositions(const double delta_t) {
    angle += angularVel * delta_t;

    if(isAttachedToPendulum())
        base = parentPtr->getBobPosition();

    bob = base.add(Point(length * cos(angle + ANGLE_MODIFIER), length * sin(angle + ANGLE_MODIFIER)));

    for(unsigned int i = 0; i < childPendulums.size(); i++) {
        childPendulums[i]->updatePositions(delta_t);
    }
}

// TODO: add tests
Point Pendulum::getTangentForce(Point force) {
    return force.projectOnto(bob.sub(base).perp());
}

bool Pendulum::isAttachedToPendulum() const {
    return this->parentPtr != NULL;
}

bool Pendulum::hasChild(Pendulum *child) const {
    return std::find(childPendulums.begin(), childPendulums.end(), child) != childPendulums.end();
}

long Pendulum::getNumChildren() const {
    return this->childPendulums.size();
}

Pendulum* Pendulum::getParentPendulum() const {
    return this->parentPtr;
}

Point Pendulum::getBasePosition() const {
    return this->base;
}

Point Pendulum::getBobPosition() const {
    return this->bob;
}

double Pendulum::getLength() const {
    return this->length;
}

double Pendulum::getMaxTotalLength() const {
    double longest = 0.0;
    for(unsigned int i = 0; i < childPendulums.size(); i++) {
        double length = childPendulums[i]->getMaxTotalLength();
        if(length > longest) {
            longest = length;
        }
    }

    return this->getLength() + longest;
}

Point Pendulum::getNetForce() const {
    return this->netForce;
}

double Pendulum::getAngle() const {
    return this->angle;
}

double Pendulum::getMass() const {
    return this->mass;
}

bool Pendulum::operator==(const Pendulum &other) const {
    return getMass() == other.getMass() && getLength() == other.getLength()
            && getParentPendulum() == other.getParentPendulum()
            && childPendulums == other.childPendulums
            && getBobPosition() == other.getBobPosition();
}

bool Pendulum::operator!=(const Pendulum &other) const {
    return !(*this == other);
}
