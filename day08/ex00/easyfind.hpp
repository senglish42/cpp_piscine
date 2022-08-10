/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:41:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/27 18:41:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <iterator>


template <typename T>
void easyfind(T& x, int num)
{
    typename T::const_iterator iterStart = x.begin();
    typename T::const_iterator iterEnd = x.end();
    typename T::const_iterator target = std::find(iterStart, iterEnd, num);
    try
    {
        if (target == iterEnd)
            throw std::exception();
        else
            std::cout   << "The integer is needed (" << num
                        << ") has been found. Container's position: "
                        << std::distance(iterStart, target) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout   << "Error: the integer is needed (" << num
                    << ") hasn't been found." << std::endl;
    }
}

#endif