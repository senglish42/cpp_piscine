/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:29:00 by senglish          #+#    #+#             */
/*   Updated: 2022/04/12 19:29:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main(int argc, char **argv)
{
    int     count, sym;
    char    ch;

    count = 0;
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    while (argv[++count])
    {
        sym = -1;
        while (argv[count][++sym])
        {
            ch = (char)toupper(argv[count][sym]);
            std::cout << ch;
        }
        std::cout << " ";
    }
    std::cout << std::endl;
    return 0;
}
