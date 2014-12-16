#include <cstdlib>
#include <iostream>
#include "app.h"

using namespace std;

int main() {

    App app;
    cout << "Hello, " << app.getProjectName() << endl;

    return EXIT_SUCCESS;
}
