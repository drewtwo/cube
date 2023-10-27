int nextColor(int color) { return (color + 1) % 10; }
int nextPrimaryColor(int color) { return (color + 1) % 3; }

int roundClosest(int numerator, int denominator)
{
    numerator = (numerator << 1) / denominator;
    int output = (numerator >> 1) + (numerator % 2);
    return output;
}

void swapint(int &one, int &two)
{
    one = one ^ two;
    two = one ^ two;
    one = one ^ two;
}