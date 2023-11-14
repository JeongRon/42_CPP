#include <iostream>

int main(int ac, char **av)
{
    int i = 1, j = 0;

    if (ac == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    } 
    else 
    {
        while (i < ac)
        {
            j = 0;
            while (av[i][j])
            {
                if ('a' <= av[i][j] && av[i][j] <= 'z')
                    std::cout << char(av[i][j] - 32);
                else
                    std::cout << av[i][j];
                j++;
            }
            i++;
        }
        std::cout << std::endl;
    }
    return 0;
}