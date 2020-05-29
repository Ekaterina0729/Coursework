#include "../src/header.h"
#include "testparty/catch.hpp"

using namespace std;

TEST_CASE("DATA")
{
    CHECK(data("want") == 1);
    CHECK(data("вуца") == 0);
    CHECK(data("FDWEFdwq") == 0);
    CHECK(data("wedfwfjfkfwefjwejkfkjwefjkwefjkewfjkwefjkewfjkewfjkkjewjkewkj")
          == 0);
    CHECK(data("!@$#") == 0);
    CHECK(data("32435") == 0);
}
