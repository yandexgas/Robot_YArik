#pragma once
#include<fstream>
#include <thread>
#include <chrono>
#include "Standart_lib.h"
namespace language {
	enum class Sides
	{
		FRONT,
		BACK,
		RIGHT,
		LEFT
	};
	enum class Commands {
		GO,
		LOOK,
		STOP,
		FLY,
		ROTATE
	};

}
namespace robot {
	using namespace language;

	class Labitinth {
	public:
		static std::vector<std::vector<bool>> walls;
		static Square exit_;
		static void print(Square& position, bool isOnFly,int rotation) {
			using namespace std::chrono_literals;
			std::this_thread::sleep_for(100ms);
			system("cls");
			int x =(int)* position.getX();
			int y = (int)*position.getY();
			int ex = (int)*exit_.getX();
			int ey = (int)*exit_.getY();
			for (int i = 0; i <walls.size(); i++) {
				for (int j = 0; j < walls[i].size() ;  j++) {
					if (walls[i][j])
						std::cout << " # ";
					else if (i == x && j == y) {
						if (isOnFly)
							std::cout << "*";
						else {
							switch (rotation)
							{
							case 0:
								std::cout << " ^ ";
								break;
							case 1:
								std::cout << " > ";
								break;
							case 2:
								std::cout << " v ";
								break;
							case 3:
								std::cout << " < ";
								break;
							}
						}
					}
					else { 
						if (i == ex && j == ey)
							std::cout << " O ";
						else
							std::cout << " . "; 
					}
				}
				std::cout << std::endl;
			}
		}
		static void moveTo(int x, int y,Square& position, bool isOnFly, bool& AllowScriptExecution){
			int nx = (int)*position.getX() + x;
			int ny = (int)*position.getY() + y;
			if (isOnFly && walls[nx][ny]) {
				nx += x;
				ny += y;
			}
			if (nx >= walls.size() || ny >= walls[0].size() || nx < 0 || ny < 0 || walls[nx][ny]) {
				AllowScriptExecution = false;
				throw Script_error("Vrezalis v stenu!");
			}
			if (nx== (int)*exit_.getX() && ny == (int)*exit_.getY()) {
				AllowScriptExecution = false;
			}
			position.setX(nx);
			position.setY(ny);
		}
		static int lookAt(int x, int y,int xdir, int ydir, bool isOnFly){
			int point;
			int distance = 0;
			if (xdir != 0) {
				for (point = x+xdir; point < walls.size() && point>=0; point += xdir ) {
					if (walls[point][y]&&!(isOnFly&&point==x+xdir))
						break;
					distance++;
				}

				if (distance == 1 && isOnFly && walls[x + xdir][y])
					distance = 0;
				return distance;
			}
			else
			{
				for (point = y +ydir; point < walls[0].size() && point>=0; point += ydir) {
					if (walls[x][point] && !(isOnFly && point == y + ydir))
						break;
					distance++;
				}

				if (distance == 1 && isOnFly && walls[x][point+ydir])
					distance = 0;
				return distance;
			}
		}
	};
	class Robot {
	private:
		static bool activated;
		constexpr static int go(Sides side){
			switch (side)
			{
			case language::Sides::FRONT:
				switch (rotation)
				{
				case 0:
					Labitinth::moveTo(-1,   0,position, isOnFly, AllowScriptExecution);
					break;
				case 1:
					Labitinth::moveTo(0, 1, position, isOnFly, AllowScriptExecution);
					break;
				case 2:
					Labitinth::moveTo(1, 0, position, isOnFly, AllowScriptExecution);
					break;
				case 3:
					Labitinth::moveTo(0 , -1, position, isOnFly, AllowScriptExecution);
					break;
				}
				break;
			case language::Sides::BACK:
				switch (rotation)
				{
				case 0:
					Labitinth::moveTo(1,  0, position, isOnFly, AllowScriptExecution);
					break;
				case 1:
					Labitinth::moveTo(0, -1, position, isOnFly, AllowScriptExecution);
					break;
				case 2:
					Labitinth::moveTo(-1,  0, position, isOnFly, AllowScriptExecution);
					break;
				case 3:
					Labitinth::moveTo( 0, 1, position, isOnFly, AllowScriptExecution);
					break;
				}
				break;
			case language::Sides::RIGHT:
				switch (rotation)
				{
				case 0:
					Labitinth::moveTo( 0, 1, position, isOnFly, AllowScriptExecution);
					
					break;
				case 1:
					Labitinth::moveTo(1, 0, position, isOnFly, AllowScriptExecution);
					break;
				case 2:
					Labitinth::moveTo( 0, -1, position, isOnFly, AllowScriptExecution);
					
					break;
				case 3:
					Labitinth::moveTo(-1,  0, position, isOnFly, AllowScriptExecution);
					break;
				}
				break;
			case language::Sides::LEFT:
				switch (rotation)
				{
				case 0:
					Labitinth::moveTo( 0, -1, position, isOnFly, AllowScriptExecution);
					break;
				case 1:
					Labitinth::moveTo(-1,  0, position, isOnFly, AllowScriptExecution);
					break;
				case 2:
					Labitinth::moveTo( 0, 1,position, isOnFly, AllowScriptExecution);
					break;
				case 3:
					Labitinth::moveTo(1,  0, position, isOnFly, AllowScriptExecution);
					break;
				}
				break;
			}
			isOnFly = false;
			return -100;
		}
		static int look(Sides side) {
			switch (side)
			{
			case language::Sides::FRONT:
				switch (rotation)
				{
				case 0:
					return Labitinth::lookAt((int)*position.getX(), (int)*position.getY(),-1,0, isOnFly);
				case 1:
					return Labitinth::lookAt((int)*position.getX(), (int)*position.getY(),0,1, isOnFly);
				case 2:
					return Labitinth::lookAt((int)*position.getX(), (int)*position.getY(),1,0, isOnFly);
				case 3:
					return Labitinth::lookAt((int)*position.getX(), (int)*position.getY(),0,-1, isOnFly);
				}
				break;
			case language::Sides::BACK:
				switch (rotation)
				{
				case 0:
					return Labitinth::lookAt((int)*position.getX(), (int)*position.getY(), 1,0, isOnFly);
				case 1:
					return Labitinth::lookAt((int)*position.getX(), (int)*position.getY(), 0,-1, isOnFly);
				case 2:
					return Labitinth::lookAt((int)*position.getX(), (int)*position.getY(), -1,0, isOnFly);
				case 3:
					return Labitinth::lookAt((int)*position.getX(), (int)*position.getY(), 0,1, isOnFly);
				}
				break;
			case language::Sides::RIGHT:
				switch (rotation)
				{
				case 0:
					return Labitinth::lookAt((int)*position.getX(), (int)*position.getY(), 0,1, isOnFly);
				case 1:
					return Labitinth::lookAt((int)*position.getX(), (int)*position.getY(), 1,0, isOnFly);
				case 2:
					return Labitinth::lookAt((int)*position.getX(), (int)*position.getY(), 0,-1, isOnFly);
				case 3:
					return Labitinth::lookAt((int)*position.getX(), (int)*position.getY(), -1,0, isOnFly);
				}
				break;
			case language::Sides::LEFT:
				switch (rotation)
				{
				case 0:
					return Labitinth::lookAt((int)*position.getX(), (int)*position.getY(), 0,-1, isOnFly);
				case 1:
					return Labitinth::lookAt((int)*position.getX(), (int)*position.getY(), -1,0, isOnFly);
				case 2:
					return Labitinth::lookAt((int)*position.getX(), (int)*position.getY(), 0,1, isOnFly);
				case 3:
					return Labitinth::lookAt((int)*position.getX(), (int)*position.getY(), 1,0, isOnFly);
				}
				break;
			}
		}
		static int fly() {
			isOnFly = true;
			return -100;
		}
		static int rotate(Sides side) {
			switch (side)
			{
			case language::Sides::RIGHT:
				rotation = (rotation + 1) % 4;
				break;
			case language::Sides::LEFT:
				rotation = rotation - 1 < 0 ? 3 : rotation - 1;
				break;
			}
			return -100;
		}
		static bool stop(int i) {
			if (i <= 0) {
				isOnFly = false;
				return true;
			}
			return false;
		}

