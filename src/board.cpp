#include "board.h"

//�o�H�T�������ăX�e�[�^�X��ݒ肷��
bool Board::find(const Point& start, const Point& goal)
{
	//�X�^�[�g�ƃS�[���ɃX�e�[�^�X��ݒ�
	mass_[start.y()][start.x()].setStatus(Mass::START);
	mass_[goal.y()][goal.x()].setStatus(Mass::GOAL);

	//���ׂ�|�C���gp���X�^�[�g�n�_�ɐݒ�
	Point p = start;

	//p���S�[���ɓ��B����܂ŏ�������
	while (p != goal)
	{
		//�ʂ����n�_�ɃX�e�[�^�XWAYPOINT(�Z��)��t�^�B�X�^�[�g�n�_�ɂ͕t�^���Ȃ��B
		if (p != start) mass_[p.x()][p.y()].setStatus(Mass::WAYPOINT);

		//p�̍��W���S�[���n�_�̍��W�Ɠ������Ȃ�܂�x,y�𑝌�������
		if (p.x() < goal.x()) { p.setX(p.x() + 1); continue; }
		if (goal.x() < p.x()) { p.setX(p.x() - 1); continue; }
		if (p.y() < goal.y()) { p.setY(p.y() + 1); continue; }
		if (goal.y() < p.y()) { p.setY(p.y() - 1); continue; }
	}

	return false;
}

//�}�b�v�`��A�ύX�s�v
void Board::show() const 
{
	std::cout << std::endl;

	for (int y = 0; y < BOARD_SIZE; y++) {
		std::cout << " ";
		for (int x = 0; x < BOARD_SIZE; x++) {
			std::cout << "+-";
		}
		std::cout << "+" << std::endl;

		std::cout << " ";
		for (int x = 0; x < BOARD_SIZE; x++) {
			std::cout << "|";
			switch (mass_[y][x].getStatus()) {
			case Mass::BLANK:
				std::cout << " ";
				break;
			case Mass::START:
				std::cout << "S";
				break;
			case Mass::GOAL:
				std::cout << "G";
				break;
			case Mass::WAYPOINT:
				std::cout << "o";
				break;
			case Mass::WALL:
				std::cout << "#";
				break;
			case Mass::WATER:
				std::cout << "~";
				break;
			case Mass::ROAD:
				std::cout << "$";
				break;
			}
		}
		std::cout << "|" << std::endl;
	}

	std::cout << " ";
	for (int x = 0; x < BOARD_SIZE; x++) {
		std::cout << "+-";
	}
	std::cout << "+" << std::endl;

}
