#ifndef PROVINCEENUM_H
#define PROVINCEENUM_H

#include <string>

namespace PetAdoption {

enum class ProvinceEnum {
    AB, // Alberta
    BC, // British Columbia
    MB, // Manitoba
    NB, // New Brunswick
    NL, // Newfoundland and Labrador
    NS, // Nova Scotia
    NT, // Northwest Territories
    NU, // Nunavut
    ON, // Ontario
    PE, // Prince Edward Island
    QC, // Quebec
    SK, // Saskatchewan
    YT  // Yukon
};

std::string to_string(ProvinceEnum province);

} // namespace PetAdoption

#endif // PROVINCEENUM_H
