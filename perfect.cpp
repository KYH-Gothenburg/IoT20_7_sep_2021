#include <iostream>
#include <string>

using namespace std;

void process(string &arg)
{
    cout << "lvalue process" << endl;
}

void process(string &&arg)
{
    cout << "rvalue process" << endl;
}


template<typename T>
void logAndProcess(T &&param)
{
    process(param);
}

int main() {
    string value = "hej";
    logAndProcess("hej");
    return 0;
}
