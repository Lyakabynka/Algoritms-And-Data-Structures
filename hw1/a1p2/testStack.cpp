#include "Stack.h"

using namespace std;

int main()
{
    //simple test
    int out;
    Stack<int> integer_stack;
    string outs;
    Stack<string> string_stack;
    integer_stack.push(777);
    integer_stack.push(5);
    integer_stack.push(12);

    string_stack.push("Hello");
    string_stack.push("from");
    string_stack.push("Jacobs University!");

    bool res = integer_stack.pop(out);
    if (res)
    {
        cout << "Popped: " << out << endl;
    }

    res = string_stack.pop(outs);
    if (res)
    {
        cout << "Popped s: " << outs << endl;
    }

    int result = integer_stack.back();
    if (result != 0)
    {
        cout << "Top element is " << result
            << endl;
    }

    string results = string_stack.back();
    if (result != 0)
    {
        cout << "Top element is " << results
            << endl;
    }


    return 0;
}