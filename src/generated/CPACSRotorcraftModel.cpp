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
#include "CPACSRotorcraft.h"
#include "CPACSRotorcraftModel.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSRotorcraftModel::CPACSRotorcraftModel(CPACSRotorcraft* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSRotorcraftModel::~CPACSRotorcraftModel()
    {
        if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
    }

    const CPACSRotorcraft* CPACSRotorcraftModel::GetParent() const
    {
        return m_parent;
    }

    CPACSRotorcraft* CPACSRotorcraftModel::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSRotorcraftModel::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSRotorcraftModel::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSRotorcraftModel::GetUIDManager()
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSRotorcraftModel::GetUIDManager() const
    {
        if (!m_uidMgr) {
            throw CTiglError("UIDManager is null");
        }
        return *m_uidMgr;
    }

    void CPACSRotorcraftModel::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read attribute uID
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
            m_uID = tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            if (m_uID.empty()) {
                LOG(WARNING) << "Required attribute uID is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required attribute uID is missing at xpath " << xpath;
        }

        // read element name
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/name")) {
            m_name = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/name");
            if (m_name.empty()) {
                LOG(WARNING) << "Required element name is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required element name is missing at xpath " << xpath;
        }

        // read element description
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/description")) {
            m_description = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/description");
            if (m_description->empty()) {
                LOG(WARNING) << "Optional element description is present but empty at xpath " << xpath;
            }
        }

        // read element fuselages
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/fuselages")) {
            m_fuselages = boost::in_place(reinterpret_cast<CCPACSRotorcraftModel*>(this), m_uidMgr);
            try {
                m_fuselages->ReadCPACS(tixiHandle, xpath + "/fuselages");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read fuselages at xpath " << xpath << ": " << e.what();
                m_fuselages = boost::none;
            }
        }

        // read element wings
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/wings")) {
            m_wings = boost::in_place(reinterpret_cast<CCPACSRotorcraftModel*>(this), m_uidMgr);
            try {
                m_wings->ReadCPACS(tixiHandle, xpath + "/wings");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read wings at xpath " << xpath << ": " << e.what();
                m_wings = boost::none;
            }
        }

        // read element rotors
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/rotors")) {
            m_rotors = boost::in_place(reinterpret_cast<CCPACSRotorcraftModel*>(this), m_uidMgr);
            try {
                m_rotors->ReadCPACS(tixiHandle, xpath + "/rotors");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read rotors at xpath " << xpath << ": " << e.what();
                m_rotors = boost::none;
            }
        }

        // read element rotorBlades
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/rotorBlades")) {
            m_rotorBlades = boost::in_place(reinterpret_cast<CCPACSRotorcraftModel*>(this), m_uidMgr);
            try {
                m_rotorBlades->ReadCPACS(tixiHandle, xpath + "/rotorBlades");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read rotorBlades at xpath " << xpath << ": " << e.what();
                m_rotorBlades = boost::none;
            }
        }

        // read element engines
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/engines")) {
            m_engines = boost::in_place(reinterpret_cast<CCPACSRotorcraftModel*>(this), m_uidMgr);
            try {
                m_engines->ReadCPACS(tixiHandle, xpath + "/engines");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read engines at xpath " << xpath << ": " << e.what();
                m_engines = boost::none;
            }
        }

        // read element systems
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/systems")) {
            m_systems = boost::in_place(reinterpret_cast<CCPACSRotorcraftModel*>(this), m_uidMgr);
            try {
                m_systems->ReadCPACS(tixiHandle, xpath + "/systems");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read systems at xpath " << xpath << ": " << e.what();
                m_systems = boost::none;
            }
        }

        if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
    }

    void CPACSRotorcraftModel::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write attribute uID
        tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);

        // write element name
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/name");
        tixi::TixiSaveElement(tixiHandle, xpath + "/name", m_name);

        // write element description
        if (m_description) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/description");
            tixi::TixiSaveElement(tixiHandle, xpath + "/description", *m_description);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/description")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/description");
            }
        }

        // write element fuselages
        if (m_fuselages) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/fuselages");
            m_fuselages->WriteCPACS(tixiHandle, xpath + "/fuselages");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/fuselages")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/fuselages");
            }
        }

        // write element wings
        if (m_wings) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/wings");
            m_wings->WriteCPACS(tixiHandle, xpath + "/wings");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/wings")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/wings");
            }
        }

        // write element rotors
        if (m_rotors) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/rotors");
            m_rotors->WriteCPACS(tixiHandle, xpath + "/rotors");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/rotors")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/rotors");
            }
        }

        // write element rotorBlades
        if (m_rotorBlades) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/rotorBlades");
            m_rotorBlades->WriteCPACS(tixiHandle, xpath + "/rotorBlades");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/rotorBlades")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/rotorBlades");
            }
        }

        // write element engines
        if (m_engines) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/engines");
            m_engines->WriteCPACS(tixiHandle, xpath + "/engines");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/engines")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/engines");
            }
        }

        // write element systems
        if (m_systems) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/systems");
            m_systems->WriteCPACS(tixiHandle, xpath + "/systems");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/systems")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/systems");
            }
        }

    }

    const std::string& CPACSRotorcraftModel::GetUID() const
    {
        return m_uID;
    }

    void CPACSRotorcraftModel::SetUID(const std::string& value)
    {
        if (m_uidMgr && value != m_uID) {
            if (m_uID.empty()) {
                m_uidMgr->RegisterObject(value, *this);
            }
            else {
                m_uidMgr->UpdateObjectUID(m_uID, value);
            }
        }
        m_uID = value;
    }

    const std::string& CPACSRotorcraftModel::GetName() const
    {
        return m_name;
    }

    void CPACSRotorcraftModel::SetName(const std::string& value)
    {
        m_name = value;
    }

    const boost::optional<std::string>& CPACSRotorcraftModel::GetDescription() const
    {
        return m_description;
    }

    void CPACSRotorcraftModel::SetDescription(const boost::optional<std::string>& value)
    {
        m_description = value;
    }

    const boost::optional<CPACSFuselages>& CPACSRotorcraftModel::GetFuselages() const
    {
        return m_fuselages;
    }

    boost::optional<CPACSFuselages>& CPACSRotorcraftModel::GetFuselages()
    {
        return m_fuselages;
    }

    const boost::optional<CCPACSWings>& CPACSRotorcraftModel::GetWings() const
    {
        return m_wings;
    }

    boost::optional<CCPACSWings>& CPACSRotorcraftModel::GetWings()
    {
        return m_wings;
    }

    const boost::optional<CCPACSRotors>& CPACSRotorcraftModel::GetRotors() const
    {
        return m_rotors;
    }

    boost::optional<CCPACSRotors>& CPACSRotorcraftModel::GetRotors()
    {
        return m_rotors;
    }

    const boost::optional<CCPACSRotorBlades>& CPACSRotorcraftModel::GetRotorBlades() const
    {
        return m_rotorBlades;
    }

    boost::optional<CCPACSRotorBlades>& CPACSRotorcraftModel::GetRotorBlades()
    {
        return m_rotorBlades;
    }

    const boost::optional<CCPACSEnginePositions>& CPACSRotorcraftModel::GetEngines() const
    {
        return m_engines;
    }

    boost::optional<CCPACSEnginePositions>& CPACSRotorcraftModel::GetEngines()
    {
        return m_engines;
    }

    const boost::optional<CCPACSACSystems>& CPACSRotorcraftModel::GetSystems() const
    {
        return m_systems;
    }

    boost::optional<CCPACSACSystems>& CPACSRotorcraftModel::GetSystems()
    {
        return m_systems;
    }

    CPACSFuselages& CPACSRotorcraftModel::GetFuselages(CreateIfNotExistsTag)
    {
        if (!m_fuselages)
            m_fuselages = boost::in_place(reinterpret_cast<CCPACSRotorcraftModel*>(this), m_uidMgr);
        return *m_fuselages;
    }

    void CPACSRotorcraftModel::RemoveFuselages()
    {
        m_fuselages = boost::none;
    }

    CCPACSWings& CPACSRotorcraftModel::GetWings(CreateIfNotExistsTag)
    {
        if (!m_wings)
            m_wings = boost::in_place(reinterpret_cast<CCPACSRotorcraftModel*>(this), m_uidMgr);
        return *m_wings;
    }

    void CPACSRotorcraftModel::RemoveWings()
    {
        m_wings = boost::none;
    }

    CCPACSRotors& CPACSRotorcraftModel::GetRotors(CreateIfNotExistsTag)
    {
        if (!m_rotors)
            m_rotors = boost::in_place(reinterpret_cast<CCPACSRotorcraftModel*>(this), m_uidMgr);
        return *m_rotors;
    }

    void CPACSRotorcraftModel::RemoveRotors()
    {
        m_rotors = boost::none;
    }

    CCPACSRotorBlades& CPACSRotorcraftModel::GetRotorBlades(CreateIfNotExistsTag)
    {
        if (!m_rotorBlades)
            m_rotorBlades = boost::in_place(reinterpret_cast<CCPACSRotorcraftModel*>(this), m_uidMgr);
        return *m_rotorBlades;
    }

    void CPACSRotorcraftModel::RemoveRotorBlades()
    {
        m_rotorBlades = boost::none;
    }

    CCPACSEnginePositions& CPACSRotorcraftModel::GetEngines(CreateIfNotExistsTag)
    {
        if (!m_engines)
            m_engines = boost::in_place(reinterpret_cast<CCPACSRotorcraftModel*>(this), m_uidMgr);
        return *m_engines;
    }

    void CPACSRotorcraftModel::RemoveEngines()
    {
        m_engines = boost::none;
    }

    CCPACSACSystems& CPACSRotorcraftModel::GetSystems(CreateIfNotExistsTag)
    {
        if (!m_systems)
            m_systems = boost::in_place(reinterpret_cast<CCPACSRotorcraftModel*>(this), m_uidMgr);
        return *m_systems;
    }

    void CPACSRotorcraftModel::RemoveSystems()
    {
        m_systems = boost::none;
    }

} // namespace generated
} // namespace tigl
