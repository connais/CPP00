#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

class Contact
{

public:

    int			infos;
    std::string	first_name;
    std::string	last_name;
    std::string	nickname;
    std::string	phone_number;
    std::string	darkest_secret;

    Contact( void );
    ~Contact( void );
};


