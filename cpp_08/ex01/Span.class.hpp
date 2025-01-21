#ifndef SPAN_H
#define SPAN_H
#include <vector>
#include <algorithm>
#include <iostream>

#include <cstdlib>

class Span
{
	public:
					Span(unsigned int nb);
					Span(Span const & src);
					virtual ~Span();
	Span& 			operator=(Span const & src);
	void			addNumber(int nb);
	void			addNumbers(unsigned int add);
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;
	void			displayTab() const;
	void			displaySortedTab() const;
	const std::vector<int> &	getTab() const;
	const std::vector<int> &	getSortedTab() const;
	int				getSize() const;

	class MaxNumbers : public std::exception
	{
		public :
			const char*		what() const throw();
	};

	class NoDistance : public std::exception
	{
		public :
			const char*		what() const throw();
	};

	protected:
						Span();
		std::vector 	<int>tab;
		std::vector		<int>sortedTab;
		unsigned int	N;



};

#endif