#include "ProvinceEnum.h"
#include <map>
namespace PetAdoption {

std::string to_string(ProvinceEnum province) {
    static std::map<ProvinceEnum, std::string> provinceMap = {
        {ProvinceEnum::AB, "Alberta"},
        {ProvinceEnum::BC, "British Columbia"},
        {ProvinceEnum::MB, "Manitoba"},
        {ProvinceEnum::NB, "New Brunswick"},
        {ProvinceEnum::NL, "Newfoundland and Labrador"},
        {ProvinceEnum::NS, "Nova Scotia"},
        {ProvinceEnum::NT, "Northwest Territories"},
        {ProvinceEnum::NU, "Nunavut"},
        {ProvinceEnum::ON, "Ontario"},
        {ProvinceEnum::PE, "Prince Edward Island"},
        {ProvinceEnum::QC, "Quebec"},
        {ProvinceEnum::SK, "Saskatchewan"},
        {ProvinceEnum::YT, "Yukon"}
    };

    auto it = provinceMap.find(province);
    if (it != provinceMap.end()) {
        return it->second;
    }

    return "Unknown"; // Fallback for undefined enum values
}

} // namespace PetAdoption
