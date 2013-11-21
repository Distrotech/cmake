/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2013 Stephen Kelly <steveire@gmail.com>

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/
#include "cmTargetCompileFeaturesCommand.h"

bool cmTargetCompileFeaturesCommand::InitialPass(
  std::vector<std::string> const& args,
  cmExecutionStatus &)
{
  if (args.size() < 3)
    {
      this->SetError("called with wrong number of arguments.");
      return false;
    }
  cmTarget *target = this->Makefile->FindTargetToUse(args[0].c_str());

  if(!target)
    {
    this->SetError("specified invalid target.");
    return false;
    }

  if(target->IsImported())
    {
    this->SetError("may not be used with an IMPORTED target.");
    return false;
    }

  if(args[1] != "PRIVATE")
    {
    this->SetError("called with invalid arguments.");
    return false;
    }

  for (size_t i = 2; i < args.size(); ++i)
    {
    std::string feature = args[i];

    if (!this->Makefile->AddRequiredTargetFeature(target, feature.c_str()))
      {
      cmOStringStream e;
      e << "specified unknown feature \"" << feature << "\".";
      this->SetError(e.str().c_str());
      return false;
      }
    }
  return true;
}
