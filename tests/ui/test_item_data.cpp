#include "doctest.h"
#include "Core/Globals/_enum.h"
#include "UI/Inventory/ItemMng.h"

#include <array>

TEST_CASE("extended item data preserves the guardian option flag")
{
    constexpr auto guardianFlag = static_cast<BYTE>(ItemOptionFlags::HasGuardian);
    const std::array<BYTE, 5> itemData{0, 0, 0, 1, guardianFlag};

    const auto params = ParseItemData(itemData);

    CHECK(params.HasGuardianOption);
    CHECK(params.ExcellentFlags == 0);
}
