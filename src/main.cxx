#include <iostream>
#include "app.h"

using namespace std;

int main(int argc, char *argv[]) {

    App app;
    cout << "Hello, " << app.getProjectName() << endl;

    return 0;
}
