/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:11:20 by iarrar            #+#    #+#             */
/*   Updated: 2024/05/07 16:11:21 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_H
#define SERIALIZE_H
#include <stdint.h>
#include "Data.class.hpp"

class Serialize
{
    public:
        virtual ~Serialize();
        static uintptr_t    serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);

    protected:

        Serialize& operator=(Serialize const & src);
        Serialize();
        Serialize(Serialize const & src);
        int i;
};

#endif