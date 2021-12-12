#pragma once
#include "Standart_lib.h"
namespace language {

}
namespace robot {
	using namespace language;
	class Robot {
	private:
		Square position;
		bool isOnFly;
	public:
		MemoryCell look_at(Sides);
		void go_to(Sides);
		void turn_to(Sides);
		void fly();
		void stop();
		MemoryCell where_am_I();
	};
	
	
}