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
#include <CCPACSAircraftModel.h>
#include "CPACSAircraft.h"
#include "CPACSVehicles.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSAircraft::CPACSAircraft(CPACSVehicles* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSAircraft::~CPACSAircraft()
    {
    }

    const CPACSVehicles* CPACSAircraft::GetParent() const
    {
        return m_parent;
    }

    CPACSVehicles* CPACSAircraft::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSAircraft::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSAircraft::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSAircraft::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSAircraft::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSAircraft::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element model
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/model")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/model", m_models, 1, tixi::xsdUnbounded, this, m_uidMgr);
        }

    }

    void CPACSAircraft::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element model
        tixi::TixiSaveElements(tixiHandle, xpath + "/model", m_models);

    }

    const std::vector<std::unique_ptr<CCPACSAircraftModel>>& CPACSAircraft::GetModels() const
    {
        return m_models;
    }

    std::vector<std::unique_ptr<CCPACSAircraftModel>>& CPACSAircraft::GetModels()
    {
        return m_models;
    }

    size_t CPACSAircraft::GetModelCount() const
    {
        return m_models.size();
    }

    size_t CPACSAircraft::GetModelIndex(const std::string& UID) const
    {
        for (size_t i=0; i < GetModelCount(); i++) {
            const std::string tmpUID(m_models[i]->GetUID());
            if (tmpUID == UID) {
                return i+1;
            }
        }
        throw CTiglError("Invalid UID in CPACSAircraft::GetModelIndex", TIGL_UID_ERROR);
    }

    CCPACSAircraftModel& CPACSAircraft::GetModel(size_t index)
    {
        if (index < 1 || index > GetModelCount()) {
            throw CTiglError("Invalid index in std::vector<std::unique_ptr<CCPACSAircraftModel>>::GetModel", TIGL_INDEX_ERROR);
        }
        index--;
        return *m_models[index];
    }

    const CCPACSAircraftModel& CPACSAircraft::GetModel(size_t index) const
    {
        if (index < 1 || index > GetModelCount()) {
            throw CTiglError("Invalid index in std::vector<std::unique_ptr<CCPACSAircraftModel>>::GetModel", TIGL_INDEX_ERROR);
        }
        index--;
        return *m_models[index];
    }

    CCPACSAircraftModel& CPACSAircraft::GetModel(const std::string& UID)
    {
        for (auto& elem : m_models ) {
            if (elem->GetUID() == UID)
                return *elem;
            }
            throw CTiglError("Invalid UID in CPACSAircraft::GetModel. \""+ UID + "\" not found in CPACS file!" , TIGL_UID_ERROR);
    }

    const CCPACSAircraftModel& CPACSAircraft::GetModel(const std::string& UID) const
    {
        for (auto& elem : m_models ) {
            if (elem->GetUID() == UID)
                return *elem;
            }
            throw CTiglError("Invalid UID in CPACSAircraft::GetModel. \""+ UID + "\" not found in CPACS file!" , TIGL_UID_ERROR);
    }


    CCPACSAircraftModel& CPACSAircraft::AddModel()
    {
        m_models.push_back(make_unique<CCPACSAircraftModel>(this, m_uidMgr));
        return *m_models.back();
    }

    void CPACSAircraft::RemoveModel(CCPACSAircraftModel& ref)
    {
        for (std::size_t i = 0; i < m_models.size(); i++) {
            if (m_models[i].get() == &ref) {
                m_models.erase(m_models.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl
