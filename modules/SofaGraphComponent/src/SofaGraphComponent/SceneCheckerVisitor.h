/******************************************************************************
*                 SOFA, Simulation Open-Framework Architecture                *
*                    (c) 2006 INRIA, USTL, UJF, CNRS, MGH                     *
*                                                                             *
* This program is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This program is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this program. If not, see <http://www.gnu.org/licenses/>.        *
*******************************************************************************
* Authors: The SOFA Team and external contributors (see Authors.txt)          *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/
#pragma once

#include <SofaGraphComponent/config.h>
#include <SofaGraphComponent/SceneCheck.h>

#include <functional>
#include <map>

#include <sofa/simulation/Visitor.h>

namespace sofa::simulation::_scenechecking_
{

class SOFA_SOFAGRAPHCOMPONENT_API SceneCheckerVisitor : public Visitor
{
public:
    SceneCheckerVisitor(const sofa::core::ExecParams* params = sofa::core::ExecParams::defaultInstance()) ;
    ~SceneCheckerVisitor() override;

    void validate(Node* node) ;
    Result processNodeTopDown(Node* node) override ;

    void addCheck(SceneCheck::SPtr check) ;
    void removeCheck(SceneCheck::SPtr check) ;

private:
    std::vector<SceneCheck::SPtr> m_checkset ;
};

} // namespace sofa::simulation::_scenechecking_

namespace sofa::simulation::scenechecking
{
    using _scenechecking_::SceneCheckerVisitor;
} // namespace sofa::simulation::scenechecking