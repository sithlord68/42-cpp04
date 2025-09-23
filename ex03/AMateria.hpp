/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:53:48 by pascal            #+#    #+#             */
/*   Updated: 2025/09/23 17:00:15 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

class AMateria
{
	public:

		AMateria(std::string const & type);
		// [...]

		std::string const & getType() const; //Returns the materia type
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	protected:
		// [...]

};




#endif