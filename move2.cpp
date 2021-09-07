#include <iostream>

using namespace std;

class MyClass
{
public:
    MyClass() : value_(nullptr)
    {
        cout << "Default Constructor" << endl;
    }

    MyClass(int value) : value_(new int(value))
    {
        cout << "Single argument constructor with value " << *value_ << endl;
    }

    MyClass(const MyClass &other) : value_(new int(*other.value_))
    {
        cout << "Copy constructor with value " << *value_ << endl;
    }

    MyClass(MyClass &&other) : value_(nullptr)
    {
        swap(value_, other.value_);
        cout << "Move constructor with value " << *value_ << endl;
    }

    ~MyClass()
    {
        if(value_)
        {
            cout << "Destructing object with value " << *value_ << endl;
        }
        else
        {
            cout << "Destructing object with value null" << endl;
        }


        delete value_;
    }

    MyClass &operator = (const MyClass &other)
    {
        value_ = new int(*other.value_);
        cout << "Copy assignment with value " << *value_ << endl;
        return *this;
    }

    MyClass &operator = (MyClass &&other)
    {
        value_ = nullptr;
        swap(value_, other.value_);
        cout << "Move assignment with value " << *value_ << endl;
        return *this;
    }

    void print()
    {
        if(value_)
        {
            cout << *value_ << endl;
        }
        else
        {
            cout << "null" << endl;
        }
    }

private:
    int *value_;
};

MyClass func()
{
    MyClass mm(44);
    return move(mm);
}

void f(int &value)
{
    cout << "value is lvalue" << endl;
}

void f(int &&value)
{
    cout << "value is rvalue" << endl;
}

int main() {
    MyClass m1(10);
    MyClass m2 = func();

    return 0;
}
