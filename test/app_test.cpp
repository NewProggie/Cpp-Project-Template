#include <string.h>
#include "gtest/gtest.h"

#include "../src/appinfo.h"
#include "../src/app.h"

/* to use a test fixture, we derive from testing::Test */
class AppTest : public testing::Test {

protected:
    /* will be called before each test is run */
    virtual void SetUp() {
        app = new App();
    }

    /* will be called after each test is run */
    virtual void TearDown() {
        delete app;
    }
    App *app;
};

/* using test fixture with TEST_F instead of TEST */
TEST_F(AppTest, GetProjectName) {
    ASSERT_STREQ(app->getProjectName().c_str(), APPLICATION_NAME);
}

TEST_F(AppTest, GetProjectDetails) {
    ASSERT_STREQ(app->getProjectCodeName().c_str(), APPLICATION_CODENAME);
    ASSERT_STREQ(app->getProjectVendorID().c_str(), APPLICATION_VENDOR_ID);
    ASSERT_STREQ(app->getProjectVendorName().c_str(), APPLICATION_VENDOR_NAME);
    ASSERT_STREQ(app->getProjectID().c_str(), APPLICATION_ID);
    ASSERT_EQ(app->getProjectMajorVersion(), APPLICATION_VERSION_MAJOR);
    ASSERT_EQ(app->getProjectMinorVersion(), APPLICATION_VERSION_MINOR);
    ASSERT_EQ(app->getProjectPatchVersion(), APPLICATION_VERSION_PATCH);
    ASSERT_STREQ(app->getProjectVersion().c_str(), APPLICATION_VERSION_STRING);
    ASSERT_STREQ(app->getProjectCopyrightYears().c_str(), APPLICATION_COPYRIGHT_YEARS);
}
