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

#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
#include <string>
#include <tixi.h>
#include <typeinfo>
#include "CPACSSkinSegments.h"
#include "CreateIfNotExists.h"
#include "CTiglError.h"
#include "ITiglUIDRefObject.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CTiglUIDObject;
class CCPACSDuctStructure;
class CCPACSFuselageStructure;

namespace generated
{
    class CPACSVesselSkinLayers;

    // This class is used in:
    // CPACSDuctStructure
    // CPACSFuselageStructure
    // CPACSVesselSkinLayers

    /// @brief skinType
    /// 
    /// Containing data defining the skin
    /// 
    class CPACSSkin : public ITiglUIDRefObject
    {
    public:
        TIGL_EXPORT CPACSSkin(CCPACSDuctStructure* parent, CTiglUIDManager* uidMgr);
        TIGL_EXPORT CPACSSkin(CCPACSFuselageStructure* parent, CTiglUIDManager* uidMgr);
        TIGL_EXPORT CPACSSkin(CPACSVesselSkinLayers* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSSkin();

        template<typename P>
        bool IsParent() const
        {
            return m_parentType != NULL && *m_parentType == typeid(P);
        }

        template<typename P>
        P* GetParent()
        {
            static_assert(std::is_same<P, CCPACSDuctStructure>::value || std::is_same<P, CCPACSFuselageStructure>::value || std::is_same<P, CPACSVesselSkinLayers>::value, "template argument for P is not a parent class of CPACSSkin");
            if (!IsParent<P>()) {
                throw CTiglError("bad parent");
            }
            return static_cast<P*>(m_parent);
        }

        template<typename P>
        const P* GetParent() const
        {
            static_assert(std::is_same<P, CCPACSDuctStructure>::value || std::is_same<P, CCPACSFuselageStructure>::value || std::is_same<P, CPACSVesselSkinLayers>::value, "template argument for P is not a parent class of CPACSSkin");
            if (!IsParent<P>()) {
                throw CTiglError("bad parent");
            }
            return static_cast<P*>(m_parent);
        }

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const boost::optional<std::string>& GetStandardSheetElementUID() const;
        TIGL_EXPORT virtual void SetStandardSheetElementUID(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const boost::optional<CPACSSkinSegments>& GetSkinSegments() const;
        TIGL_EXPORT virtual boost::optional<CPACSSkinSegments>& GetSkinSegments();

        TIGL_EXPORT virtual CPACSSkinSegments& GetSkinSegments(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveSkinSegments();

    protected:
        void* m_parent;
        const std::type_info* m_parentType;

        CTiglUIDManager* m_uidMgr;

        /// Default UID of sheetBasedStructuralElement
        /// used for the fuselage skin not covered by individual panels
        boost::optional<std::string>       m_standardSheetElementUID;

        boost::optional<CPACSSkinSegments> m_skinSegments;

    private:
        TIGL_EXPORT const CTiglUIDObject* GetNextUIDObject() const final;
        TIGL_EXPORT void NotifyUIDChange(const std::string& oldUid, const std::string& newUid) final;

        CPACSSkin(const CPACSSkin&) = delete;
        CPACSSkin& operator=(const CPACSSkin&) = delete;

        CPACSSkin(CPACSSkin&&) = delete;
        CPACSSkin& operator=(CPACSSkin&&) = delete;
    };
} // namespace generated

// CPACSSkin is customized, use type CCPACSSkin directly

// Aliases in tigl namespace
using CCPACSVesselSkinLayers = generated::CPACSVesselSkinLayers;
} // namespace tigl
