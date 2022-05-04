/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:36:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/01 17:36:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(void)
{
    std::ifstream   input("forever");
    std::ofstream   output("forever.replace");

    std::string str;
    std::string s1 = "Masha";
    std::string s2 = "Dasha";

    while (input >> str)
    {
        if (str.compare(0, s1.size(), s1) != 0)
            output << str << " ";
        else
        {
            output << s2;
            if (str.size() != s1.size())
            {
                str.erase(0, s1.size());
                output << str;
            }
            output << " ";
        }
    }
    output << std::endl;
    input.close();
    output.close();
    return (0);
}