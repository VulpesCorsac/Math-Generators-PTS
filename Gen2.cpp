#include <algorithm>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <string>

using namespace std;

int number_of_variants = 0, min_gen = 10, max_gen = 100, a, b, c;

void init()
{
    srand(time(NULL));
    cerr << "Generator (c) Aloyan" << endl;
    cerr << "Generating a+- b*/x = c, can be solved with wrong priority" << endl;
    cerr << "Number of variants? " << endl;
    cin >> number_of_variants;

    freopen("output.txt", "w+", stdout);
    cout << "Гeнeрaтoр примeрoв пo aлгeбрe (c) Алоян" << endl;
    fclose(stdout);

    freopen("variants.txt", "w+", stdout);
    cout << "Гeнeрaтoр примeрoв пo aлгeбрe (c) Алоян" << endl << endl;
    fclose(stdout);
}

void generate(int q)
{
    freopen("output.txt", "a+", stdout);
    cout << endl << "Вариант № " << q << " " << endl;
    cerr << "MAKING VARIANT " << q << endl;

    a = b = c = 1;
    int v = rand() % 2, a0 = 1, b0 = 1, c0 = 1;

    if (v)
    {
        b0 = rand() % (max_gen - min_gen) + min_gen;
        a0 = rand() % (max_gen - min_gen) + min_gen;
        c0 = rand() % (max_gen - min_gen) + min_gen + a0 * b0;

        b = b0;
        a = a0 * b;
        c = c0 * b;

        cout << "Верный порядок" << endl;
        cout << a << "+x*" << b << "=" << c << "       x = " << (c - a) / b << endl;
        cout << a << "+x/" << b << "=" << c << "       x = " << (c - a) * b << endl;
        cout << "Неверный порядок" << endl;
        cout << a << "+x*" << b << "=" << c << "       x = " << (c / b - a) << endl;
        cout << a << "+x/" << b << "=" << c << "       x = " << (c * b - a) << endl;

        fclose(stdout);
        freopen("variants.txt", "a+", stdout);

        cout << "Вариант № " << q << " ";
        int vv = rand() % 2;
        if (vv)
            cout << a << "+x*" << b << "=" << c << endl;
        else
            cout << a << "+x/" << b << "=" << c << endl;
    }
    else
    {
        b0 = rand() % (max_gen - min_gen) + min_gen;
        c0 = rand() % (max_gen - min_gen) + min_gen;
        a0 = rand() % (max_gen - min_gen) + min_gen + c0 * b0;

        b = b0;
        a = a0 * b;
        c = c0 * b;

        cout << "Верный порядок" << endl;
        cout << a << "-x*" << b << "=" << c << "       x = " << (a - c) / b << endl;
        cout << a << "-x/" << b << "=" << c << "       x = " << (a - c) * b << endl;
        cout << "Неверный порядок" << endl;
        cout << a << "-x*" << b << "=" << c << "       x = " << (a - c / b) << endl;
        cout << a << "-x/" << b << "=" << c << "       x = " << (a - c * b) << endl;

        fclose(stdout);
        freopen("variants.txt", "a+", stdout);

        cout << "Вариант № " << q << " ";
        int vv = rand() % 2;
        if (vv)
            cout << a << "-x*" << b << "=" << c << endl;
        else
            cout << a << "-x/" << b << "=" << c << endl;
    }

    fclose(stdout);
}

int main()
{
    init();
    cerr << "INITED" << endl;
    for (int i = 0; i < number_of_variants; i++)
        generate(i + 1);
    cerr << "ALL DONE - CLOSING";

    return 0;
}
