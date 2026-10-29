#include <doctest.h>

#include "UI/Inventory/ItemDataParser.h"

#include <array>

TEST_CASE("extended item data preserves the guardian option flag")
{
    constexpr std::uint8_t guardianFlag = 0x40;
    const std::array<std::uint8_t, 5> itemData{0, 0, 0, 1, guardianFlag};

    const auto params = ParseItemData(itemData);

    CHECK(params.HasGuardianOption);
}
