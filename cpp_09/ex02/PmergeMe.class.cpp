#include "PmergeMe.class.hpp"

PmergeMe::PmergeMe()
{
	_error = 0;
}

PmergeMe::PmergeMe(char **input)
{
	_error = 0;
	setInput(input);
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
	*this = src;
}

PmergeMe::~PmergeMe()
{

}

PmergeMe & PmergeMe::operator=(PmergeMe const & src)
{
	_list = src.getList();
	_vector = src.getVector();
	_error = src.getError();
	return (*this);
}

int	PmergeMe::getError() const
{
	return (_error);
}


long int	PmergeMe::checkInput(char *str)
{
	int i = 0;
	char* endPtr;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		else
			i++;
	}

	long int res = std::strtol(str, &endPtr, 10);
	if (res < 0 || res > 2147483647)
		return (-1);
	else
		return (res);
}


std::vector <int>	PmergeMe::getVector() const
{
	return (_vector);
}

std::list <int> PmergeMe::getList() const
{
	return (_list);
}

void				PmergeMe::setInput(char **src)
{
	int i = 0;
	while (src[i] != NULL)
	{
		if (atoi(src[i]) < 0 || checkInput(src[i]) < 0)
		{
			_error = 1;
			std::cout << "Negative number or invalid argument found in the input" << std::endl;
			return ;
		}

		_vector.push_back(atoi(src[i]));
		_list.push_back(atoi(src[i]));
		i++;
	}
	return ;
}

std::vector <int> PmergeMe::sort_vector(std::vector <int> src)
{
	if (_error == 0)
	{
		if (src.size() == 2)
		{
			if (src[0] > src[1])
			{
				int tmp;
				tmp = src[0];
				src[0] = src[1];
				src[1] = tmp;
				return (src);
			}
			else
				return (src);
		}
		else if (src.size() == 1)
			return (src);
		else
		{
			std::vector <int> vec1 = first_part_vector(src);
			std::vector <int> vec2 = second_part_vector(src);
			vec1 = sort_vector(vec1);
			vec2 = sort_vector(vec2);
			src = merge_vector(vec1, vec2);
		}
			return (src);
	}
	else
	{
		std::cout << "Error : Negative numbers found in the input" << std::endl;
		return (src);
	}
}

std::vector <int> PmergeMe::first_part_vector(std::vector <int> src)
{
	std::vector <int> res;
	int i = static_cast <int> (src.size());
	int j = 0;

	while (j < i / 2)
	{
		res.push_back(src[j]);
		j++;
	}

	return (res);
}

std::vector <int> PmergeMe::second_part_vector(std::vector <int> src)
{
	std::vector <int> res;
	int i = static_cast <int> (src.size()) / 2;

	while (i < static_cast<int> (src.size()))
	{
		res.push_back(src[i]);
		i++;
	}
	return (res);

}

std::vector <int> PmergeMe::merge_vector(std::vector <int> src1, std::vector <int> src2)
{
	int i = 0;
	int j = 0;

	std::vector <int> dest;
	while (i < static_cast<int>(src1.size()) && j < static_cast<int>(src2.size()))
	{
		if (src1[i] <= src2[j])
		{
			dest.push_back(src1[i]);
			i++;
		}
		else
		{
			dest.push_back(src2[j]);
			j++;
		}
	}
	if (i < static_cast<int>(src1.size()))
	{
		while (i < static_cast<int>(src1.size()))
		{
			dest.push_back(src1[i]);
			i++;
		}
	}
	if (j < static_cast<int>(src2.size()))
	{
		while (j < static_cast<int>(src2.size()))
		{
			dest.push_back(src2[j]);
			j++;
		}
	}
	return (dest);
}

std::list <int> PmergeMe::sort_list(std::list <int> src)
{
	if (_error == 0)
	{
		if (src.size() == 2)
		{
			src.sort();
			return (src);	
		}
		else if (src.size() == 1)
			return (src);
		else
		{
			
			int i = 0;
			std::list <int>::iterator it = src.begin();
			std::list <int> vec1;
			std::list <int> vec2;
			while (i < static_cast<int>(src.size() / 2))
			{
				vec1.push_back(*it);
				it++;
				i++;
			}
			while (it != src.end())
			{
				vec2.push_back(*it);
				it++;
			}
			vec1 = sort_list(vec1);
			vec2 = sort_list(vec2);
			src = merge_list(vec1, vec2);
		}
			return (src);
	}
	else
	{
		std::cout << "Error : Negative numbers found in the input" << std::endl;
		return (src);
	}
}

std::list <int> PmergeMe::merge_list(std::list <int> src1, std::list <int> src2)
{
	std::list <int>::iterator it = src1.begin();
	std::list <int>::iterator jt = src2.begin();

	std::list <int> dest;
	while (it != src1.end() && jt != src2.end())
	{
		if (*it <= *jt)
		{
			dest.push_back(*it);
			it++;
		}
		else
		{
			dest.push_back(*jt);
			jt++;
		}
	}
	if (it != src1.end())
	{
		while (it != src1.end())
		{
			dest.push_back(*it);
			it++;
		}
	}
	if (jt != src2.end())
	{
		while (jt != src2.end())
		{
			dest.push_back(*jt);
			jt++;
		}
	}
	return (dest);
}

void		PmergeMe::sort()
{
	clock_t	start;
	clock_t end;
	double time;
	if (_error == 0)
	{
		start = clock();
		_vector = sort_vector(_vector);
		end = clock();
		int i = 0;
		std::cout << "Sort via Vector :" << std::endl;
		while (i < static_cast<int>(_vector.size()))
		{
			std::cout <<_vector[i] << ", ";
			i++;
		}
		std::cout << std::endl;
		time = static_cast<double>(end) - static_cast<double>(start);
		std::cout << "Sort on vector done in " << time << std::endl;
		std::cout << "Sort via Vector :" << std::endl;
		start = clock();
		_list = sort_list(_list);
		end = clock();
		time = static_cast<double>(end) - static_cast<double>(start);
		std::list<int>::iterator it = _list.begin();
		while (it != _list.end())
		{
			std::cout << *it << ", ";
			it++;
		}
		std::cout << "\nSort on List done in " << time << std::endl;
	}
	else
	{
		std::cout << "Wrong Input" << std::endl;
	}

}
