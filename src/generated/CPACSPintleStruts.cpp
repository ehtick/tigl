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

#include <cassert>
#include "CPACSLandingGearComponentAssembly.h"
#include "CPACSPintleStruts.h"
#include "CPACSStrutAssembly.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSPintleStruts::CPACSPintleStruts(CPACSLandingGearComponentAssembly* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSPintleStruts::~CPACSPintleStruts()
    {
    }

    const CPACSLandingGearComponentAssembly* CPACSPintleStruts::GetParent() const
    {
        return m_parent;
    }

    CPACSLandingGearComponentAssembly* CPACSPintleStruts::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSPintleStruts::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSPintleStruts::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSPintleStruts::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSPintleStruts::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSPintleStruts::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element pintleStrut
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/pintleStrut")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/pintleStrut", m_pintleStruts, 1, 2, this, m_uidMgr);
        }

    }

    void CPACSPintleStruts::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element pintleStrut
        tixi::TixiSaveElements(tixiHandle, xpath + "/pintleStrut", m_pintleStruts);

    }

    const std::vector<std::unique_ptr<CPACSStrutAssembly>>& CPACSPintleStruts::GetPintleStruts() const
    {
        return m_pintleStruts;
    }

    std::vector<std::unique_ptr<CPACSStrutAssembly>>& CPACSPintleStruts::GetPintleStruts()
    {
        return m_pintleStruts;
    }

    size_t CPACSPintleStruts::GetPintleStrutCount() const
    {
        return m_pintleStruts.size();
    }

    size_t CPACSPintleStruts::GetPintleStrutIndex(const std::string& UID) const
    {
        for (size_t i=0; i < GetPintleStrutCount(); i++) {
            const std::string tmpUID(m_pintleStruts[i]->GetUID());
            if (tmpUID == UID) {
                return i+1;
            }
        }
        throw CTiglError("Invalid UID in CPACSPintleStruts::GetPintleStrutIndex", TIGL_UID_ERROR);
    }

    CPACSStrutAssembly& CPACSPintleStruts::GetPintleStrut(size_t index)
    {
        if (index < 1 || index > GetPintleStrutCount()) {
            throw CTiglError("Invalid index in std::vector<std::unique_ptr<CPACSStrutAssembly>>::GetPintleStrut", TIGL_INDEX_ERROR);
        }
        index--;
        return *m_pintleStruts[index];
    }

    const CPACSStrutAssembly& CPACSPintleStruts::GetPintleStrut(size_t index) const
    {
        if (index < 1 || index > GetPintleStrutCount()) {
            throw CTiglError("Invalid index in std::vector<std::unique_ptr<CPACSStrutAssembly>>::GetPintleStrut", TIGL_INDEX_ERROR);
        }
        index--;
        return *m_pintleStruts[index];
    }

    CPACSStrutAssembly& CPACSPintleStruts::GetPintleStrut(const std::string& UID)
    {
        for (auto& elem : m_pintleStruts ) {
            if (elem->GetUID() == UID)
                return *elem;
            }
            throw CTiglError("Invalid UID in CPACSPintleStruts::GetPintleStrut. \""+ UID + "\" not found in CPACS file!" , TIGL_UID_ERROR);
    }

    const CPACSStrutAssembly& CPACSPintleStruts::GetPintleStrut(const std::string& UID) const
    {
        for (auto& elem : m_pintleStruts ) {
            if (elem->GetUID() == UID)
                return *elem;
            }
            throw CTiglError("Invalid UID in CPACSPintleStruts::GetPintleStrut. \""+ UID + "\" not found in CPACS file!" , TIGL_UID_ERROR);
    }


    CPACSStrutAssembly& CPACSPintleStruts::AddPintleStrut()
    {
        m_pintleStruts.push_back(make_unique<CPACSStrutAssembly>(this, m_uidMgr));
        return *m_pintleStruts.back();
    }

    void CPACSPintleStruts::RemovePintleStrut(CPACSStrutAssembly& ref)
    {
        for (std::size_t i = 0; i < m_pintleStruts.size(); i++) {
            if (m_pintleStruts[i].get() == &ref) {
                m_pintleStruts.erase(m_pintleStruts.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl
