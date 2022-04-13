#pragma once

namespace Pizza {

	__declspec(dllimport) void Print();

}

void main() {
	Pizza::Print();
}