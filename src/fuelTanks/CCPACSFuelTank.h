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
* @brief  Implementation of CPACS fuelTank handling routines.
*/

#pragma once

#include "generated/CPACSFuelTank.h"
#include "CTiglRelativelyPositionedComponent.h"
#include "CCPACSConfiguration.h"

namespace tigl
{

class CCPACSFuelTank : public generated::CPACSFuelTank, public CTiglRelativelyPositionedComponent
{
public:
    TIGL_EXPORT CCPACSFuelTank(CCPACSFuelTanks* parent, CTiglUIDManager* uidMgr);

    TIGL_EXPORT CCPACSConfiguration const& GetConfiguration() const;

    TIGL_EXPORT std::string GetDefaultedUID() const override;
    TIGL_EXPORT TiglGeometricComponentType GetComponentType() const override;
    TIGL_EXPORT TiglGeometricComponentIntent GetComponentIntent() const override;

protected:
    PNamedShape BuildLoft() const override;

private:
    void InvalidateImpl(const boost::optional<std::string>&) const override;

    std::string GetShortShapeName() const;

    std::vector<std::function<void()>> invalidationCallbacks;
};

} //namespace tigl
