#include<graphics.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>
#pragma comment(lib, "Winmm.lib")
using namespace std;


const int maxn = 10;//�з�̹������
struct tank_s {
	int row;
	int col;
	int direction;//̹���ڿڷ��� ��������--0��1��2��3
	bool live;    //true--�false--����
	//tank_s(int r,int c,int dir,bool flag):row(r),col(c),direction(dir),live(flag){ }
};
struct bullet_s{
	int pos_r;
	int pos_c;
	int direction;
	bool status;//�ӵ�״̬
};
//�����ͼ����
int map[26][26] = {
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 2, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 2, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
{ 2, 2, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 2, 2 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};
int main(int argv, char* argc[]) {
	void menu();
	void init_map();
	bool play();
	void game_over(bool s);
	//���̨
	initgraph(650, 650);

	//��ʼ�˵�
	menu();

	//��ͼ��ʼ��
	init_map();

	//��ʼ��Ϸ
	bool result=play();

	//��ʾ��Ϸ���
	game_over(result);

	system("pause");
	system("pause");
	system("pause");
	closegraph();
	return 0;
}
void menu() {
	//��ʾlogo
	IMAGE logo_img;
	loadimage(&logo_img, _T("logo.bmp"), 297, 150);
	putimage(180, 20, &logo_img);

	//��������˵�� ��ʼ
	setlinecolor(WHITE);
	setfillcolor(BLACK);

	fillrectangle(230, 200, 310, 240);
	settextstyle(25, 0, _T("����"));
	outtextxy(240, 210, _T("˵ ��"));

	fillrectangle(350, 200, 430, 240);
	outtextxy(360, 210, _T("�� ʼ"));

	MOUSEMSG mouse;
	IMAGE illustrate_img;
	loadimage(&illustrate_img, _T("illustrate.jpg"), 300, 300);
	while (true) {
		mouse = GetMouseMsg();
		switch (mouse.uMsg) {
		case WM_MOUSEMOVE:	//˵��
			if (mouse.x > 230 && mouse.x < 310 && mouse.y>200 && mouse.y < 240) {
				putimage(150, 250, &illustrate_img);
			}
			else {
				solidrectangle(150, 250, 450, 550);
			}
			break;
		case WM_LBUTTONDOWN:	//��ʼ
			if (mouse.x > 350 && mouse.x < 430 && mouse.y>200 && mouse.y < 240) {
				cleardevice();
				return;
			}
		}
	}
}
void init_map() {
	//1Ϊ������ǽ��2������ǽ��3��ӥ��200�ҷ�̹��
	IMAGE img_home, img_wallF, img_wallS;
	loadimage(&img_home,_T("home.jpg"),50,50);
	loadimage(&img_wallF, _T("wallF.jpg"), 25, 25);
	loadimage(&img_wallS, _T("wallS.jpg"), 25, 25);
	
	//��ʼ����ͼ����
	/*
	{






	}
	*/

	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26;++j) {
			if (map[i][j]==1) {
				putimage(25 * j, 25 * i, &img_wallF);
			}
			else if (map[i][j] == 2) {
				putimage(25 * j, 25 * i, &img_wallS);
			}
			else if(map[i][j]==3) {
				putimage(25 *j , 25 * i, &img_home);
				map[i][j] = map[i + 1][j] = map[i][j + 1] = map[i + 1][j + 1] = 4;//��עӥ��λ��
			}
		}
	}

}

void set_map(int y,int x,int val) {   //��ͼֵ��������
	map[y][x] = val;
	map[y][x + 1] = val;
	map[y + 1][x] = val;
	map[y + 1][x + 1] = val;
}

