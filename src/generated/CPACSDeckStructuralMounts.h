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
    class CPACSDeckStructuralMount;
    class CPACSDeckComponent2DBase;

    // This class is used in:
    // CPACSDeckComponent2DBase

    /// @brief Structural mounts
    /// 
    /// Structural mount type containing the structural connections of cabin elements
    /// 
    class CPACSDeckStructuralMounts
    {
    public:
        TIGL_EXPORT CPACSDeckStructuralMounts(CPACSDeckComponent2DBase* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSDeckStructuralMounts();

        TIGL_EXPORT CPACSDeckComponent2DBase* GetParent();

        TIGL_EXPORT const CPACSDeckComponent2DBase* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::vector<std::unique_ptr<CPACSDeckStructuralMount>>& GetStructuralMounts() const;
        TIGL_EXPORT virtual std::vector<std::unique_ptr<CPACSDeckStructuralMount>>& GetStructuralMounts();

        TIGL_EXPORT virtual size_t GetStructuralMountCount() const;
        TIGL_EXPORT virtual size_t GetStructuralMountIndex(const std::string& UID) const;

        TIGL_EXPORT virtual const CPACSDeckStructuralMount& GetStructuralMount(size_t index) const;
        TIGL_EXPORT virtual CPACSDeckStructuralMount& GetStructuralMount(size_t index);

        TIGL_EXPORT virtual const CPACSDeckStructuralMount& GetStructuralMount(const std::string& UID) const;
        TIGL_EXPORT virtual CPACSDeckStructuralMount& GetStructuralMount(const std::string& UID);

        TIGL_EXPORT virtual CPACSDeckStructuralMount& AddStructuralMount();
        TIGL_EXPORT virtual void RemoveStructuralMount(CPACSDeckStructuralMount& ref);

    protected:
        CPACSDeckComponent2DBase* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::vector<std::unique_ptr<CPACSDeckStructuralMount>> m_structuralMounts;

    private:
        CPACSDeckStructuralMounts(const CPACSDeckStructuralMounts&) = delete;
        CPACSDeckStructuralMounts& operator=(const CPACSDeckStructuralMounts&) = delete;

        CPACSDeckStructuralMounts(CPACSDeckStructuralMounts&&) = delete;
        CPACSDeckStructuralMounts& operator=(CPACSDeckStructuralMounts&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSDeckStructuralMounts = generated::CPACSDeckStructuralMounts;
using CCPACSDeckStructuralMount = generated::CPACSDeckStructuralMount;
using CCPACSDeckComponent2DBase = generated::CPACSDeckComponent2DBase;
} // namespace tigl
