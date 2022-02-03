#include <iostream>
#include <windows.h>
#include <string>
#include <ctime>


using namespace std;

void HUD();
void Combat();
void CombatHUD();
void Moving();
void CreateMonster();

string name = " ";
int level = 0, xp = 0, health = 0, totalHealth = 0, maxHealth = 0, nextLevel = 0, heal = 0;

string monsterName[] = {"Nurse","Researcher","Doctor","Psychologist","Director","Janitor","Security guard"}; //ถ้าคิดตัวไรออกอีกก็เพิ่มได้ (ป้อง)
string currentMonster = " ";
int monsterHp = 0, MonsterXp = 0, MonsterLevel = 0;

int main(){
    
    srand(time(0));
    
    level = 1;
    xp = 0;
    nextLevel = 76;
    health = 100;
    totalHealth = health;
    maxHealth = totalHealth;



    //สร้างตัวละคร
    cout << "Enter Character Name: ";
    cin >> name;

    //หน้าโหลดหลังจากสร้างตัวละครเสร็จ(ทำให้มีดูมีลูกเล่นมากขึ้นนิดนึง5555555)
    cout << "Creating Charecter.\n";
    Sleep(350);
    system("cls");
    cout << "Creating Charecter..\n";
    Sleep(350);
    system("cls");
    cout << "Creating Charecter...\n";
    Sleep(350);
    system("cls");

    
    HUD();
    Moving();

    system("pause");

    return 0;

}

//หน้าโชว์ stat ตัวละคร (เพิ่มได้)
void HUD() { 
    Sleep(500);
    system("cls");
    cout << "Name: " << name << "       Health: " << totalHealth << "\nLevel: " << level << "\nExp: " << xp << "\nExp to next level: " << nextLevel << "\n";
}

//ตัวเลือกว่าจะทำอะไรต่อในหน้าหลัก (เพิ่มได้ & แก้ได้)
void Moving() { 
    int choice;
    cout << "\n\n";
    cout << "1. Go to next room\n";
    cout << "2. Sleep\n";
    cout << "3. Stay in current room\n";
    cout << "\n";
    
    cin >> choice;
    if(choice == 1){
        int temp = rand()%100 + 1; 
        cout << "You begin moving to next room...\n";
        if(temp >= 50 ) { 
            //************************************ พี่บิ๊กทำต่อจากตรงนี้*************************************************
        }
    }
    else if(choice == 2){

    }
    else if(choice == 3){

    }
    else{
        cout << "Wrong Input!!!";
        Sleep(500);
        Moving();
    } 
}

void spawnMonster(); // ระบบสุ่มเกิดมอน ยังไมไม่ได้ทำต่อ (ว่าน)

void CombatHUD(){
    Sleep(500);
    system("cls");
    cout << "Name: " << name << "       |       Monster Name: " << currentMonster << "\n";
    cout << "Health: " << totalHealth << "       |       Monster Health: " << monsterHp << "\n";
    cout << "Level: " << level << "     |       Monster Level: " << MonsterLevel << "\n";
}

void Combat(){
    CombatHUD();
    int playerAttack;
    int playerDamage = 8 * level/2; // <---------------------------- พี่เธียรปรับได้ (stat ตีของ player)
    int monsterAttack = 6 * MonsterLevel/2; // <---------------------- พี่เธียรปรับได้่ (stat ตีของ Monster)

    if(totalHealth >= 1 && monsterHp >= 1){
        cout << "\n";
        cout << "1. Attack\n";
        cout << "2. Use item\n";
        cout << "3. RUN\n";
        cout << "\n";
        cin >> playerAttack;

        if(playerAttack == 1){
            //ตี
            cout << "Attacking... you did " << playerDamage << " to the " << currentMonster << "\n";
            monsterHp = monsterHp - playerDamage;
            Sleep(750);
            CombatHUD();
            if(monsterHp >= 1){
                cout << "\n";
                cout << "Monster is Atacking...\n";
                totalHealth = totalHealth - monsterAttack;
                cout << "You lost " << monsterAttack << " hp and your current hp is " << totalHealth << "\n";
                if (totalHealth <= 0){
                    totalHealth = 0;
                }
            }else if(monsterHp <= 0) {
                monsterHp = 0;
            }
            Sleep(1000);
            Combat();
        }
        else if(playerAttack == 2){
            //ใช้ของ (ยังไม่ได้ทำ)

            Sleep(1000);
            Combat();


        }
        else if(playerAttack == 3){
            //วิ่งหนีแบบใส่เกียร์หมา
            cout << "You try to run away...\n";
            int x = rand() % 100 +1;
            if(x >= 70){
                cout << "You escaped safely.\n";
                HUD();
            }
            else {
                cout << "Can't escape!\n";
                cout << currentMonster << " does a savage attack on you!\n";
                totalHealth -= monsterAttack + 5;
                cout << "You lost " << monsterAttack + 5 << " hp and your current hp is " << totalHealth << "\n";
                Sleep(1000);
                Combat();
            }

        }
        else {
            cout << "Wrong Input!!!";
            Sleep(500);
            Combat();
        }
    }
}