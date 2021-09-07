#include <iostream>

using namespace std;

int main() {

    auto f = [z = 0]() mutable
            {
                return z++;
            };

    while(f() < 10)
    {
        cout << "Inne" << endl;
    }
    cout << "Done" << endl;
    return 0;
}
