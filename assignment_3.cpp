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


int main()
{
    const std::string degreeCode("PHYS");
	int course_code{};
    std::string course_name;
    std::vector<std::string> course;
	std::string user_input;
	std::stringstream full_course_details;
	std::vector<std::string> sorted_by_year;

    // Gather list of courses and their codes from user,
    // storing data as a vector of strings
    bool not_finished(true);
    do
    {
        std::cout << "Please enter a course code and course name (or x to finish): \n";//seems really slow file?
		std::cin >> user_input;
		int i{};
        if (user_input == "x") {
            not_finished = false;
        }
        else if (user_input.empty()) {
            std::cout << "Please enter a valid course: " << std::endl;
            user_input.clear();//or erase?
            std::cin >> user_input;
        }

		else {
			std::stringstream(user_input) >> course_code;
			std::getline(std::cin, course_name);
			full_course_details << degreeCode << course_code << course_name;
			course.push_back(full_course_details.str());
			full_course_details.str("");
		}

    } while (not_finished);

    // Print out full list of courses
    std::cout << "List of courses:" << std::endl;
	//wants it done with intorators
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
 
	//sort by year
	/*std::vector <std::string> ::iterator iterator_begin{ course.begin() };
	//std::vector<std::string> ::iterator iterator_year{ course.at(4) };
	std::vector <std::string>::iterator iterator_end{ course.end() };
	std::vector <std::string>::iterator iterator;
	for (iterator = iterator_begin; iterator < iterator_end; ++iterator) {
		if (iterator[4, 1] == year) {
			std::cout << iterator[4,1] << std::endl;
			sorted_by_year.push_back(*iterator);
			std::cout << *iterator << std::endl;
		}
	}*/

	for (size_t i{}; i < course.size(); ++i) {

		if(course[i].substr(4,1) == year){
				sorted_by_year.push_back(course[i]);
		}
	}
	std::vector <std::string> ::iterator iterator_begin{ sorted_by_year.begin() };
	std::vector <std::string>::iterator iterator_end{ sorted_by_year.end() };
	std::vector <std::string>::iterator iterator;
	for (iterator = iterator_begin; iterator < iterator_end; ++iterator)
		std::cout << *iterator << std::endl;
	//for (int i{}; i < sorted_by_year.size(); i++)
		//std::cout << sorted_by_year[i] << std::endl;

    //sort courses by code or name
    std::string sort_option;
    std::cout << "Sort by code or name: ";
    std::cin >> sort_option;

	//ok lot of stuff to fix here
    if (sort_option == "code"){//theres a sort function google
		/*std::vector <std::string>:: iterator begin {course.begin ()};
		std::vector <std::string>::iterator end {course.end() };*/
		//std::vector <std::string>::iterator vector_iterator;
		//// Sort data in reverse order
		//reverse(vector_begin, vector_end);
		//std::cout << "Sorted data:" << std::endl;B
		//std::vector <std::string>::iterator vector_iterator;
		//for (vector_iterator = vector_begin; vector_iterator < vector_end; ++vector_iterator)
		//	std::cout << *vector_iterator << std::endl;

		/*sort(begin(course), end(course), substring_compare(4, 5));
		std::cout << "Sorted by code: " << std::endl;
		for (auto& line : course)
			std::cout << line << std::endl;*/

    }

	else if (sort_option == "name") {

	}
    else {
		//if your keeping this figure it out
        std::cout << "Please say whether you would like to sort by code or name: (or another charracter to quit)" << std::endl;
        std::cin.clear();
        std::cin.ignore();
        std::cin >> sort_option;
    }

    return 0;

}


