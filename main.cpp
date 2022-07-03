#include <fcntl.h>
#include <iostream>

int main()
{
    int i = O_WRONLY | O_RDWR;
    std::cout << i << std::endl;
}