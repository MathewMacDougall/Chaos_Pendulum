#include <gtest/gtest.h>
#include "../src/util/point.hpp"
#include "../src/pendulum.hpp"

TEST(PendulumTest, TestAbsoluteValueObservers) {
    Point anchor;
    Pendulum p1 = Pendulum(1, -M_PI_4, 4, anchor);
    Pendulum p2 = Pendulum(2, M_PI_2, 3, p1);
    Pendulum p3 = Pendulum(3, 0, 2.5, p2);
    p1.update(0.0);

    //Observing p1 and absolute positions
    ASSERT_EQ(p1.getMass(), 4);
    ASSERT_EQ(p1.getLength(), 1);
    ASSERT_EQ(p1.getAngle(), -M_PI_4);
    ASSERT_EQ(p1.getBasePosition(), anchor);
    ASSERT_EQ(p1.getBobPosition(), Point(-sqrt(0.5), -sqrt(0.5)));

    //Observing p2 and absolute positions
    ASSERT_EQ(p2.getMass(), 3);
    ASSERT_EQ(p2.getLength(), 2);
    ASSERT_EQ(p2.getAngle(), M_PI_2);
    ASSERT_EQ(p2.getBasePosition(), Point(-sqrt(0.5), -sqrt(0.5)));
    ASSERT_EQ(p2.getBobPosition(), Point(2 - sqrt(0.5), -sqrt(0.5)));

    //Observing p3 and absolute positions
    ASSERT_EQ(p3.getMass(), 2.5);
    ASSERT_EQ(p3.getLength(), 3);
    ASSERT_EQ(p3.getAngle(), 0);
    ASSERT_EQ(p3.getBasePosition(), Point(2 - sqrt(0.5), -sqrt(0.5)));
    ASSERT_EQ(p3.getBobPosition(), Point(2 - sqrt(0.5), -sqrt(0.5) - 3));
}

TEST(PendulumTest, TestRelativeObservers) {
    Point anchor;
    Pendulum p1 = Pendulum(1, -M_PI_4, 4, anchor);
    Pendulum p2 = Pendulum(2, M_PI_2, 3, p1);
    Pendulum p3 = Pendulum(3, 0, 2.5, p2);
    p1.update(0.0);

    //Observing bob and base positions in terms of parent and child positions
    ASSERT_EQ(p1.getBobPosition(), p2.getBasePosition());
    ASSERT_EQ(p2.getBobPosition(), p3.getBasePosition());
}

TEST(PendulumTest, TestChildParentRelationships) {
    Point anchor;
    Pendulum p1 = Pendulum(1, -M_PI_4, 4, anchor);
    Pendulum p2 = Pendulum(2, M_PI_2, 3, p1);
    Pendulum p3 = Pendulum(3, 0, 2.5, p2);
    p1.update(0.0);

    //Observing parent and child attachments
    ASSERT_EQ(*p2.getParentPendulum(), p1);
    ASSERT_EQ(*p3.getParentPendulum(), p2);
    ASSERT_FALSE(p1.isAttachedToPendulum());
    ASSERT_TRUE(p2.isAttachedToPendulum());
    ASSERT_TRUE(p3.isAttachedToPendulum());
    ASSERT_TRUE(p1.hasChild(&p2));
    ASSERT_TRUE(p2.hasChild(&p3));
}

TEST(PendulumTest, TestChangingParents) {
    Point anchor;
    Pendulum p1 = Pendulum(1, -M_PI_4, 4, anchor);
    Pendulum p2 = Pendulum(2, M_PI_2, 3, p1);
    Pendulum p3 = Pendulum(3, 0, 2.5, p2);
    p1.update(0.0);

    ASSERT_TRUE(p1.getParentPendulum() == NULL);
    ASSERT_EQ(p2.getParentPendulum(), &p1);
    ASSERT_EQ(p3.getParentPendulum(), &p2);
    ASSERT_TRUE(p1.hasChild(&p2));
    ASSERT_TRUE(p2.hasChild(&p3));

    p3.attachTo(p1);
    ASSERT_TRUE(p1.getParentPendulum() == NULL);
    ASSERT_EQ(p2.getParentPendulum(), &p1);
    ASSERT_EQ(p3.getParentPendulum(), &p1);
    ASSERT_TRUE(p1.hasChild(&p2));
    ASSERT_TRUE(p1.hasChild(&p3));
    ASSERT_EQ(p2.getNumChildren(), 0);
    ASSERT_EQ(p1.getNumChildren(), 2);

    p2.attachTo(anchor);
    ASSERT_TRUE(p1.getParentPendulum() == NULL);
    ASSERT_TRUE(p2.getParentPendulum() == NULL);
    ASSERT_EQ(p3.getParentPendulum(), &p1);
    ASSERT_TRUE(p1.hasChild(&p3));
    ASSERT_EQ(p2.getNumChildren(), 0);
    ASSERT_EQ(p1.getNumChildren(), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}