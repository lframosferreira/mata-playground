// TODO: Modify when copying to target `/mata/tests-integration/src/utils/`.
#include "../utils/utils.hh"
#include "../utils/config.hh"

#include "mata/nfa/nfa.hh"

#include <iostream>
#include <iomanip>
#include <chrono>
#include <string>

using namespace mata::nfa;

int main() {
    // Setting precision of the times to fixed points and 4 decimal places
    std::cout << std::fixed << std::setprecision(4);

    TIME_BEGIN(tmp);

    /**************************************************
     * TODO: HERE COMES YOUR CODE YOU WANT TO PROFILE *
     **************************************************/

    TIME_END(tmp);

    return EXIT_SUCCESS;
}
