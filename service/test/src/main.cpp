#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <smarthome/mock/all.hpp>

int main(int argc, char** argv) {

    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}