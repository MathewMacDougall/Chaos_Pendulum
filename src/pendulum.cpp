#include "pendulum.hpp"
#include <cmath>
#include <stdlib.h>

Pendulum::Pendulum(double length, double angle, double mass, Pendulum &parent) {
    this->length = length;
    this->angle = angle;
    this->mass = mass;
    parentPtr = &parent;
    base = parentPtr->getBobPosition();
    bob = base.add(Point(length * cos(angle), length * sin(angle)));
}

Pendulum::Pendulum(double length, double angle, double mass, Point base) {
    this->length = length;
    this->angle = angle;
    this->mass = mass;
    parentPtr = NULL; //There is no parent for this pendulum, so parentPtr points to nothing
    this->base = base;
    bob = base.add(Point(length * cos(angle), length * sin(angle)));
}

// TODO: add function/destructor to delete pendulums (should delete all children too, not just remove pointer)

void Pendulum::attachTo(Pendulum &newParent) {
    if(isAttachedToPendulum()) {
        if(getParentPendulum() != &newParent) {
            getParentPendulum()->detachChild(this);
            parentPtr = &newParent;
            getParentPendulum()->attachChild(this);
            update(0.0);
        } else {
            // This pendulum is already attached to this parent. Do nothing
        }
    } else {
        parentPtr = &newParent;
        getParentPendulum()->attachChild(this);
        update(0.0);
    }
}

void Pendulum::attachTo(Point newBase) {
    if(isAttachedToPendulum()) {
        getParentPendulum()->detachChild(this);
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

void Pendulum::attachChild(Pendulum *newChild) {

}

void Pendulum::detachChild(Pendulum *child) {


}

void Pendulum::update(double delta_t) {
    // TODO: do basic physics simulation with recursive updates

    if(isAttachedToPendulum())
        base = parentPtr->getBobPosition();

    bob = base.add(Point(length * cos(angle), length * sin(angle)));
}


std::vector<Pendulum*> Pendulum::getChildPendulums() const {
    return this->childPendulums;
}

bool Pendulum::isAttachedToPendulum() const {
    return this->parentPtr != NULL;
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

double Pendulum::getAngle() const {
    return this->angle;
}

double Pendulum::getMass() const {
    return this->mass;
}

bool Pendulum::operator==(const Pendulum &other) const {
    return getMass() == other.getMass() && getLength() == other.getLength()
            && getParentPendulum() == other.getParentPendulum()
            && getChildPendulums() == other.getChildPendulums()
            && getBobPosition() == other.getBobPosition();
}
