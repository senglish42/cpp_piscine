/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:41:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/27 18:41:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include "easyfind.hpp"

int main()
{
    {
        std::vector<int> arrInt;
        arrInt.push_back((int) 4);
        arrInt.push_back((int) 8);
        arrInt.push_back((int) 15);
        arrInt.push_back((int) 16);
        arrInt.push_back((int) 23);
        arrInt.push_back((int) 42);
        easyfind(arrInt, 23);
    }
    {
        int *arrInt2 = new int[10];
        for (int num = 0; num < 10; ++num)
            std::fill(arrInt2 + num, arrInt2 + num + 1, num);
        std::vector<int> arrInt3(arrInt2, arrInt2 + 10);
        easyfind(arrInt3, 9);
        delete []arrInt2;
    }
    {
        std::list<int> arrInt4(5, 10);
        easyfind(arrInt4, 10);
        std::vector<int> arrInt5;
        arrInt5.reserve(arrInt4.size());
        std::copy(arrInt4.begin(), arrInt4.end(), std::back_inserter(arrInt5));
        easyfind(arrInt5, 0);
    }
    {
        std::set<int> arrInt6;
        arrInt6.insert(16);
        arrInt6.insert(19);
        arrInt6.insert(22);
        easyfind(arrInt6, 22);
    }
    return 0;
}