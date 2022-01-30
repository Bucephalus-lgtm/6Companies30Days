// https://leetcode.com/problems/generate-random-point-in-a-circle

class Solution {
    double R, X, Y;
public:
    const double PI = 3.14159265358979323846264;
    double rad, xc, yc;
    Solution(double radius, double x_center, double y_center) : R(radius), X(x_center), Y(y_center) {
        srand(time(0));
    }
    
    double random(){
        return (double)rand() / RAND_MAX; 
    }
    
    vector<double> randPoint() {
        vector<double> randomPoint(2);
        double len = sqrt(random()) * R;
        double deg = 2 * M_PI * random();
        randomPoint[0] = X + len * cos(deg);
        randomPoint[1] = Y + len * sin(deg);
        return randomPoint;
    }
};