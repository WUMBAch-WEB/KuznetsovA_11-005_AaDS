#include <iostream>
#include "cmath"

using namespace std;

void sum()
{
    cout << "Enter the amount of numbers to sum: " << endl;
    int n = 0;
    cin >> n;
    int sum = 0;
    cout << "Now enter the numbers: " << endl;
    for (int i = 0; i < n; ++i)
    {
        int a = 0;
        cin >> a;
        sum += a;
    }
    cout << sum << endl;
}
void dec()
{
    double  a, b, c, x1, x2;
    cin >> a >> b >> c;
    double dec1;
    dec1 = b * b - 4 * a * c;
    if (dec1 < 0)
    {
        cout << "No roots" << endl;
    }
    if (dec1 == 0)
    {
        x1 = (-b + 0) / ( 2 * a);
        cout << "Root: " << x1 << endl;
    }
    if (dec1 > 0)
    {
        x1 = ((-b + sqrt(dec1)) / (2 * a));
        x2 = ((-b - sqrt(dec1)) / (2 * a));
        cout << "Roots: " << x1 << x2 << endl;
    }
}
void log()
{
    int f = 1;
    double x;
    cout << "Enter X: " << endl;
    cin >> x;
    int p = 0;
    while (f < x)
    {
        f = f * 2;
        p += 1;
    }
    p -= 1;
    cout << p << endl;
}
int power (int x, unsigned p)
{
    int f = x;
    for (int i = 1; i < p ; ++i)
    {
        f = f * x;
    }
    return f;
}
int main() {
    cout << "Make the choice: " << endl;
    cout << "Enter '1' for run first task" << endl;
    cout << "Enter '2' for run second task" << endl;
    cout << "Enter '3' for run third task" << endl;
    cout << "Enter '4' for run fourth task" << endl;
    cout << "Enter '0' for exit" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
        case 0:
            return 0;
        case 1:
            sum();
            main();
            break;
        case 2:
            dec();
            main();
            break;
        case 3:
            log();
            main();
            break;
        case 4:
            int x;
            int p;
            cout << "Enter X and P";
            cin >> x >> p;
            cout << power(x, p) << endl;
            main();
            break;
    }
}