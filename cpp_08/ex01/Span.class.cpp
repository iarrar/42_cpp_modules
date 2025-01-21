#include "Span.class.hpp"

Span::Span()
{

}

Span::Span(unsigned int nb) : N(nb)
{
	
}

Span::Span(Span const & src)
{
	*this = src;
}

Span::~Span()
{

}

void	Span::addNumber(int nb)
{
	if (this->tab.size() >= this->N)
		throw (Span::MaxNumbers());
	else
	{
		this->tab.push_back(nb);
		this->sortedTab = this->tab;
		std::sort(sortedTab.begin(), sortedTab.end());
	}
}

void			Span::addNumbers(unsigned int add)
{
	time_t *ptr = NULL;
	std::vector<int> tab_f(add);
	std::vector<int>::iterator it = tab_f.begin();

	unsigned int i = 0;
	srand(time(ptr));
	//random = rand();
	while (i < add && it != tab_f.end())
	{
		if (i > N)
			throw MaxNumbers();
		else
		{
			*it = rand();
			it++;
			i++;
		}
	}
	this->tab = tab_f;
	this->sortedTab = tab_f;
	std::sort(sortedTab.begin(), sortedTab.end());

}

unsigned int	Span::longestSpan() const
{
	if (this->tab.size() <= 1)
		throw NoDistance();
	else
	{
		int min = *std::min_element(this->tab.begin(), this->tab.end());
		int max = *std::max_element(this->tab.begin(), this->tab.end());
		unsigned int diff =  max - min;
		return (diff);
	}
}

unsigned int	Span::shortestSpan() const
{
	if (this->tab.size() <= 1)
		throw NoDistance();
	else
	{
		int min;
		int buff;
		min = this->sortedTab[0] - this->sortedTab[1];
		if (min < 0)
			min = -min;
		unsigned int i = 0;
		while (i < sortedTab.size())
		{
			buff = this->sortedTab[i] - this->sortedTab[i + 1];
			if (buff <= 0)
				buff = -buff;
			if (buff <= min)
				min = buff;
			i++;
		}
		return (min);
	}
}

const char*		Span::NoDistance::what() const throw()
{
	return ("Not enough members");
}

const char * Span::MaxNumbers::what() const throw()
{
	return ("Maximum capacity reached");
}

void		Span::displaySortedTab() const
{
	unsigned int i = 0;
	while (i < this->sortedTab.size())
	{
		std::cout << "ST[" << i << "] = " << this->sortedTab[i] << std::endl;
		i++;
	}
}

void		Span::displayTab() const
{
	unsigned int i = 0;
	while (i < this->tab.size())
	{
		std::cout << "T[" << i << "] = " << this->tab[i] << std::endl;
		i++;
	}
}

const std::vector<int> &	Span::getSortedTab() const
{
	return (this->sortedTab);
}

const std::vector<int> &	Span::getTab() const
{
	return (this->tab);
}

int				Span::getSize() const
{
	return (this->N);
}

Span & Span::operator=(Span const & src)
{
	this->N = src.getSize();
	this->sortedTab = src.getSortedTab();
	this->tab = src.getTab();
	return (*this);
}
