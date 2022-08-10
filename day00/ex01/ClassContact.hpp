/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:56:00 by senglish          #+#    #+#             */
/*   Updated: 2022/04/12 19:56:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CONTACT_HPP
#define CLASS_CONTACT_HPP

#include <string>

class Contact {
    public:
        Contact();
        Contact(const std::string &name, const std::string &surname,
                    const std::string &nickname, const std::string &phone,
                    const std::string &secret);
        ~Contact();
        void GetInfo() const;
        const std::string& GetName() const;
        const std::string& GetSurname() const;
        const std::string& GetNickname() const;
        const std::string& GetPhone() const;
        const std::string& GetSecret() const;
    private:
        std::string _name;
        std::string _surname;
        std::string _nickname;
        std::string _phone;
        std::string _secret;
};

#endif