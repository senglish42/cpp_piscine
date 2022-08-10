/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassC.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:12:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/23 18:12:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSC_HPP
# define CLASSC_HPP

#include "ClassBase.hpp"

class C : public Base
{
    public:
        C();
        virtual ~C();
        const char &getType() const;
    private:
        const char _type;
};

#endif