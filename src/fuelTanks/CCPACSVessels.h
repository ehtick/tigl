/*
* Copyright (C) 2007-2025 German Aerospace Center (DLR/SC)
*
* Created: 2025-05-09 Marko Alder <Marko.Alder@dlr.de>
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
/**
* @file
* @brief  Implementation of CPACS vessels handling routines.
*/

#pragma once

#include "generated/CPACSVessels.h"
#include <functional>
#include <boost/optional.hpp>

namespace tigl
{

class CCPACSVessels : public generated::CPACSVessels
{
public:
    TIGL_EXPORT CCPACSVessels(CCPACSFuelTank* parent, CTiglUIDManager* uidMgr);

    // Get a specific vessel for a given uID
    TIGL_EXPORT CCPACSVessel const& GetVessel(std::string const& uID) const;
    TIGL_EXPORT CCPACSVessel& GetVessel(std::string const& uID);

    // Get a specific vessel for a given index.
    TIGL_EXPORT CCPACSVessel const& GetVessel(int index) const;
    TIGL_EXPORT CCPACSVessel& GetVessel(int index);

    // Returns the vessel index for a given uID.
    TIGL_EXPORT int GetVesselIndex(const std::string& uID) const;

    // Returns the total count of fuselages in a configuration
    TIGL_EXPORT int GetVesselsCount() const;

private:
};

} //namespace tigl
