#include "memory.h"
#include <thread>
#include <iostream>

int main() {

	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(2));

		uintptr_t localPlayer = VARS::memRead<uintptr_t>(VARS::baseAddress + 0x16D4F48);

		if (!localPlayer) {


			continue;
		}
		int32_t m_fFlags = VARS::memRead<int32_t>(localPlayer + 0x3C8);

		if (GetAsyncKeyState(VK_SPACE) && m_fFlags & (1 << 0)) {

			VARS::memWrite(VARS::baseAddress + 0x16CE390, 65537);
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
			VARS::memWrite(VARS::baseAddress + 0x16CE390, 256);
		}






	}




	return 0;
}