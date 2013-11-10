#include <iostream>
using namespace std;
int main()
{
    std::cout << "Enter two numbers:" << endl;
    int v1, v2;
    cin >> v1 >> v2; // 读入数据
    if (v1 >= v2)
    cout << "The bigger number is" << v1 << endl;
    else
    cout << "The bigger number is" << v2 << endl;
    return 0;
}
