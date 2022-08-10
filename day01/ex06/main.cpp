/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:57:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/02 21:57:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

enum string_code {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    OTHERS
};

string_code checkit (std::string const& level)
{
    if (level == "DEBUG")
        return DEBUG;
    if (level == "INFO")
        return INFO;
    if (level == "WARNING")
        return WARNING;
    if (level == "ERROR")
        return ERROR;
    return OTHERS;
}

void    error(Harl harl)
{
    harl.complain("ERROR");
    std::cout << std::endl;
}

void    warning(Harl harl)
{
    harl.complain("WARNING");
    std::cout << std::endl;
    error(harl);
}

void    info(Harl harl)
{
    harl.complain("INFO");
    std::cout << std::endl;
    warning(harl);
}

void    debug(Harl harl)
{
    harl.complain("DEBUG");
    std::cout << std::endl;
    info(harl);
}

void    others(void)
{
    std::cout   << "[ Probably complaining about insignificant problems ]"
                <<  std::endl;
}

int     main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout   << "Here is should be Harl's grumbling" << std::endl;
        return 1;
    }
    Harl harl;
    switch (checkit(argv[1]))
    {
        case OTHERS:
        {
            others();
            break ;
        }
        case DEBUG:
        {
            debug(harl);
            break ;
        }
        case INFO: {
            info(harl);
            break ;
        }
        case WARNING: {
            warning(harl);
            break ;
        }
        case ERROR:
            error(harl);
    }
    return 0;
}