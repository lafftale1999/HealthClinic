#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H
#include <iostream>
#include "include/client.h"
#include "include/clinic.h"

// Client *binarySearch(Clinic *clientlist,int size, std::string target);
Client *binarySearch(Clinic *clientlist, int size, const std::string& target);

#endif