	public:
		static int rotation;
		static Square position;
		static bool AllowScriptExecution;
		static bool isOnFly;
		static std::optional<std::shared_ptr<MemoryCell>> doCommands(std::list<std::pair<Commands, std::optional<Sides>>> cmd) {
			if (!activated)
				throw Script_error("Robot can not do commands because start position and labirinth have not been inited with .env file.");
			int exec_code = 0;
			for (auto a : cmd) {
				switch (a.first)
				{
				case language::Commands::GO:
					exec_code = go(a.second.value());
					break;
				case language::Commands::LOOK:
					exec_code = look(a.second.value());
					break;
				case language::Commands::STOP:
					if (stop(exec_code))
						goto STOPPED;
					break;
				case language::Commands::FLY:
					exec_code = fly();
					break;
				case language::Commands::ROTATE:
					exec_code = rotate(a.second.value());
					break;
				}
			}

		STOPPED:
			if (exec_code >= -1) {
				auto i = std::make_shared<Math_type<int>>(exec_code, Types::INT);
				return std::make_shared<MemoryCell>(i);
			}
			return std::nullopt;
		}
		static std::optional<std::shared_ptr<MemoryCell>> WhereAmI() {
			Labitinth::print(position, isOnFly, rotation);
			return std::make_shared<MemoryCell>(std::make_shared<Square>(Robot::position));

		}
		static void setActive() {
			activated = true;
		}
	};

	static void initArea(std::string area) {
		std::ifstream file;
		file.open(area+".env");
		if (file.is_open()) {
			Robot::setActive();
			size_t x=0, y=0, size_x, size_y, exit_x=0, exit_y=0;
			file >> size_x;
			file.ignore(1);
			file >> size_y;
			file.ignore(1);

			for (int i = 0; i < size_x; i++) {
				Labitinth::walls.push_back({});
				for (int j = 0; j < size_y; j++)
					Labitinth::walls[i].push_back(false);
			}


				for (int i = 0; i < size_x; i++) {
					for (int j = 0; j < size_y; j++) {
						char c;
						file >> c;
						Labitinth::walls[i][j] = c == '#';
						if (c == '^') {
							x = i;
							y = j;
						}
						if (c == 'O') {
							exit_y = j;
							exit_x = i;
						}

					}
					file.ignore(1);
				}
				
				Robot::position.setX(x);
				Robot::position.setY(y);
				Robot::position.setBusy(false);

				Labitinth::exit_.setY(exit_y);
				Labitinth::exit_.setX(exit_x);
				Labitinth::exit_.setBusy(false);
				Labitinth::print(Robot::position,false, Robot::rotation);
			file.close();
		}
		else {
			throw Script_error("Enviroment error. No such .env file.", 0);
		}
	}
}