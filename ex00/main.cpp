/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:08:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/20 13:08:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassStore.hpp"

int main(int argc, char **argv)
{
    std::string par;
    std::string free;
    if (argc != 2)
    {
        std::cerr << "Input one stroke: ";
        std::cin >> par;
    }
    else
        par = argv[1];
    for (unsigned int c = 0; c != par.size(); c++)
        par[c] = static_cast<char>(tolower(par[c]));
    Store keep(par);
    keep.convert();
    return 0;
}
