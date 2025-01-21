/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:11:00 by iarrar            #+#    #+#             */
/*   Updated: 2024/05/07 16:11:01 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
#define DATA_H

class Data
{
    public:
        Data();
        Data(Data const & src);
        virtual ~Data();
       Data& operator=(Data const & src);

    protected:
        int member;

};

#endif