// Copyright (c) 2020 RISC Software GmbH
//
// This file was generated by CPACSGen from CPACS XML Schema (c) German Aerospace Center (DLR/SC).
// Do not edit, all changes are lost when files are re-generated.
//
// Licensed under the Apache License, Version 2.0 (the "License")
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <string>
#include <tixi.h>
#include <vector>
#include "tigl_internal.h"
#include "UniquePtr.h"

namespace tigl
{
class CTiglUIDManager;
class CTiglUIDObject;
class CCPACSWallPosition;
class CCPACSWalls;

namespace generated
{
    // This class is used in:
    // CPACSWalls

    class CPACSWallPositions
    {
    public:
        TIGL_EXPORT CPACSWallPositions(CCPACSWalls* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSWallPositions();

        TIGL_EXPORT CCPACSWalls* GetParent();

        TIGL_EXPORT const CCPACSWalls* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::vector<std::unique_ptr<CCPACSWallPosition>>& GetWallPositions() const;
        TIGL_EXPORT virtual std::vector<std::unique_ptr<CCPACSWallPosition>>& GetWallPositions();

        TIGL_EXPORT virtual size_t GetWallPositionCount() const;
        TIGL_EXPORT virtual size_t GetWallPositionIndex(const std::string& UID) const;

        TIGL_EXPORT virtual const CCPACSWallPosition& GetWallPosition(size_t index) const;
        TIGL_EXPORT virtual CCPACSWallPosition& GetWallPosition(size_t index);

        TIGL_EXPORT virtual const CCPACSWallPosition& GetWallPosition(const std::string& UID) const;
        TIGL_EXPORT virtual CCPACSWallPosition& GetWallPosition(const std::string& UID);

        TIGL_EXPORT virtual CCPACSWallPosition& AddWallPosition();
        TIGL_EXPORT virtual void RemoveWallPosition(CCPACSWallPosition& ref);

    protected:
        CCPACSWalls* m_parent;

        CTiglUIDManager* m_uidMgr;

        /// Wall position definition specifying a point in the fuselage to be connected to a wall segment.
        std::vector<std::unique_ptr<CCPACSWallPosition>> m_wallPositions;

    private:
        CPACSWallPositions(const CPACSWallPositions&) = delete;
        CPACSWallPositions& operator=(const CPACSWallPositions&) = delete;

        CPACSWallPositions(CPACSWallPositions&&) = delete;
        CPACSWallPositions& operator=(CPACSWallPositions&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSWallPositions = generated::CPACSWallPositions;
} // namespace tigl
