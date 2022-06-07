#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <sstream>
#include <string>


extern "C"{

#include "ssd1322.h"
#include "timer.h"
#include "ssd1322.c"
#include "display_comm.h"

}

using namespace testing;

//TEST(nhd31225664ucb2,GIVEN_DisplayAndArea_WHEN_ClearFunctionIsCalled_THEN_)
