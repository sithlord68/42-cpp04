/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:23:19 by pascal            #+#    #+#             */
/*   Updated: 2025/09/23 18:29:38 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class	AMateria;

class	IMateriaSource
{

	public:

		IMateriaSource( void );											// canon default cons
		virtual ~IMateriaSource( void ) {}								// canon destroyer

		IMateriaSource( const IMateriaSource & rhs );					// canon copy by cons
		IMateriaSource &	operator=( const IMateriaSource & rhs );	// canon copy by cons

		virtual void learnMateria(AMateria*) = 0;

		virtual AMateria* createMateria(std::string const & type) = 0;

	protected:

	private:

};