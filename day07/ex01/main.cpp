/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:45:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/25 12:45:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cstring>

void lowerstring(std::string &arr)
{
    int size = static_cast<int>(static_cast<std::string>(arr).size());
    for (int i = 0; i < size; i++)
        arr[i] = static_cast<char>(tolower((arr[i])));
}

int main()
{
    std::string arr1[] = {"STANFORD", "MIT", "HARVARD", "SCHOOL21"};
    char arr2[] = "Linus Torvalds";
    int arr3[5] = {1,2,3,4,5};
    iter(arr3, 5, print_data);
    std::cout << std::endl;
    iter(arr3, 5, multiply5);
    iter(arr3, 5, print_data);
    std::cout << std::endl;
    iter(arr3, 5, replace56);
    iter(arr3, 5, print_data);
    std::cout << std::endl;
    iter(arr2, strlen(arr2), print_data);
    std::cout << std::endl;
    iter(arr2, strlen(arr2), uppercase);
    iter(arr2, strlen(arr2), print_data);
    std::cout << std::endl;
    iter(arr1, 4, print_data);
    std::cout << std::endl;
    iter(arr1, 4, lowerstring);
    iter(arr1, 4, print_data);
    std::cout << std::endl;
    return 0;
}