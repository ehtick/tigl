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
#include "CPACSCargoContainerElement.h"
#include "CPACSCargoContainerElements.h"
#include "CPACSDeckElements.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSCargoContainerElements::CPACSCargoContainerElements(CPACSDeckElements* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSCargoContainerElements::~CPACSCargoContainerElements()
    {
    }

    const CPACSDeckElements* CPACSCargoContainerElements::GetParent() const
    {
        return m_parent;
    }

    CPACSDeckElements* CPACSCargoContainerElements::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSCargoContainerElements::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSCargoContainerElements::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSCargoContainerElements::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSCargoContainerElements::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSCargoContainerElements::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element cargoContainerElement
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/cargoContainerElement")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/cargoContainerElement", m_cargoContainerElements, 1, tixi::xsdUnbounded, this, m_uidMgr);
        }

    }

    void CPACSCargoContainerElements::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element cargoContainerElement
        tixi::TixiSaveElements(tixiHandle, xpath + "/cargoContainerElement", m_cargoContainerElements);

    }

    const std::vector<std::unique_ptr<CPACSCargoContainerElement>>& CPACSCargoContainerElements::GetCargoContainerElements() const
    {
        return m_cargoContainerElements;
    }

    std::vector<std::unique_ptr<CPACSCargoContainerElement>>& CPACSCargoContainerElements::GetCargoContainerElements()
    {
        return m_cargoContainerElements;
    }

    size_t CPACSCargoContainerElements::GetCargoContainerElementCount() const
    {
        return m_cargoContainerElements.size();
    }

    size_t CPACSCargoContainerElements::GetCargoContainerElementIndex(const std::string& UID) const
    {
        for (size_t i=0; i < GetCargoContainerElementCount(); i++) {
            const std::string tmpUID(m_cargoContainerElements[i]->GetUID());
            if (tmpUID == UID) {
                return i+1;
            }
        }
        throw CTiglError("Invalid UID in CPACSCargoContainerElements::GetCargoContainerElementIndex", TIGL_UID_ERROR);
    }

    CPACSCargoContainerElement& CPACSCargoContainerElements::GetCargoContainerElement(size_t index)
    {
        if (index < 1 || index > GetCargoContainerElementCount()) {
            throw CTiglError("Invalid index in std::vector<std::unique_ptr<CPACSCargoContainerElement>>::GetCargoContainerElement", TIGL_INDEX_ERROR);
        }
        index--;
        return *m_cargoContainerElements[index];
    }

    const CPACSCargoContainerElement& CPACSCargoContainerElements::GetCargoContainerElement(size_t index) const
    {
        if (index < 1 || index > GetCargoContainerElementCount()) {
            throw CTiglError("Invalid index in std::vector<std::unique_ptr<CPACSCargoContainerElement>>::GetCargoContainerElement", TIGL_INDEX_ERROR);
        }
        index--;
        return *m_cargoContainerElements[index];
    }

    CPACSCargoContainerElement& CPACSCargoContainerElements::GetCargoContainerElement(const std::string& UID)
    {
        for (auto& elem : m_cargoContainerElements ) {
            if (elem->GetUID() == UID)
                return *elem;
            }
            throw CTiglError("Invalid UID in CPACSCargoContainerElements::GetCargoContainerElement. \""+ UID + "\" not found in CPACS file!" , TIGL_UID_ERROR);
    }

    const CPACSCargoContainerElement& CPACSCargoContainerElements::GetCargoContainerElement(const std::string& UID) const
    {
        for (auto& elem : m_cargoContainerElements ) {
            if (elem->GetUID() == UID)
                return *elem;
            }
            throw CTiglError("Invalid UID in CPACSCargoContainerElements::GetCargoContainerElement. \""+ UID + "\" not found in CPACS file!" , TIGL_UID_ERROR);
    }


    CPACSCargoContainerElement& CPACSCargoContainerElements::AddCargoContainerElement()
    {
        m_cargoContainerElements.push_back(make_unique<CPACSCargoContainerElement>(this, m_uidMgr));
        return *m_cargoContainerElements.back();
    }

    void CPACSCargoContainerElements::RemoveCargoContainerElement(CPACSCargoContainerElement& ref)
    {
        for (std::size_t i = 0; i < m_cargoContainerElements.size(); i++) {
            if (m_cargoContainerElements[i].get() == &ref) {
                m_cargoContainerElements.erase(m_cargoContainerElements.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl
