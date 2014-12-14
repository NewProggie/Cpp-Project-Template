#include <iostream>
#include "app.h"

using namespace std;

int main(int argc, char *argv[]) {

    App app;
    std::cout << "Hello, " << app.getProjectName() << std::endl;

    return 0;
}
