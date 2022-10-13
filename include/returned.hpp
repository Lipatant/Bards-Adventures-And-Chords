/*
** BARDS - VIRGILE (LIPATANT) BERRIER, 2022
** returned.hpp
** File description:
** Possible returned values
*/

#pragma once
#include <iostream>
#include "utility/strings.hpp"

enum returned_indices
{
    RETURNED_EXIT,
    RETURNED_ERROR_NO_ENV,
    RETURNED_TOTAL,
};

static const std::string RETURNED_MESSAGES[RETURNED_TOTAL] = {
    STRING_NULL,
    "Error: No env detected!",
};
