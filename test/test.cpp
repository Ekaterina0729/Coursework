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
TEST_CASE("REZULT")
{
    struct verb slova[100];
    CHECK(rezult(150, slova) == 0);
    CHECK(rezult(-10, slova) == 0);
    CHECK(rezult(50, slova) == 0);
}
TEST_CASE("READ_VERB")
{
    struct verb slova[100];
    CHECK(read_verb(" ghehj.txt", slova) == 1);
    CHECK(read_verb("weefg", slova) == 1);
    CHECK(read_verb("ahhkhkg", slova) == 1);
    CHECK(read_verb("Slovar.txt", slova) >= 0);
    CHECK(read_verb("Slovar2.txt", slova) >= 0);
}
TEST_CASE("NEWTEST")
{
    CHECK(new_test("./src/tiyfvgkyt5.txt", "./src/ytfyt.txt") == 0);
    CHECK(new_test("Slovar2.txt", "Rezultat.txt") == 0);
    CHECK(new_test(" ", " ") == 0);
    CHECK(new_test("./src/фыва.txt", "./src/нгшщз.txt") == 0);
    CHECK(new_test("./src/Slovar2.txt", "./src/Rezultat.txt") == 0);
}
TEST_CASE("NEXTVERBS")
{
    struct glag user;
    struct verb slova[100];
    int i=read_verb("./src/Slovar.txt",slova);
    CHECK(verbs_next(slova,user,5,0,1,150)==0);
    CHECK(verbs_next(slova, user, 5, 0, 1, 40) == 0);
}
