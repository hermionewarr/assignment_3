//hermione warr
//created: 12/02/2020
//assignment 3
//program to store and print physics courses

#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<vector>
#include<algorithm>
#include<string.h>

//comparing functions
bool compare_by_course_name(std::string course_name1, std::string course_name2) {

	return course_name1.substr(9) < course_name2.substr(9);
}

int main()
{
    //main variables
    std::vector<std::string> course;
	std::vector<std::string> sorted_by_year;

    // Gather list of courses and their codes from user,
    // storing data as a vector of strings
    bool not_finished(true);
    do
    {
		//local variables
		const std::string degreeCode("PHYS");
		int course_code{};
		std::string course_name;
		std::string user_input;
		std::stringstream full_course_details;

        std::cout << "Please enter a course code and course name (or x to finish): \n";//seems really slow file?
		std::cin >> user_input;

        if (user_input == "x") {
            not_finished = false;
        }
		else {
			std::stringstream(user_input) >> course_code;
			std::getline(std::cin >> std::ws, course_name);
			full_course_details << degreeCode << course_code << "  " << course_name;
			course.push_back(full_course_details.str());
			//full_course_details.str(""); //to clear
		}

    } while (not_finished);

    // Print out full list of courses
    std::cout << "List of courses:" << std::endl;
	std::vector <std::string> ::iterator vector_begin{ course.begin() };
	std::vector <std::string>::iterator vector_end{course.end()};
	std::vector <std::string>::iterator vector_iterator;
	for (vector_iterator = vector_begin; vector_iterator < vector_end; ++vector_iterator)
		std::cout << *vector_iterator << std::endl;

    // Extract courses belonging to a certain year
    //int year_choice;
	std::string year;
	std::cout << "Please enter year (1,2,3 or 4): " << std::endl;
    std::cin >> year;
	std::cout << "You entered year " << year << std::endl;
 
	//sort by year (not working but should
	/*std::vector <std::string> ::iterator iiterator_begin{ course.begin() };
	//std::vector<std::string> ::iterator iterator_year{ course.at(4) };
	std::vector <std::string>::iterator iiterator_end{ course.end() };
	std::vector <std::string>::iterator iiterator;
	for (iiterator = iiterator_begin; iiterator < iiterator_end - 1; ++iiterator) {
		if (iiterator[4, 1] == year) {
			std::cout << iiterator[4,1] << std::endl;
			sorted_by_year.push_back(*iiterator);
			std::cout << *iiterator << std::endl;
		}
	}*/
	//working method to sort by year
	for (size_t i{}; i < course.size(); ++i) {

		if(course[i].substr(4,1) == year){
				sorted_by_year.push_back(course[i]);
		}
	}
	//print out courses extracted by year with iterators
	std::vector <std::string> ::iterator year_begin{ sorted_by_year.begin() };
	std::vector <std::string>::iterator year_end{ sorted_by_year.end() };
	std::vector <std::string>::iterator year_iterator;
	for (year_iterator = year_begin; year_iterator < year_end; ++year_iterator)
		std::cout << *year_iterator << std::endl;

    //sort courses by code or name
    std::string sort_option;
    std::cout << "Sort by code or name: ";
    std::cin >> sort_option;
	std::cout << "Sorted by " << sort_option << ":" << std::endl;

    if (sort_option == "code"){
		std::sort(course.begin(), course.end());
		for (std::vector<std::string>::iterator sorted_course_it = course.begin(); sorted_course_it != course.end(); ++sorted_course_it)
			std::cout << ' ' << *sorted_course_it << std::endl;
    }
	else if (sort_option == "name") {
		std::sort(course.begin(), course.end(), compare_by_course_name);
		for (std::vector<std::string>::iterator sorted_course_it = course.begin(); sorted_course_it != course.end(); ++sorted_course_it)
			std::cout << ' ' << *sorted_course_it << std::endl;
	}
    else {
        std::cout << "Please say whether you would like to sort by code or name: (or another charracter to quit)" << std::endl;
        std::cin.clear();
        std::cin.ignore();
        std::cin >> sort_option;
    }

    return 0;
}