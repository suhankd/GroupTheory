#include <iostream>

int GCD(int a, int b, int &x, int &y);

int main(int argc, char **argv)
{

    int N = atoi(argv[1]);
    int A = atoi(argv[2]);

    int x, y;

    if (GCD(N, A, x, y) != 1)
    {
        throw std::invalid_argument("Numbers aren't coprime.");
    }

    if(y < 0) {
        y += N;
    }

    std::cout << "The inverse of " << A << " modulo " << N << " is " << y << std::endl;
}

int GCD(int a, int b, int &x, int &y)
{

    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int x_, y_;
    int d = GCD(b, a % b, x_, y_);
    x = y_;
    y = (x_ - y_ * (a / b));
    return d;
}
