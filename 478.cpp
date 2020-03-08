#define PI 3.14159265

class Solution {
public:
    double _radius;
    double _x_center;
    double _y_center;

    Solution(double radius, double x_center, double y_center) {
        _radius = radius;
        _x_center = x_center;
        _y_center = y_center;
    }
    
    vector<double> randPoint() {
        double angle = ((double)rand() / RAND_MAX) * 2 * PI;
        double r = sqrt(((double)rand() / RAND_MAX)) * _radius;
        double x_delta = r * sin(angle), y_delta = r * cos(angle);
        return {_x_center + x_delta, _y_center + y_delta};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */