#include <algorithm>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <string>

using namespace std;

int number_of_variants, min_number = 10, max_number = 100, max_gen = 30, maxx = 10000000;
int a, b, c, d, k;

void init();
void run();
void print(int a);
void make_random_variants();
bool check();

int main()
{
    init();
    cerr << "INITED" << endl;

    for (int i = 0; i < number_of_variants; i++)
    {
        cerr << "MAKING VARIANT " << i + 1 << endl;
        run();
        print(i + 1);
    }

    cerr << "MAKIN RANOM VARIANT FOR TEST" << endl;
    make_random_variants();

    cerr << "ALL DONE - CLOSING";

    return 0;
}

void init()
{
    cerr << "Generator (c) Aloyan" << endl;
    cerr << "Generating (x*/a +- b)*/c +- d = k, that can be solved with wrong operations" << endl;

    a = b = c = d = k = 1;

    srand(time(NULL));

    freopen("output.txt", "w+", stdout);
    cout << "Гeнeрaтoр примeрoв пo aлгeбрe (c) Алоян" << endl;
    fclose(stdout);

    cerr << "Number of variants? " << endl;
    cin >> number_of_variants;
    fclose(stdin);
}

void run()
{
    int b0 = 0, c0 = 0, d0 = 0, k0 = 0;
    int i = 0;

    a = rand() % max_gen + min_number;

    do
    {
        c0 = rand() % max_gen;
        i++;
        if (i > maxx)
        {
            i = 0;
            srand(time(NULL));
        }
    }
    while (c0 < 3);
    cerr << "25% ";
    i = 0;

    do
    {
        d0 = rand() % max_gen;
        i++;
        if (i > maxx)
        {
            i = 0;
            srand(time(NULL));
        }
    }
    while (d0 < 3);
    cerr << "50% ";
    i = 0;

    do
    {
        k0 = rand() % (max_number - min_number) + min_number;
        i++;
        if (i > maxx)
        {
            i = 0;
            srand(time(NULL));
            k0 = rand() % (max_number - min_number) + max_number;
        }
    }
    while (k0 <= 4*c0 + d0);
    cerr << "75% ";
    i = 0;

    do
    {
        b0 = (((k0 - d0) / c0) - (rand() % (k0 - d0) / c0) - 1);
        i++;
        if (i > max_gen)
        {
            i = 0;
            srand(time(NULL));
        }
    }
    while (b0 < 2);
    cerr << "100%" << endl;

    c = c0;
    d = d0 * a * c;
    k = k0 * a * c;
    b = b0 * a;
    if (!check())
    {
        cerr << "ERROR!!!" << endl;
        system("PAUSE");
    }
}

void print(int z)
{
    freopen("output.txt", "a+", stdout);

    cout << endl;
    cout << "Вариант №" << z << endl;

    cout << "(x*" << a << "+" << b << ")*" << c << "+" << d << "=" << k << ",  x = " << (((k - d) / c - b) / a) << endl;
    cout << "(x*" << a << "+" << b << ")*" << c << "-" << d << "=" << k << ",  x = " << (((k + d) / c - b) / a) << endl;
    cout << "(x*" << a << "+" << b << ")/" << c << "+" << d << "=" << k << ",  x = " << (((k - d) * c - b) / a) << endl;
    cout << "(x*" << a << "+" << b << ")/" << c << "-" << d << "=" << k << ",  x = " << (((k + d) * c - b) / a) << endl;
    cout << "(x*" << a << "-" << b << ")*" << c << "+" << d << "=" << k << ",  x = " << (((k - d) / c + b) / a) << endl;
    cout << "(x*" << a << "-" << b << ")*" << c << "-" << d << "=" << k << ",  x = " << (((k + d) / c + b) / a) << endl;
    cout << "(x*" << a << "-" << b << ")/" << c << "+" << d << "=" << k << ",  x = " << (((k - d) * c + b) / a) << endl;
    cout << "(x*" << a << "-" << b << ")/" << c << "-" << d << "=" << k << ",  x = " << (((k + d) * c + b) / a) << endl;
    cout << "(x/" << a << "+" << b << ")*" << c << "+" << d << "=" << k << ",  x = " << (((k - d) / c - b) * a) << endl;
    cout << "(x/" << a << "+" << b << ")*" << c << "-" << d << "=" << k << ",  x = " << (((k + d) / c - b) * a) << endl;
    cout << "(x/" << a << "+" << b << ")/" << c << "+" << d << "=" << k << ",  x = " << (((k - d) * c - b) * a) << endl;
    cout << "(x/" << a << "+" << b << ")/" << c << "-" << d << "=" << k << ",  x = " << (((k + d) * c - b) * a) << endl;
    cout << "(x/" << a << "-" << b << ")*" << c << "+" << d << "=" << k << ",  x = " << (((k - d) / c + b) * a) << endl;
    cout << "(x/" << a << "-" << b << ")*" << c << "-" << d << "=" << k << ",  x = " << (((k + d) / c + b) * a) << endl;
    cout << "(x/" << a << "-" << b << ")/" << c << "+" << d << "=" << k << ",  x = " << (((k - d) * c + b) * a) << endl;
    cout << "(x/" << a << "-" << b << ")/" << c << "-" << d << "=" << k << ",  x = " << (((k + d) * c + b) * a) << endl;

    fclose(stdout);
}

void make_random_variants()
{
    freopen("output.txt", "r+", stdin);
    freopen("variants.txt", "w+", stdout);

    string s;
    getline(cin, s);
//    getline(cin, s);

    cout << "Генератор примеров по алгебре (с) Алоян" << endl << endl;

    for (int i = 0; i < number_of_variants; i++)
    {
        getline(cin, s);
        getline(cin, s);

        int q = 10;
        while (q == 10 || q == 11)
            q = rand() % 14;

        for (int j = 0; j < q; j++)
            getline(cin, s);

        getline(cin, s);
        cout << "Вариант №" << i + 1 << "  ";
        for (int i = 0; i < (int) s.length(); i++)
        {
            if (s[i] == ',')
                break;

            if (s[i] == '/')
                cout << ":";
            else
                cout << s[i];
        }
        cout << endl;

        for (int j = q + 1; j < 16; j++)
            getline(cin, s);
    }

    fclose(stdin);
    fclose(stdout);
}

bool check()
{
    if (k > d)
    if ((k - d) % c == 0)
    if ((k + d) % c == 0)
    if ((k - d) / c > b)
    if (((k - d) / c - b) % a == 0)
        return true;
    return false;
}
