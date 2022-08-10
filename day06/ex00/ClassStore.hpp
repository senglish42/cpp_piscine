/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassStore.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:08:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/20 13:08:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSSTORE_HPP
# define CLASSSTORE_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>

class Store
{
    public:
        explicit Store(std::string &str);
        void convert();
        ~Store();
        Store(const Store &copy);
        Store &operator=(const Store &store);
        const std::string &getStr() const;
        bool        getDetect() const;
        char        getCh() const;
        int         getInt() const;
        float       getF() const;
        double      getD() const;
    private:
        void        ifChar();
        void        ifInt();
        void        ifFloat();
        void        printOut();
        void        printOutCh();
        void        printOutF();
        void        printOutD();
        void        printOutImpExc();
        bool        findExc();
        bool        exclusions();
        bool        exclusionsF();
        bool        exclusionsD();
        const std::string   _str;
        bool                _detect;
        char                _ch;
        int                 _int;
        float               _f;
        double              _d;
};

#endif