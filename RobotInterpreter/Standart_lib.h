#pragma once
#include"Memory.h"
namespace language {
	enum class Sides
	{
		FRONT,
		BACK,
		RIGHT,
		LEFT
	};
	MemoryCell look_at(Sides);
}
