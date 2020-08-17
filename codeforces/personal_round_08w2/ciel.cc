#include <iostream>
#include <algorithm>


using namespace std;


int main() {
    int r, g, b;
    cin >> r >> g >> b;

    int red = r / 3;
    int green = g / 3;
    int blue = b / 3;

    int color_sum = red + blue + green;
    int result = color_sum + min({r % 3, b % 3, g % 3});
    if (red)
        result = max(result, color_sum-1 + min({3 + r % 3, b % 3, g % 3}));
    if (blue)
        result = max(result, color_sum-1 + min({r % 3, 3 + b % 3, g % 3}));
    if (green)
        result = max(result, color_sum-1 + min({r % 3, b % 3, 3 + g % 3}));
    cout << result << endl;
}
