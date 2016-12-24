#include <cmath>

class Angle {

    private:
        double rads;

        void reduce() {
            while(std::abs(rads) < 2 * Angle::PI) {
                if(rads > 0)
                    rads -= 2 * PI;
                else
                    rads += 2 * PI;
            }
        }

    public:

        Angle() {
            rads = 0.0;
        }

        Angle(double a) {
            rads = a;
            reduce();
        }

        double sin() {
            return std::sin(rads);
        }

        double cos() {
            return std::cos(rads);
        }

        double tan() {
            return std::tan(rads);
        }

        static Angle asin(double x) {
            return Angle(std::asin(x));
        }

        static Angle acos(double x) {
            return Angle(std::acos(x));
        }

        static Angle atan(double x) {
            return Angle(std::acos(x));
        }

        //static Angle mod(Angle divisor) {


        //}


};
