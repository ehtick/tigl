/*
* Copyright (c) 2018 RISC Software GmbH
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

#pragma once

#include "generated/CPACSPoint.h"
#include "CTiglPoint.h"

namespace tigl
{
class CCPACSPoint : public generated::CPACSPoint
{
public:
    TIGL_EXPORT CCPACSPoint(CCPACSControlSurfaceStep* parent, CTiglUIDManager* uidMgr);
    TIGL_EXPORT CCPACSPoint(CCPACSControlSurfaceHingePoint* parent, CTiglUIDManager* uidMgr);
    TIGL_EXPORT CCPACSPoint(CCPACSPointList* parent, CTiglUIDManager* uidMgr);
    TIGL_EXPORT CCPACSPoint(CCPACSBoundingBox* parent, CTiglUIDManager* uidMgr);
    TIGL_EXPORT CCPACSPoint(CCPACSDeckElementMass* parent, CTiglUIDManager* uidMgr);
    TIGL_EXPORT CCPACSPoint(CCPACSTransformation* parent, CTiglUIDManager* uidMgr);

    TIGL_EXPORT CCPACSPoint(const CCPACSPoint& p);
    TIGL_EXPORT CCPACSPoint& operator=(const CCPACSPoint&);

    TIGL_EXPORT CTiglPoint AsPoint() const; // missing coordinates default to zero
    TIGL_EXPORT void SetAsPoint(const CTiglPoint& point);

    TIGL_EXPORT void SetX(const boost::optional<double>& value) override;
    TIGL_EXPORT void SetY(const boost::optional<double>& value) override;
    TIGL_EXPORT void SetZ(const boost::optional<double>& value) override;

private:
    void InvalidateImpl(const boost::optional<std::string>& source) const override;
};

} // namespace tigl
