//hermione warr
//created: 12/02/2020
//assignment 3
//program to store and print physics courses

#include<iostream>
#include<string>
#include<sstream>
#include<vector>

int main()
{
    const std::string degreeCode("PHYS");
    std::vector<double> course_code;
    //std::string course_name;
    std::vector<std::string> course_name;
    
    // Gather list of courses and their codes from user,
    // storing data as a vector of strings
    bool not_finished(true);
    do
    {
        std::cout << "Please enter a course code and course name (or x to finish): ";//seems really slow file?
        std::cin >> course_code >> course_name;
        if (std::cin() = 'x') {
            not_finished = false;
        }
        else if (course_code.empty()) {
            std::cout << "Please enter a valid course code: " << std::endl;
            course_code.clear();//or erase?
            std::cin >> course_code;
        }
         
        else if (course_name.empty()) {
            std::cout << "Please enter a valid course code: " << std::endl;
            course_name.clear();//or erase?
            std::cin >> course_name;
        }

        if (!course_name.empty()) { //or whatever conditions
            std::stringstream full_course_title;
            full_course_title << degreeCode << course_code << course_name;
        }
        
    } while (not_finished);

    // Print out full list of courses
    std::cout << "List of courses:" << std::endl;

    // Extract courses belonging to a certain year
    std::string year_choice;
    std::cout << "Please enter year: ";
    std::cin >> year_choice;
    //sort courses by code or name
    std::string sort_option;
    std::cout >> "Sort by code or name: ";
    std::cin >> sort_option;
    if (sort_option = 'code' && sort_option = 'name') {
        
    }

    else {
        std::cout << "Please say whether you would like to sort by code or name: (or enter to quit)" << std::endl;
        sort_option.clear();
        sort_option.ignore();
        std::cin >> sort_option;
    }

    return 0;

}


