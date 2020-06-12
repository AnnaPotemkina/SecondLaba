//
//  Errors.h
//  Laba2final
//
//  Created by Анна Потёмкина on 29.05.2020.
//  Copyright © 2020 Анна Потёмкина. All rights reserved.
//

#ifndef Errors_h
#define Errors_h


#include <exception>
# include <string>

class Element_exception_array: public std::exception{
public:
    Element_exception_array(std::string error) : error_notification { error } {}
    ~Element_exception_array()= default;
    const char* what() const noexcept {return error_notification.c_str();}
private:
    std:: string error_notification;
};

class Exception_in_array : public std::exception{
public:
    Exception_in_array(std::string error) : error_notification(error) {}
    ~Exception_in_array() = default;
    const char* what() const noexcept { return error_notification.c_str(); }
private:
    std::string error_notification;
};

class Exception_in_list{
public:
    Exception_in_list(std::string error) : error_notification{ error } {}
    ~Exception_in_list() = default;
    const char* what() const noexcept { return error_notification.c_str(); }
private:
    std::string error_notification;
};

class Exception_in_vector{
public:
    Exception_in_vector(std::string error) : error_notification{ error } {}
    ~Exception_in_vector() = default;
    const char* what() const noexcept { return error_notification.c_str(); }
private:
    std::string error_notification;
};

#endif /* Errors_h */
