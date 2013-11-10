//用for循环编写的程序如下:
#include <iostream>
using namespace std;
int main()
{
int sum = 0;
for (int i = 50; i <= 100; ++i)
sum += i;
cout << "Sum of 50 to 100 inclusive is "
<< sum << endl;


return 0;
}
/*
//用while循环编写的程序如下:
#include <iostream>
using namespace std;
int main()
{
int sum = 0, int i = 50;
while (i <= 100) {
sum += i;
++i;
}
cout << "Sum of 50 to 100 inclusive is "
<< sum << endl;
return 0;
}
*/

