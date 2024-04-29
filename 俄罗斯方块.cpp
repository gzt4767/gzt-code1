#include <iostream>  
#include <vector>  
#include <random>  
#include <conio.h> // ���ڶ�ȡ�������루�Ǳ�׼�⣬������Ҫ��װ��ʹ������������  

const int WIDTH = 10;
const int HEIGHT = 20;

enum class Shape {
	I,
	J,
	L,
	O,
	S,
	T,
	Z
};

struct Block {
	int x, y;
};

struct Tetromino {
	Shape shape;
	std::vector<Block> blocks;
	int rotation;
};





class Game {
private:
	std::vector<std::vector<bool>> board;
	Tetromino currentPiece;
	int score;
	bool gameOver;
	bool gamePaused;

	// ����������״����תģʽ������ֻչʾ��I��״��Ϊʾ����  
	std::vector<std::vector<Block>> I_shapes = {
		{{0, 0}, {0, 1}, {0, 2}, {0, 3}},
		{{0, 0}, {1, 0}, {2, 0}, {3, 0}},
		{{0, 0}, {1, 0}, {1, 1}, {1, 2}},
		{{0, 2}, {1, 2}, {1, 1}, {1, 0}}
	};
	std::vector<std::vector<std::vector<Block>>> allShapes = { I_shapes }; // ���������״������  

	void generatePiece() {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(0, allShapes.size() - 1);
		int shapeIndex = dis(gen);
		std::uniform_int_distribution<> rotDis(0, allShapes[shapeIndex].size() - 1);
		currentPiece.rotation = rotDis(gen);
		currentPiece.blocks = allShapes[shapeIndex][currentPiece.rotation];

		// ��ʼ�������λ��  
		int startX = (WIDTH - currentPiece.blocks.size()) / 2;
		for (Block& block : currentPiece.blocks) {
			block.x = startX + block.x;
			block.y = 0;
		}
	}

	bool canPlace(const Tetromino& piece, int xOffset, int yOffset) {
		for (const Block& block : piece.blocks) {
			int newX = block.x + xOffset;
			int newY = block.y + yOffset;
			if (newX < 0 || newX >= WIDTH || newY < 0 || newY >= HEIGHT || board[newY][newX]) {
				return false;
			}
		}
		return true;
	}

	void placePiece(const Tetromino& piece, int xOffset, int yOffset) {
		for (const Block& block : piece.blocks) {
			int newX = block.x + xOffset;
			int newY = block.y + yOffset;
			board[newY][newX] = true;
		}
	}

	void movePiece(int xOffset, int yOffset) {
		if (canPlace(currentPiece, currentPiece.blocks[0].x + xOffset, currentPiece.blocks[0].y + yOffset)) {
			for (Block& block : currentPiece.blocks) {
				block.x += xOffset;
				block.y += yOffset;
			}
		}
	}

	void rotatePiece() {
		std::vector<Block> rotatedBlocks;
		int newRotation = (currentPiece.rotation + 1) % allShapes[0].size(); // ����������״����ͬ��������ת  
		for (const Block& block : currentPiece.blocks) {
			int newX, newY;
			switch (newRotation) {
			case 0: newX = -block.y; newY = block.x; break;
			case 1: newX = block.x; newY = -block.y; break;
			case 2: newX = block.y; newY = -block.x; break;




	bool canPlace(const Tetromino& piece) {
		// ����Ƿ�����ڵ�ǰλ�÷��÷���...  
		return true;
	}

	void placePiece(const Tetromino& piece) {
		// ��������õ���Ϸ����...  
	}

	void removeCompleteLines() {
		// �Ƴ���������...  
	}

	void updateScore() {
		// ���·���...  
	}

public:
	Game() : board(HEIGHT, std::vector<bool>(WIDTH, false)), score(0), gameOver(false) {
		generatePiece();
	}

	void run() {
		while (!gameOver) {
			system("cls"); // �����Ļ  
			render();
			char input = _getch(); // ��ȡ��������  
			handleInput(input);
			update();
		}
	}

	void render() {
		for (int y = 0; y < HEIGHT; ++y) {
			for (int x = 0; x < WIDTH; ++x) {
				if (board[y][x]) {
					std::cout << "X";
				}
				else {
					std::cout << ".";
				}
			}
			std::cout << std::endl;
		}
		std::cout << "Score: " << score << std::endl;
	}

	void handleInput(char input) {
		switch (input) {
		case 'a':
			// �����ƶ�...  
			break;
		case 'd':
			// �����ƶ�...  
			break;
		case 's':
			// ��������...  
			break;
		case ' ':
			// ��ת����...  
			break;
		case 'q':
			gameOver = true;
			break;
		}
	}

	void update() {
		// ������Ϸ״̬...  
	}
};

int main() {
	Game game;
	game.run();
	return 0;
}
