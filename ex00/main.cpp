/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:12:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/25 12:12:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
    int a = 2;
    int b = 3;

    ::swap( a, b );

    std::cout << "a = " << a << ", b = " << b << std::endl;

    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);

    std::cout << "c = " << c << ", d = " << d << std::endl;

    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    return 0;
//    int a = 10;
//    int b = 5;
//    char c = 'c';
//    char d = 'd';
//    float e = 4.12f;
//    float f = 0.132434f;
//    std::string str1 = "hello";
//    std::string str2 = "world";
//    std::cout   << "::::::BEFORE SWAP::::::" << std::endl;
//    std::cout   << a << " " << b << std::endl;
//    std::cout   << c << " " << d << std::endl;
//    std::cout   << e << " " << f << std::endl;
//    std::cout   << str1 << " " << str2 << std::endl;
//    ::swap(a, b);
//    ::swap(c, d);
//    ::swap(e, f);
//    ::swap(str1, str2);
//    std::cout   << "::::::AFTER SWAP::::::" << std::endl;
//    std::cout   << a << " " << b << std::endl;
//    std::cout   << c << " " << d << std::endl;
//    std::cout   << e << " " << f << std::endl;
//    std::cout   << str1 << " " << str2 << std::endl;
//    std::cout   << "::::::WHICH IS MIN::::::" << std::endl;
//    std::cout   << a << " VS " << b << ": " << ::min(a, b) << std::endl;
//    std::cout   << c << " VS " << d << ": " << ::min(c, d) << std::endl;
//    std::cout   << e << " VS " << f << ": " << ::min(e, f) << std::endl;
//    std::cout   << str1 << " VS " << str2 << ": " << ::min(str1, str2)
//                << std::endl;
//    std::cout   << "::::::WHICH IS MAX::::::" << std::endl;
//    std::cout   << a << " VS " << b << ": " << ::max(a, b) << std::endl;
//    std::cout   << c << " VS " << d << ": " << ::max(c, d) << std::endl;
//    std::cout   << e << " VS " << f << ": " << ::max(e, f) << std::endl;
//    std::cout   << str1 << " VS " << str2 << ": " << ::max(str1, str2)
//                << std::endl;
//    return 0;
}