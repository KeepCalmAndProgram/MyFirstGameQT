#ifndef ENEMY_H
#define ENEMY_H

#include <QVector3D>
#include "gameobject.h"
#include "cmesh.h"
#include "player.h"
#include <QElapsedTimer>

class Player;

class Enemy : public GameObject
{
public:

	Enemy();    //zrobic pokadrowo animacje oraz wrzucac po plikach.obj;

	QVector3D direction;

	void init();
	void enemyAnimation(int select_animation, int current_frame_close);
	void render(GLWidget* glwidget);
	void update();

	void setSpeed(float value_speed);
	float getSpeed();

	void setEnemyHP(float value_enemy_hp);
	float getEnemyHP();

	void turn();
	void atack();
	void power_atack();
	void atack_leg();
	//void move();
	void move_back();

	void death();


	//CMesh* m_mesh;
	CMesh m_mesh_enemy[8][32];

	QElapsedTimer time;

	float total_time = 0;  // czas animacji
	float timer_for_animation = 0;  // timer animacji

	int current_frame_open = 0;  // pierwszy index animacji
	int current_frame_close = 0;  // ostatni index animacji
	int select_animation = 0;  // Rodzaj animacji ( ruch, atak, defense itd...)
	//bool number_of_animations = false;  // Ilosc powtazania sie animacji

	void collision(Player* player);

	GameObject* player;

	enum state { Turn, Atack, Power_atack, Atack_leg, Move_back };//Move, Move_back };
	state stan;

private:

	float speed;
	float enemy_hp;

	float state_time;
	float state_time_spend;

};



#endif // ENEMY_H
