/****************************************************************************
 * Copyright (C) 2014, <Copyright Holder>                                   *
 * All rights reserved                                                      *
 *                                                                          *
 * For the licensing terms see LICENSE file inside the root directory.      *
 * For the list of contributors see AUTHORS file inside the root directory. *
 ***************************************************************************/
#ifndef SRC_APP_H_
#define SRC_APP_H_

#include <iostream>

using namespace std;

class App {

public:
  string getProjectName() const;
  string getProjectCodeName() const;
  string getProjectVendorID() const;
  string getProjectVendorName() const;
  string getProjectID() const;
  int getProjectMajorVersion() const;
  int getProjectMinorVersion() const;
  int getProjectPatchVersion() const;
  string getProjectVersion() const;
  string getProjectCopyrightYears() const;
};

#endif
