#include <gtest/gtest.h>
#include "Soundex.h"



char arr_with_ret_1[4] = {'B','F','P','V'};
char arr_with_ret_2[8] = {'C','G','J','K','Q','S','X','Z'};
char arr_with_ret_3[2] = {'D','T'};
char arr_with_ret_4[1] = {'L'};
char arr_with_ret_5[2] = {'M','N'};
char arr_with_ret_6[1] = {'R'};

TEST(SoundexTest_numerical, GetSoundexCode)
{
    EXPECT_EQ(getSoundexCode('1'), '0'); // numerical value
}


// Test cases for generateSoundex function
TEST(SoundexTest_cases, GenerateSoundex) {
    char soundex[5];

    generateSoundex("Bosch", soundex);
    EXPECT_STREQ(soundex, "B200");

    generateSoundex("Tymczak", soundex); 
    EXPECT_STREQ(soundex, "T520");

    generateSoundex("J1o2h3n4", soundex); // alpha numnerical
    EXPECT_STREQ(soundex, "J500");

    generateSoundex("123TCQ", soundex); //numerical value first
    EXPECT_STREQ(soundex, "1320");

    generateSoundex("TCQ", soundex); //less than 4 characters
    EXPECT_STREQ(soundex, "T200");

    generateSoundex("", soundex); //Empty condition
    EXPECT_STREQ(soundex, "");

}

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
  EXPECT_STREQ(soundex,"A200");
}

