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

namespace generated
{
    class CPACSPointPerformanceDefinition;
    class CPACSGlobalPerformanceCases;

    // This class is used in:
    // CPACSGlobalPerformanceCases

    /// @brief Point performance definitions
    /// 
    /// List of point performance definitions
    /// 
    class CPACSPointPerformanceDefinitions
    {
    public:
        TIGL_EXPORT CPACSPointPerformanceDefinitions(CPACSGlobalPerformanceCases* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSPointPerformanceDefinitions();

        TIGL_EXPORT CPACSGlobalPerformanceCases* GetParent();

        TIGL_EXPORT const CPACSGlobalPerformanceCases* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::vector<std::unique_ptr<CPACSPointPerformanceDefinition>>& GetPointPerformanceDefinitions() const;
        TIGL_EXPORT virtual std::vector<std::unique_ptr<CPACSPointPerformanceDefinition>>& GetPointPerformanceDefinitions();

        TIGL_EXPORT virtual size_t GetPointPerformanceDefinitionCount() const;
        TIGL_EXPORT virtual size_t GetPointPerformanceDefinitionIndex(const std::string& UID) const;

        TIGL_EXPORT virtual const CPACSPointPerformanceDefinition& GetPointPerformanceDefinition(size_t index) const;
        TIGL_EXPORT virtual CPACSPointPerformanceDefinition& GetPointPerformanceDefinition(size_t index);

        TIGL_EXPORT virtual const CPACSPointPerformanceDefinition& GetPointPerformanceDefinition(const std::string& UID) const;
        TIGL_EXPORT virtual CPACSPointPerformanceDefinition& GetPointPerformanceDefinition(const std::string& UID);

        TIGL_EXPORT virtual CPACSPointPerformanceDefinition& AddPointPerformanceDefinition();
        TIGL_EXPORT virtual void RemovePointPerformanceDefinition(CPACSPointPerformanceDefinition& ref);

    protected:
        CPACSGlobalPerformanceCases* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::vector<std::unique_ptr<CPACSPointPerformanceDefinition>> m_pointPerformanceDefinitions;

    private:
        CPACSPointPerformanceDefinitions(const CPACSPointPerformanceDefinitions&) = delete;
        CPACSPointPerformanceDefinitions& operator=(const CPACSPointPerformanceDefinitions&) = delete;

        CPACSPointPerformanceDefinitions(CPACSPointPerformanceDefinitions&&) = delete;
        CPACSPointPerformanceDefinitions& operator=(CPACSPointPerformanceDefinitions&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSPointPerformanceDefinitions = generated::CPACSPointPerformanceDefinitions;
using CCPACSPointPerformanceDefinition = generated::CPACSPointPerformanceDefinition;
using CCPACSGlobalPerformanceCases = generated::CPACSGlobalPerformanceCases;
} // namespace tigl
