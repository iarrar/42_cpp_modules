#ifndef PMERGEME_H
#define PMERGEME_H
#include <vector>
#include <list>
#include <cstdlib>
#include <iostream>
#include <ctime>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(PmergeMe const & src);
		PmergeMe(char **str);
		virtual ~PmergeMe();

	PmergeMe& operator=(PmergeMe const & src);
	std::vector <int>	getVector() const;
	std::list <int>		getList() const;
	int					getError() const;
	void				setInput(char **argv);
	std::vector <int>	setVector(char **str);
	std::vector <int>	sort_vector(std::vector <int> src);
	std::vector <int>	first_part_vector(std::vector <int> src);
	std::vector <int>	second_part_vector(std::vector <int> src);
	std::vector <int>	merge_vector(std::vector <int> src1, std::vector <int> src2);
	long int			checkInput(char *str);
	std::list <int>	setList(char **str);
	std::list <int> sort_list(std::list <int> src);
	std::list <int>	merge_list(std::list <int> src1, std::list <int> src2);
	int				ft_stoi(std::string str);
	void			sort();

	protected:

		std::vector <int>   _vector;
		std::list   <int>   _list;
		int					_error;

};

#endif