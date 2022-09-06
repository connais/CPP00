#include <iostream>

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    if (argc <= 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    while (i < argc)
    {
        j = -1;
        while (argv[i][++j] != '\0')
        {
            if ((argv[i][j] >= 97) && (122 >= argv[i][j]))
                std::cout << (char)(argv[i][j] - 32);
            else
                std::cout << argv[i][j];
        }
        i++;
    }
    std::cout << std::endl;
    return (0);
}