void detail_tank_walk(tank_s *tank,int dir,IMAGE *img) {  //̹���н�
	int nr = tank->row;
	int nc = tank->col;
	int old = map[nr][nc];
	switch (dir) {
		case 0: --nr; break;
		case 1: ++nr; break;
		case 2: --nc; break;
		case 3: ++nc; break;
		default:break;// return false;
	}
	set_map(tank->row,tank->col,0);

	setfillcolor(BLACK);
	solidrectangle(tank->col * 25,tank->row * 25 ,tank->col * 25 + 50 , tank->row * 25 + 50);

	tank->row = nr;
	tank->col = nc;
	set_map(tank->row, tank->col, old);

	putimage(tank->col * 25,tank->row * 25 , img);

	//return true;
}
void tank_walk(tank_s* tank, int dir, IMAGE* img) {
	switch (dir) {
		case 2://left 2
			if (tank->direction != 2) {//̹��ԭ�ص�������
				tank->direction = 2;
				putimage(tank->col * 25, tank->row * 25, img);
			}
			else if (tank->col - 1 >= 0 && map[tank->row][tank->col - 1] == 0 && map[tank->row + 1][tank->col - 1] == 0) {
				detail_tank_walk(tank, 2, img);
			}
			break;
		case 0://up  0
			if (tank->direction != 0) {
				tank->direction = 0;
				putimage(tank->col * 25, tank->row * 25, img);
			}
			else if (tank->row - 1 >= 0 && map[tank->row - 1][tank->col] == 0 && map[tank->row - 1][tank->col + 1] == 0) {
				detail_tank_walk(tank, 0, img);
			}
			break;
		case 1:// down 1
			if (tank->direction != 1) {
				tank->direction = 1;
				putimage(tank->col * 25, tank->row * 25, img);
			}
			else if (tank->row + 2 <= 25 && map[tank->row + 2][tank->col] == 0 && map[tank->row + 2][tank->col + 1] == 0) {
				detail_tank_walk(tank, 1, img);
			}
			break;
		case 3://right 3
			if (tank->direction != 3) {
				tank->direction = 3;
				putimage(tank->col * 25, tank->row * 25, img);
			}
			else if (tank->col + 2 <= 25 && map[tank->row][tank->col + 2] == 0 && map[tank->row + 1][tank->col + 2] == 0) {
				detail_tank_walk(tank, 3, img);
			}
			break;
		default:
			break;
	}
}
int tank_adjustDir(tank_s* tank, int row, int col) {   //̹�˵�������
	int snum = rand() % 2;
	if (tank->row < row) {//north
		if (tank->col < col) {//west
			if (snum) {
				return 1;//down
			}
			else return 3;//right
		}
		else {//east
			if (snum) {
				return 1;//down
			}
			else return 2;//left

		}
	}
	else {//south
		if (tank->col < col) {//west
			if (snum) {
				return 0;//up
			}
			else return 3;//right
		}
		else {//east
			if (snum) {
				return 0;//up
			}
			else return 2;//left
		}
	}
}
void tank_fire(tank_s* tank,bullet_s* bullet,int need_sound) {
	if (bullet->status == false) {//�ӵ�����������ÿ��̹��ֻ��һ���ӵ���
		if (need_sound == 1) PlaySound(_T("paoji.wav"), NULL, SND_FILENAME | SND_ASYNC);
		if (tank->direction == 0) {	//up
			bullet->pos_r = tank->row * 25 - 3;
			bullet->pos_c = tank->col * 25 + 23;
		}
		else if (tank->direction == 1) {//down
			bullet->pos_r = tank->row * 25 + 50;
			bullet->pos_c = tank->col * 25 + 23;
		}
		else if (tank->direction == 2) {//left
			bullet->pos_r = tank->row * 25 + 23;
			bullet->pos_c = tank->col * 25 - 3;
		}
		else if (tank->direction == 3) {//right
			bullet->pos_r = tank->row * 25 + 23;
			bullet->pos_c = tank->col * 25 + 50;
		}
		bullet->direction = tank->direction;
		bullet->status = true;
	}
}
bool bullet_action(bullet_s &bullet,tank_s* enemy_tank) {//�ӵ���ײ���������   true--��Ϸ����  false--��Ϸ����
	int row, col, nrow, ncol;
	row = bullet.pos_r/25;
	col = bullet.pos_c/25;

	// �����ӵ�
	setfillcolor(BLACK);
	solidrectangle(bullet.pos_c, bullet.pos_r, bullet.pos_c + 3, bullet.pos_r + 3);

	//�ӵ��ض�λ
	switch (bullet.direction) {
		case 0:
			bullet.pos_r -= 2;
			ncol = col+1 ;// �ӵ���ײ������
			nrow = row;
			break;
		case 1:
			bullet.pos_r += 2;
			ncol = col + 1;// �ӵ���ײ������
			nrow = row;
			break;
		case 2:
			bullet.pos_c -= 2;
			ncol = col ;
			nrow = row+1;
			break;
		case 3:
			bullet.pos_c += 2;
			ncol = col;
			nrow = row + 1;
			break;
		default: return false;//����ֱ����ʧ�ܽ�����Ϸ
	}

	//�ӵ���Ч���
	if (bullet.pos_c > 650 || bullet.pos_c < 0 || bullet.pos_r < 0 || bullet.pos_r >650) {
		bullet.status = false;
		return true;//�ӵ���һ��������ͼ��Χ
	}

	//�ӵ���ײ��⣨ײӥ��ײǽ��
	if (map[row][col] == 4 || map[nrow][ncol] == 4) {//�ӵ�ײ��ӥ ʧ��
		return false;
	}
	if (map[row][col] == 1) {	// �ӵ�ײ��������ǽ
		map[row][col] = 0;
		bullet.status = false;
		setfillcolor(BLACK);
		solidrectangle(col * 25, row * 25, col * 25 + 25, row * 25 + 25);
	}
	else if (map[row][col] == 2) {//�ӵ�ײ����������ǽ
		bullet.status = false;
	}

	if (map[nrow][ncol] == 1) {	// �ӵ�ײ��������ǽ
		map[nrow][ncol] = 0;
		bullet.status = false;
		setfillcolor(BLACK);
		solidrectangle(ncol * 25, nrow * 25, ncol * 25 + 25, nrow * 25 + 25);
	}
	else if (map[nrow][ncol] == 2) {//�ӵ�ײ����������ǽ
		bullet.status = false;
	}

	if (map[row][col]==200||map[nrow][ncol]==200) {//�ӵ������ҷ�̹��
		return false;
	}

	tank_s* tank = NULL;
	if (map[row][col] >= 100 && map[row][col] < 200) {//�ӵ����ез�̹��
		bullet.status = false;
		tank = enemy_tank + (map[row][col] - 100);
	}
	else if (map[nrow][ncol] >= 100 && map[nrow][ncol] < 200) {//�ӵ����ез�̹��
		bullet.status = false;
		tank = enemy_tank + (map[nrow][ncol] - 100);
	}
	if (tank != NULL) {
		tank->live = false;
		set_map(tank->row, tank->col, 0);
		setfillcolor(BLACK);
		solidrectangle(tank->col * 25, tank->row * 25, tank->col * 25 + 50, tank->row * 25 + 50);
	}

	//�ӵ����»���
	if (bullet.status == true) {
		setfillcolor(WHITE);
		solidrectangle(bullet.pos_c, bullet.pos_r, bullet.pos_c+3, bullet.pos_r+3);
	}
	return true;
}
bool play() {
	srand(time(NULL));//��ʼ����������ӣ�ÿ��������Ϸ���в�ͬ����ϵ��

	tank_s my_tank;// �ҷ�̹�˳�ʼ��
	bullet_s my_bullet;		//�ҷ��ӵ�

	tank_s enemy_tank[maxn]; // �з�̹�˳�ʼ��
	bullet_s enemy_bullet[maxn];		//�з��ӵ�
	int enemy_total = 3;		// �з�̹�˳�������

	IMAGE my_tank_img[4];//�ҷ�̹��ͼƬ����
	loadimage(&my_tank_img[0], _T("tank_up.jpg"), 50, 50);
	loadimage(&my_tank_img[1], _T("tank_down.jpg"), 50, 50);
	loadimage(&my_tank_img[2], _T("tank_left.jpg"), 50, 50);
	loadimage(&my_tank_img[3], _T("tank_right.jpg"), 50, 50);

	IMAGE enemy_tank_img[4];//�з�̹��ͼƬ����
	loadimage(&enemy_tank_img[0], _T("enemy_tank_up.jpg"), 50, 50);
	loadimage(&enemy_tank_img[1], _T("enemy_tank_down.jpg"), 50, 50);
	loadimage(&enemy_tank_img[2], _T("enemy_tank_left.jpg"), 50, 50);
	loadimage(&enemy_tank_img[3], _T("enemy_tank_right.jpg"), 50, 50);

	mciSendString(_T("open background.wav alias al wait"), NULL, 0, NULL);  //���ű�������
	mciSendString(_T("play al"), NULL, 0, NULL);

	my_tank.row = 24;// �ҷ�̹�����ݳ�ʼ��
	my_tank.col = 8;
	map[my_tank.row][my_tank.col] = 200;
	my_tank.direction = 0;
	my_tank.live = true;
	my_bullet.status = false;
	putimage(my_tank.col*25,my_tank.row*25,&my_tank_img[my_tank.direction]);//̹���ϳ�

	for (int i = 0; i < maxn; ++i) {//�з�̹�����ݳ�ʼ��
		switch (i%3) {
			case 0:
				enemy_tank[i].col = 0; break;
			case 1:
				enemy_tank[i].col = 12; break;
			case 2:
				enemy_tank[i].col = 24; break;
			default:break;
		}
		enemy_tank[i].row = 0;
		enemy_tank[i].live = true;
		enemy_tank[i].direction = 1;
		enemy_bullet[i].status = false;
	}
	putimage(enemy_tank[0].col * 25, enemy_tank[0].row * 25, &enemy_tank_img[enemy_tank[0].direction]);//�з�̹�˳���
	putimage(enemy_tank[1].col * 25, enemy_tank[1].row * 25, &enemy_tank_img[enemy_tank[1].direction]);
	putimage(enemy_tank[2].col * 25, enemy_tank[2].row * 25, &enemy_tank_img[enemy_tank[2].direction]);
	set_map(enemy_tank[0].row, enemy_tank[0].col, 100 );
	set_map(enemy_tank[1].row, enemy_tank[1].col, 101);
	set_map(enemy_tank[2].row, enemy_tank[2].col, 102);

	int key;//�ҷ��ȼ�����
	int times=0;//�з��ӵ�ʱ�����
	int dir;//�з�̹�˵����������
	while (1) {
		times++;
		if (times > 0 && times % 500== 0 && enemy_total < maxn) {
			if (map[enemy_tank[enemy_total].row][enemy_tank[enemy_total].col]==0) {//������̹��
				putimage(enemy_tank[enemy_total].col * 25, enemy_tank[enemy_total].row * 25, &enemy_tank_img[enemy_tank[enemy_total].direction]);
				set_map(enemy_tank[enemy_total].row, enemy_tank[enemy_total].col, 100 + enemy_total);
				enemy_total++;
			}
		}
		if (times % 200 == 0) {		//	ÿ2000ms�з�̹�˵�������һ��
			for (int i = 0; i < enemy_total; ++i) {
				if (enemy_tank[i].live == false) continue;
				if (i%2==0) {//�����ҷ�̹��
					dir=tank_adjustDir(&enemy_tank[i],my_tank.row, my_tank.col);
					tank_walk(&enemy_tank[i], dir, &enemy_tank_img[dir]);
				}
				else if ( i % 2 == 1) {//�����ҷ���ӥ
					dir = tank_adjustDir(&enemy_tank[i], 24, 12);
					tank_walk(&enemy_tank[i], dir, &enemy_tank_img[dir]);
				}
				tank_fire(&enemy_tank[i],&enemy_bullet[i],0);
			}

		}
		else if (times%50==0) {		//	ÿ500ms�з�̹���н�һ��
			for (int i = 0; i < enemy_total;++i) {
				if (enemy_tank[i].live ) {
					tank_walk(&enemy_tank[i], enemy_tank[i].direction, &enemy_tank_img[enemy_tank[i].direction]);
				}
			}
		
		}
	

		if(_kbhit()){		//   �ҷ�̹�˿��� #include<conio.h>
			key = _getch();
			switch (key) {
				case 'a'://left 2
					if (my_tank.direction!=2) {	//̹��ԭ�ص�������
						my_tank.direction = 2;
						putimage(my_tank.col * 25, my_tank.row * 25, &my_tank_img[my_tank.direction]);
					}
					else if (my_tank.col - 1 >= 0 && map[my_tank.row][my_tank.col - 1] == 0 && map[my_tank.row + 1][my_tank.col - 1] == 0) {
						tank_walk(&my_tank,2,&my_tank_img[my_tank.direction]);
					}
					break;
				case 'w'://up  0
					if (my_tank.direction != 0) {
						my_tank.direction = 0;
						putimage(my_tank.col * 25, my_tank.row * 25, &my_tank_img[my_tank.direction]);
					}
					else if (my_tank.row - 1 >= 0 && map[my_tank.row-1][my_tank.col] == 0 && map[my_tank.row -1][my_tank.col +1] == 0) {
						tank_walk(&my_tank, 0, &my_tank_img[my_tank.direction]);
					}
					break;
				case 's':// down 1
					if (my_tank.direction != 1) {
						my_tank.direction = 1;
						putimage(my_tank.col * 25, my_tank.row * 25, &my_tank_img[my_tank.direction]);
					}
					else if (my_tank.row + 2 <= 25 && map[my_tank.row + 2][my_tank.col] == 0 && map[my_tank.row + 2][my_tank.col + 1] == 0) {
						tank_walk(&my_tank, 1, &my_tank_img[my_tank.direction]);
					}
					break;
				case 'd'://right 3
					if (my_tank.direction != 3) {
						my_tank.direction = 3;
						putimage(my_tank.col * 25, my_tank.row * 25, &my_tank_img[my_tank.direction]);
					}
					else if (my_tank.col + 2 <= 25 && map[my_tank.row][my_tank.col + 2] == 0 && map[my_tank.row + 1][my_tank.col + 2] == 0) {
						tank_walk(&my_tank, 3, &my_tank_img[my_tank.direction]);
					}
					break;
				case 'j'://����
					tank_fire(&my_tank,&my_bullet,1);
					break;
				case 'p':
					system("pause");
					break;
				default:
					break;
			}
			
		}
		if (my_bullet.status) {
			if (!bullet_action(my_bullet, enemy_tank)) {
				
				return false;
			}
		}
		for (int i = 0; i < enemy_total; ++i) {
			if (enemy_bullet[i].status) {
				if (!bullet_action(enemy_bullet[i], enemy_tank)) {

					return false;
				}
			}
		}
		int IsWin = 0;
		for (int i = 0; i < maxn;++i) {
			if (enemy_tank[i].live == true) {
				IsWin = 0;
				break;
			}
			else IsWin++;
		}
		if (IsWin == maxn) {
			return true;
		}
		Sleep(10);
	}
}

void game_over(bool s) {
	IMAGE img;
	if (s) {
		loadimage(&img, _T("success.jpg"),500, 250);
		putimage(80,200,&img);
	}
	else {
		loadimage(&img, _T("failure.jpg"), 500, 250);
		putimage(80, 200, &img);
	}
}
