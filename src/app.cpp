#include "app.h"
#include "appinfo.h"

string App::getProjectName() const {
    return APPLICATION_NAME;
}

string App::getProjectCodeName() const {
    return APPLICATION_CODENAME;
}

string App::getProjectVendorID() const {
    return APPLICATION_VENDOR_ID;
}

string App::getProjectVendorName() const {
    return APPLICATION_VENDOR_NAME;
}

string App::getProjectID() const {
    return APPLICATION_ID;
}

int App::getProjectMajorVersion() const {
    return APPLICATION_VERSION_MAJOR;
}

int App::getProjectMinorVersion() const {
    return APPLICATION_VERSION_MINOR;
}

int App::getProjectPatchVersion() const {
    return APPLICATION_VERSION_PATCH;
}

string App::getProjectVersion() const {
    return APPLICATION_VERSION_STRING;
}

string App::getProjectCopyrightYears() const {
    return APPLICATION_COPYRIGHT_YEARS;
}

