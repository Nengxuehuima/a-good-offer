#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double x;
    int n;
    
    while (std::cin >> x >> n) {
        double s = 0.0;
        for (int i = 0; i < n; i++) {
            s += x;
            x = sqrt(x);
        }
        std::cout << std::fixed << std::setprecision(2) << s << std::endl;
    }
    return 0;
}