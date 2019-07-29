// Created by Flavio Castelli <flavio.castelli@gmail.com>
// distrubuted under GPL v2 license

#include <boost/regex.hpp>
#include <string>

int main()
{
	boost::regex pattern ("b.lug",boost::regex_constants::icase|boost::regex_constants::perl);
	std::string stringa ("Searching for bolug");
	std::string replace ("BgLug");
	std::string newString;

	newString = boost::regex_replace (stringa, pattern, replace);

	printf("The new string is: |%s|\n",newString.c_str());
		
	return 0;
}
