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
void LevelUp();

string name = " ";
int level = 0, xp = 0, health = 0, totalHealth = 0, maxHealth = 0, nextLevel = 0, heal = 0;

string monsterName[] = {"Nurse","Researcher","Doctor","Psychologist","Director","Janitor","Security guard"}; //ถ้าคิดตัวไรออกอีกก็เพิ่มได้ (ป้อง)
string currentMonster = " ";
int monsterHp = 0, monsterXp = 0, monsterLevel = 0;

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
            CreateMonster();
            string monster = monsterName[rand()%6];
            cout << "You found the " << monster << "! Prepare to fight!\n";
            currentMonster = monster;
            Sleep(1000);
            Combat();
            
        }
        else {
            //เพิ่มEventอื่นนอกจากเจอมอน ว่านทำเอง
            HUD();
            Moving();
        }
    }
    else if(choice == 2){
        //************************************ ให้พี่บิ๊กทำต่อจากตรงนี้แทน เพิ่มระบบนอนแล้วเพิ่มเลือดเมื่อผู้เล่นเลือกเลข 2************************************************

    }
    else if(choice == 3){
       

    }
    else{
        cout << "Wrong Input!!!";
        Sleep(500);
        Moving();
    } 
}

void CreateMonster(){ // ระบบสุ่มเกิดมอน พี่เธียรปรับได้ (stat สุ่มของ Monster) เพราะตอนนี้ยังไม่ค่อยบาลานซ์
    monsterLevel = (rand()%3) + level;
    monsterHp = (rand()%(maxHealth/4)+((maxHealth/4)+1) * monsterLevel);

    if (monsterHp == 0 ) CreateMonster();
    if (monsterLevel == 0) CreateMonster();
}


void CombatHUD(){
    Sleep(500);
    system("cls");
    cout << "Name: " << name << "       |       Monster Name: " << currentMonster << "\n";
    cout << "Health: " << totalHealth << "       |       Monster Health: " << monsterHp << "\n";
    cout << "Level: " << level << "          |       Monster Level: " << monsterLevel << "\n";
}

void Combat(){
    CombatHUD();
    int playerAttack;
    int playerDamage = 8 * level/2; // <---------------------------- พี่เธียรปรับให้เป็นแบบ Random (stat ตีของ player)
    int monsterAttack = 6 * monsterLevel/2; // <---------------------- พี่เธียรปรับให้เป็นแบบ Random (stat ตีของ Monster)

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
            Sleep(1250);
            CombatHUD();
            if(monsterHp >= 1){
                cout << "\n";
                cout << "Monster is Atacking...\n";
                totalHealth = totalHealth - monsterAttack;
                cout << "You lost " << monsterAttack << " hp and your current hp is " << totalHealth << "\n";
                if (totalHealth <= 0){
                    totalHealth = 0;
                    system("cls");
                    cout << "You DIED! \nYou were level: " << level << " you got killed by " << currentMonster << ".\n";
                    Sleep(1000);
                    cout << "You can't get out of the hospital. so sad :(\n";
                    Sleep(3000); 
                    exit(0);
                }
            }else if(monsterHp <= 0) {
                monsterHp = 0;
                LevelUp();
                cout << "\n";
                cout << "You Defeated " << currentMonster << " you are awarded with " << monsterXp << " Exp.\n";
                cout << "Nice :)";
                Sleep(2500);
                HUD();
                Moving();
            }
            Sleep(1500);
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
            Sleep(1250);
            int x = rand() % 100 +1;
            if(x >= 70){
                cout << "You escaped safely.\n";
                Sleep(1250);
                HUD();
                Moving();
            }
            else {
                cout << "Can't escape!\n";
                cout << currentMonster << " does a savage attack on you!\n";
                totalHealth -= monsterAttack + 5;
                cout << "You lost " << monsterAttack + 5 << " hp and your current hp is " << totalHealth << "\n";
                Sleep(2000);
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

void LevelUp() {
    monsterXp = 19 * monsterLevel;
    xp = xp + monsterXp;

    if(xp >= nextLevel){
        level++;
        nextLevel = nextLevel * 3/2;
        xp = 0;
        totalHealth = totalHealth + 20;
        maxHealth = maxHealth + 20;
        cout << "\n\n";
        cout << "Congratulations " << name << " you are now level " << level << "\n";
        cout << "You are STRONGER than before\n";
        Sleep(2500);
        HUD();
    }
}

