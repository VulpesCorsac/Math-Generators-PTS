#include <algorithm>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <string>

using namespace std;

long long number_of_variants = 0, min_gen = 5, max_gen = 50, a, b, c, d, k, kk = 3;

void init()
{
    srand(time(NULL));
    cerr << "Generator (c) Aloyan" << endl;
    cerr << "Generating , a+-(b+-x*/c)*/d=k, that can be solved with wrong priority" << endl;
    cerr << "But , a-(b+x*/c)*/d = k is impossible =(" << endl;
    cerr << "Number of variants? " << endl;
    cin >> number_of_variants >> kk;

    freopen("output.txt", "w+", stdout);
    cout << "Гeнeрaтoр примeрoв пo aлгeбрe (c) Алоян" << endl;
    fclose(stdout);

    freopen("variants.txt", "w+", stdout);
    cout << "Гeнeрaтoр примeрoв пo aлгeбрe (c) Алоян" << endl << endl;
    fclose(stdout);
}

void generate(int q)
{
    cerr << "MAKING VARIANT " << q << endl;

    long long a0, b0, c0, d0, k0, i = 0;


    long long key = rand() % 3 + 1;

    if (key == 1) // a + (b + x */ c) */ d = k
    {
        a0 = rand() % (max_gen - min_gen) + min_gen;
        k0 = rand() % (max_gen - min_gen) + a0 + 2*min_gen;
        d0 = rand() % (max_gen - min_gen) + min_gen;
        do
        {
            i++;
            if (i % 1000000 == 0)
                k0 += min_gen;
            b0 = rand() % (max_gen - min_gen) + min_gen;
        }
        while (b0 + 5 >= (k0 - a0));
        c0 = rand() % (max_gen - min_gen) + min_gen;

        c = c0;
        d = d0;
        b = b0 * c;
        k = k0 * a0 * d * c * c;
        a = a0 * d * c * c;

        freopen("variants.txt", "a+", stdout);
        cout << "Вариант № " << q << "    ";

        long long key1 = rand() % kk + 1;

        if (key1 == 1)
        {
            cout << a << "+(" << b << "+x*" << c << ")*" << d << "=" << k << "    , x = " << ((((k - a) / d) - b) / c) << endl;
        }
        if (key1 == 2)
        {
            cout << a << "+(" << b << "+x*" << c << ")/" << d << "=" << k << "    , x = " << ((((k - a) * d) - b) / c) << endl;
        }
        if (key1 == 3)
        {
            cout << a << "+(" << b << "+x/" << c << ")*" << d << "=" << k << "    , x = " << ((((k - a) / d) - b) * c) << endl;
        }
        if (key1 == 4)
        {
            cout << a << "+(" << b << "+x/" << c << ")/" << d << "=" << k << "    , x = " << ((((k - a) * d) - b) * c) << endl;
        }

        fclose(stdout);

        freopen("output.txt", "a+", stdout);
        cout << endl << "Вариант № " << q << "    " << endl;

        cout << a << "+(" << b << "+x*" << c << ")*" << d << "=" << k << "    , x = " << ((((k - a) / d) - b) / c) << endl;
        cout << "Неверный приоритет действий:" << endl;
        cout << "x1 = " << ((k / d - a ) / c - b) << endl;
        cout << "x2 = " << ((k / d - a - b) / c) << endl;
        cout << "x3 = " << (((k - a) / d) / c - b) << endl;

        cout << a << "+(" << b << "+x*" << c << ")/" << d << "=" << k << "    , x = " << ((((k - a) * d) - b) / c) << endl;
        cout << "Неверный приоритет действий:" << endl;
        cout << "x1 = " << ((k * d - a ) / c - b) << endl;
        cout << "x2 = " << ((k * d - a - b) / c) << endl;
        cout << "x3 = " << (((k - a) * d) / c - b) << endl;

        cout << a << "+(" << b << "+x/" << c << ")*" << d << "=" << k << "    , x = " << ((((k - a) / d) - b) * c) << endl;
        cout << "Неверный приоритет действий:" << endl;
        cout << "x1 = " << ((k / d - a ) * c - b) << endl;
        cout << "x2 = " << ((k / d - a - b) * c) << endl;
        cout << "x3 = " << (((k - a) / d) * c - b) << endl;

        cout << a << "+(" << b << "+x/" << c << ")/" << d << "=" << k << "    , x = " << ((((k - a) * d) - b) * c) << endl;
        cout << "Неверный приоритет действий:" << endl;
        cout << "x1 = " << ((k * d - a ) * c - b) << endl;
        cout << "x2 = " << ((k * d - a - b) * c) << endl;
        cout << "x3 = " << (((k - a) * d) * c - b) << endl;

        fclose(stdout);
    }

    if (key == 2) // a + (b - x */ c) */ d = k
    {
        k0 = rand() % (max_gen - min_gen) + min_gen;
        a0 = rand() % (max_gen - min_gen) + k0 + 2*min_gen;
        d0 = rand() % (max_gen - min_gen) + min_gen;
        do
        {
            i++;
            if (i % 1000000 == 0)
                a0 += min_gen;
            b0 = rand() % (max_gen - min_gen) + min_gen;
        }
        while (b0 + 5 >= (a0 - k0));
        c0 = rand() % (max_gen - min_gen) + min_gen;

        c = c0;
        d = d0;
        b = b0 * c;
        k = k0 * d * c * c;
        a = a0 * k0 * d * c * c;

        freopen("variants.txt", "a+", stdout);
        cout << "Вариант № " << q << "    ";

        long long key1 = rand() % kk + 1;

        if (key1 == 1)
        {
            cout << a << "+(" << b << "-x*" << c << ")*" << d << "=" << k << "    , x = " << -((((k - a) / d) - b) / c) << endl;
        }
        if (key1 == 2)
        {
            cout << a << "+(" << b << "-x*" << c << ")/" << d << "=" << k << "    , x = " << -((((k - a) * d) - b) / c) << endl;
        }
        if (key1 == 3)
        {
            cout << a << "+(" << b << "-x/" << c << ")*" << d << "=" << k << "    , x = " << -((((k - a) / d) - b) * c) << endl;
        }
        if (key1 == 4)
        {
            cout << a << "+(" << b << "-x/" << c << ")/" << d << "=" << k << "    , x = " << -((((k - a) * d) - b) * c) << endl;
        }

        fclose(stdout);

        freopen("output.txt", "a+", stdout);
        cout << endl << "Вариант № " << q << "    " << endl;

        cout << a << "+(" << b << "-x*" << c << ")*" << d << "=" << k << "    , x = " << -((((k - a) / d) - b) / c) << endl;
        cout << "Неверный приоритет действий:" << endl;
        cout << "x1 = " << -((k / d - a ) / c - b) << endl;
        cout << "x2 = " << -((k / d - a - b) / c) << endl;
        cout << "x3 = " << -(((k - a) / d) / c - b) << endl;

        cout << a << "+(" << b << "-x*" << c << ")/" << d << "=" << k << "    , x = " << -((((k - a) * d) - b) / c) << endl;
        cout << "Неверный приоритет действий:" << endl;
        cout << "x1 = " << -((k * d - a ) / c - b) << endl;
        cout << "x2 = " << -((k * d - a - b) / c) << endl;
        cout << "x3 = " << -(((k - a) * d) / c - b) << endl;

        cout << a << "+(" << b << "-x/" << c << ")*" << d << "=" << k << "    , x = " << -((((k - a) / d) - b) * c) << endl;
        cout << "Неверный приоритет действий:" << endl;
        cout << "x1 = " << -((k / d - a ) * c - b) << endl;
        cout << "x2 = " << -((k / d - a - b) * c) << endl;
        cout << "x3 = " << -(((k - a) / d) * c - b) << endl;

        cout << a << "+(" << b << "-x/" << c << ")/" << d << "=" << k << "    , x = " << -((((k - a) * d) - b) * c) << endl;
        cout << "Неверный приоритет действий:" << endl;
        cout << "x1 = " << -((k * d - a ) * c - b) << endl;
        cout << "x2 = " << -((k * d - a - b) * c) << endl;
        cout << "x3 = " << -(((k - a) * d) * c - b) << endl;

        fclose(stdout);
    }

    if (key == 3) // a - (b - x */ c) */ d = k
    {
        a0 = rand() % (max_gen - min_gen) + min_gen;
        k0 = rand() % (max_gen - min_gen) + a0 + 2*min_gen;
        d0 = rand() % (max_gen - min_gen) + min_gen;
        do
        {
            i++;
            if (i % 1000000 == 0)
                k0 += min_gen;
            b0 = rand() % (max_gen - min_gen) + min_gen;
        }
        while (b0 + 5 >= (k0 - a0));
        c0 = rand() % (max_gen - min_gen) + min_gen;

        c = c0;
        d = d0;
        b = b0 * c;
        k = k0 * d * a0 * c * c;
        a = a0 * d * c * c;

        freopen("variants.txt", "a+", stdout);
        cout << "Вариант № " << q << "    ";

        long long key1 = rand() % kk + 1;

        if (key1 == 1)
        {
            cout << a << "-(" << b << "-x*" << c << ")*" << d << "=" << k << "    , x = " << ((((k - a) / d) + b) / c) << endl;
        }
        if (key1 == 2)
        {
            cout << a << "-(" << b << "-x*" << c << ")/" << d << "=" << k << "    , x = " << ((((k - a) * d) + b) / c) << endl;
        }
        if (key1 == 3)
        {
            cout << a << "-(" << b << "-x/" << c << ")*" << d << "=" << k << "    , x = " << ((((k - a) / d) + b) * c) << endl;
        }
        if (key1 == 4)
        {
            cout << a << "-(" << b << "-x/" << c << ")/" << d << "=" << k << "    , x = " << ((((k - a) * d) + b) * c) << endl;
        }

        fclose(stdout);

        freopen("output.txt", "a+", stdout);
        cout << endl << "Вариант № " << q << "    " << endl;

        cout << a << "-(" << b << "-x*" << c << ")*" << d << "=" << k << "    , x = " << ((((k - a) / d) + b) / c) << endl;
        cout << "Неверный приоритет действий:" << endl;
        cout << "x1 = " << (k / d - a ) / c + b << endl;
        cout << "x2 = " << (k / d - a + b) / c << endl;
        cout << "x3 = " << ((k - a) / d) / c + b << endl;

        cout << a << "-(" << b << "-x*" << c << ")/" << d << "=" << k << "    , x = " << ((((k - a) * d) + b) / c) << endl;
        cout << "Неверный приоритет действий:" << endl;
        cout << "x1 = " << (k * d - a ) / c + b << endl;
        cout << "x2 = " << (k * d - a - b) / c << endl;
        cout << "x3 = " << ((k - a) * d) / c + b << endl;

        cout << a << "-(" << b << "-x/" << c << ")*" << d << "=" << k << "    , x = " << ((((k - a) / d) + b) * c) << endl;
        cout << "Неверный приоритет действий:" << endl;
        cout << "x1 = " << (k / d - a ) * c + b << endl;
        cout << "x2 = " << (k / d - a + b) * c << endl;
        cout << "x3 = " << ((k - a) / d) * c + b << endl;

        cout << a << "-(" << b << "-x/" << c << ")/" << d << "=" << k << "    , x = " << ((((k - a) * d) + b) * c) << endl;
        cout << "Неверный приоритет действий:" << endl;
        cout << "x1 = " << (k * d - a ) * c + b << endl;
        cout << "x2 = " << (k * d - a + b) * c << endl;
        cout << "x3 = " << ((k - a) * d) * c + b << endl;

        fclose(stdout);
    }

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
