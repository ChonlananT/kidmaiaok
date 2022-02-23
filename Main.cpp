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
void story1();


string name = " ";
int level = 0, xp = 0, health = 0, totalHealth = 0, maxHealth = 0, nextLevel = 0, heal = 0, currentRoom=1, healthPotion=0, chemicalX=0, atk = 8;
int scalpelState = 0, ppeState = 0, Scalpel=0, PPE=0, SPcooldown=0;
string monsterName[] = {"Nurse","Researcher","Doctor","Psychologist","Director","Janitor","Security guard"}; //ถ้าคิดตัวไรออกอีกก็เพิ่มได้ (ป้อง)
string currentMonster = " ";
int monsterHp = 0, monsterXp , monsterLevel ;

int main(){
    
    srand(time(0));
    
    level = 1;
    xp = 0;
    nextLevel = 76;
    health = 100;
    totalHealth = health + ::PPE;
    maxHealth = totalHealth + ::PPE;

    story1();

    //สร้างตัวละคร
    cout << "Enter Character Name: ";
    cin >> name;

    //หน้าโหลดหลังจากสร้างตัวละครเสร็จ(ทำให้มีดูมีลูกเล่นมากขึ้นนิดนึง5555555)
    cout << "Creating Charecter.\n";
    Sleep(500);
    system("cls");
    cout << "Creating Charecter..\n";
    Sleep(500);
    system("cls");
    cout << "Creating Charecter...\n";
    Sleep(500);
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
    cout << "Name: " << name << "       Health: " << totalHealth+::PPE << "\nLevel: " << level << "\nExp: " << xp << "\nExp to next level: " << nextLevel << "\n" << "Current room: " << ::currentRoom;
}

//ตัวเลือกว่าจะทำอะไรต่อในหน้าหลัก (เพิ่มได้ & แก้ได้)
void Moving() { 
    int choice;
    cout << "\n\n";
    cout << "1. Go to next room\n";
    cout << "2. Open inventory\n";
    cout << "3. Explore this room\n";
    cout << "\n";
    
    cin >> choice;
    if(choice == 1){
        int temp = rand()%100 + 1; 
        system("cls");
        cout << "You begin moving to the next room.\n";
        Sleep(500);
        system("cls");
        cout << "You begin moving to the next room..\n";
        Sleep(500);
        system("cls");
        cout << "You begin moving to the next room...\n";
        Sleep(500);
        system("cls");
       
        ::currentRoom++;
        if(temp <= 80) { 
            if(currentRoom < 20){
            CreateMonster();
            string monster = monsterName[rand()%6];
            cout << "You found the " << monster << "! Prepare to fight!\n";
            currentMonster = monster;
            Sleep(1500);
            Combat();
            }else{ // สร้าง BOSS
                CreateMonster();
                monsterLevel = level;
                monsterHp = maxHealth+120;
                string monster = monsterName[6];
                cout << "You found the last boss " << monster << "! Prepare to your final fight!\n";
                currentMonster = monster;
                Sleep(2000);
                Combat();
            } 
        }
        else {
            //เพิ่มEventอื่นนอกจากเจอมอน ว่านทำเอง
            int temp = rand()%2 + 1; 
            if(temp == 1){
            cout << "Congratulations!!! You found a Medkit\n";
            ::healthPotion++;
            Sleep(1500);
            HUD();
            Moving();
            }else {
                cout << "Congratulations!!! You found a Chemical X\n";
                ::chemicalX++;
                Sleep(1500);
                HUD();
                Moving();        
            }
        }
    }
    else if(choice == 2){
        
        system("cls");
        int ans;
        cout << "Please select your equipment\n\n";
        cout << "1. Scalpel\n";
        cout << "2. PPE Suit\n";
        cin >> ans;
        if(ans == 1){
            if(::scalpelState == 1){
                ::Scalpel = 25;
                system("cls");
                cout << "You are equipping the Scalpel.\n";
                Sleep(500);
                system("cls");
                cout << "You are equipping the Scalpel..\n";
                Sleep(500);
                system("cls");
                cout << "You are equipping the Scalpel...\n";
                Sleep(500);
                system("cls");
                cout << "Your damage is increase by 25.";
                Sleep(1500);
                HUD();
                Moving(); 
            }else{
                system("cls");
                cout << "You don't have this equipment yet.";
                Sleep(1500);
                HUD();
                Moving(); 
            }
        }else if(ans == 2){
            if(::ppeState == 1){
                ::PPE = 150;
                system("cls");
                cout << "You are equipping the PPE Suit.\n";
                Sleep(500);
                system("cls");
                cout << "You are equipping the PPE Suit..\n";
                Sleep(500);
                system("cls");
                cout << "You are equipping the PPE Suit...\n";
                Sleep(500);
                system("cls");
                cout << "Your Max HP is increase by 150.";
                Sleep(1500);
                HUD();
                Moving(); 
            }else{
                system("cls");
                cout << "You don't have this equipment yet.";
                Sleep(1500);
                HUD();
                Moving(); 
            }
        }else{
            cout << "Wrong Input!!!";
            Sleep(500);
            HUD();
            Moving();
        }
    }    
    else if(choice == 3){
        system("cls");
        cout << "You begin exploring this room.\n";
        Sleep(500);
        system("cls");
        cout << "You begin exploring this room..\n";
        Sleep(500);
        system("cls");
        cout << "You begin exploring this room...\n";
        Sleep(500);
        system("cls");
       
        int temp = rand()%100 + 1; 
        if(temp <= 10){
            ::scalpelState++;
            if(::scalpelState == 1){
                cout << "Wow!! You found a Scalpel. It can increase your damage if you equip it.";
                Sleep(2500);
                HUD();
                Moving();
            }else{
                ::scalpelState = 1;
                cout << "You found nothing :(";
                Sleep(750);
                HUD();
                Moving();            
            }
        }else if(temp > 10 && temp <= 20){
            ::ppeState++;
            if(::ppeState == 1){
                cout << "Wow!! You found a PPE Suit. It can increase your max HP if you equip it.";
                Sleep(2500);
                HUD();
                Moving();
            }else{
                ::ppeState = 1;
                cout << "You found nothing :(";
                Sleep(750);
                HUD();
                Moving();            
            }
        }else if(temp > 20 && temp <=60){
            cout << "You found nothing :(";
            Sleep(750);
            HUD();
            Moving();   
        }else{
            CreateMonster();
            string monster = monsterName[rand()%6];
            cout << "The " << monster << " is coming for you! Prepare to fight.\n";
            currentMonster = monster;
            Sleep(1500);
            Combat();
        }
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
    cout << "Health: " << totalHealth+::PPE << "       |       Monster Health: " << monsterHp << "\n";
    cout << "Level: " << level << "          |       Monster Level: " << monsterLevel << "\n";
}

void Combat(){
    CombatHUD();
    int playerAttack;
    int playerDamage = atk * level + ::Scalpel; // <---------------------------- พี่เธียรปรับให้เป็นแบบ Random (stat ตีของ player)
    int monsterAttack = 6 * monsterLevel/2; // <---------------------- พี่เธียรปรับให้เป็นแบบ Random (stat ตีของ Monster)

    if(totalHealth >= 1 && monsterHp >= 1){
        cout << "\n";
        cout << "1. Attack\n";
        cout << "2. Special Attack\n";
        cout << "3. Use item\n";
        cout << "4. RUN\n";
        cout << "\n";
        cin >> playerAttack;

        if(playerAttack == 1){
            //ตี
            cout << "Attacking...\n";
            Sleep(500);
            cout << "you did " << playerDamage << " damage to the " << currentMonster << "\n";
            monsterHp = monsterHp - playerDamage;
            Sleep(1250);
            CombatHUD();
            if(monsterHp >= 1){
                cout << "\n";
                cout << "Monster is Atacking...\n";
                totalHealth = totalHealth - monsterAttack;
                cout << "You lost " << monsterAttack << " hp and your current hp is " << totalHealth+::PPE << "\n";
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
                if(currentRoom >= 20){
                    system("cls");
                    cout << "Congrats eiei\n";
                    cout << ""; // เพิ่มบทตอนฉากจบให้หน่อย
                    Sleep(3000); 
                    exit(0);
                }
                monsterHp = 0;
                cout << "\n\n";
                monsterXp = 19 * monsterLevel;
                cout << "You Defeated " << currentMonster << " you are awarded with " << monsterXp << " Exp.\n";
                cout << "Nice :)";
                monsterXp = 0;
                LevelUp();
                Sleep(2500);
                HUD();
                Moving();
            }
            Sleep(1500);
            Combat();
        }else if(playerAttack == 2){
            if(::SPcooldown == 0){ 
                if(level >= 4){
                    ::SPcooldown++;
                    system("cls");
                    cout << "You are using the SPECIAL ATTACK.\n";
                    Sleep(500);
                    system("cls");
                    cout << "You are using the SPECIAL ATTACK..\n";
                    Sleep(500);
                    system("cls");
                    cout << "You are using the SPECIAL ATTACK...\n";
                    Sleep(500);
                    system("cls");
                    cout << "The " << currentMonster << " suffered from your Special Attack by " << (100*(level/2))/2 << " damage!!\n";
                    monsterHp = monsterHp - (100*(level/2))/2;
                    Sleep(1500);
                    CombatHUD();
                
                    if(monsterHp >= 1){
                        cout << "\n";
                        cout << "Monster is Atacking...\n";
                        totalHealth = totalHealth - monsterAttack;
                        cout << "You lost " << monsterAttack << " hp and your current hp is " << totalHealth+::PPE << "\n";
                            if(totalHealth <= 0){
                                totalHealth = 0;
                                system("cls");
                                cout << "You DIED! \nYou were level: " << level << " you got killed by " << currentMonster << ".\n";
                                Sleep(1000);
                                cout << "You can't get out of the hospital. so sad :(\n";
                                Sleep(3000); 
                                exit(0);
                            }
                    }else if(monsterHp <= 0){
                        if(currentRoom >= 20){
                            system("cls");
                            cout << "Congrats eiei\n";
                            cout << ""; // เพิ่มบทตอนฉากจบให้หน่อย
                            Sleep(3000); 
                            exit(0);
                        }
                        monsterHp = 0;
                        cout << "\n\n";
                        monsterXp = 19 * monsterLevel;
                        cout << "You Defeated " << currentMonster << " you are awarded with " << monsterXp << " Exp.\n";
                        cout << "Nice :)";
                        monsterXp = 0;
                        LevelUp();
                        Sleep(2500);
                        HUD();
                        Moving();
                    }
                    Sleep(1500);
                    Combat(); 
                }else{
                    system("cls");
                    cout << "Your level is not enough to use the Special Attack.\n";
                    cout << "Your level must be 4 or higher than that.\n";
                    Sleep(2500);
                    Combat();  
                }
            }else {
                system("cls");
                cout << "You can use the Special Attack only once per round.\n";
                Sleep(1500);
                Combat();       
            }    
        } 
        else if(playerAttack == 3){
            system("cls");
            int ans;
            cout << "Please select your items\n\n";
            cout << "1. Health potion\n";
            cout << "2. Chemical X\n";
            cin >> ans;
            if(ans == 1){
                if(::healthPotion >= 1){
                    ::healthPotion--;
                    cout << "\nYour HP is restored by 100\n";
                    totalHealth = totalHealth + 100;
                    if(totalHealth >= maxHealth) totalHealth = maxHealth;
                    Sleep(1500);
                    Combat();
                }else{ 
                    cout << "You don't have any Health potion left\n";
                    Sleep(1500);
                    Combat();
                }
            }else if(ans == 2){
                if(::chemicalX >= 1){
                ::chemicalX--;
                ::atk = atk+25;   
                cout << "Your damage is increased by 25. (This item effect will remain until the fight ends)\n";
                Sleep(2500);
                Combat();
                }else{
                    cout << "You don't have any Chamical X left\n";
                    Sleep(1500);
                    Combat();
                }               
            }
            Sleep(1000);
            Combat();
        }
        else if(playerAttack == 4){
            //วิ่งหนีแบบใส่เกียร์หมา
            system("cls");
            cout << "You try to run away.\n";
            Sleep(500);
            system("cls");
            cout << "You try to run away..\n";
            Sleep(500);
            system("cls");
            cout << "You try to run away...\n";
            Sleep(500);
            system("cls");
           
            int x = rand() % 100 +1;
            if(x >= 70){
                cout << "You escaped safely.\n";
                ::currentRoom--;
                ::SPcooldown=0;
                Sleep(1250);
                HUD();
                Moving();
            }
            else {
                cout << "Can't escape!\n\n";
                Sleep(500);
                cout << currentMonster << " does a savage attack on you!\n";
                totalHealth -= monsterAttack + 5;
                cout << "You lost " << monsterAttack + 5 << " hp and your current hp is " << totalHealth << "\n";
                if (totalHealth <= 0){
                    totalHealth = 0;
                    system("cls");
                    cout << "You DIED! \nYou were level: " << level << " you got killed by " << currentMonster << ".\n";
                    Sleep(1000);
                    cout << "You can't get out of the hospital. so sad :(\n";
                    Sleep(3000); 
                    exit(0);
                }
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
    ::atk = 8;
    ::SPcooldown = 0;
    monsterXp = 19 * monsterLevel;
    xp = xp + monsterXp;

    if(xp >= nextLevel){
        level++;
        nextLevel = nextLevel * 3/2;
        xp = 0;
        totalHealth = totalHealth + 20;
        maxHealth = maxHealth+ + 20;
        cout << "\n\n";
        cout << "Congratulations " << name << " you are now level " << level << "\n";
        cout << "You are STRONGER than before\n";
        Sleep(2500);
        HUD();
    }
}

void story1(){
    string prologue1 = "\n\tProlouge......\n======================================\n13 February 2052 fisrt infecter was found.\nThe virus spread rapidly and used only 3 weeks to get over 5 countries including Thailand.\n\nThe Thai army successfully caught the first infecter in the country and sent to Krung Thep Maha Nakhon Hospital.\nThai government used 8 years to made detention area for the hospital......\n\n\nDuring that time infecter in other country got cured.\n======================================\n\n\n\n\n ";
	int x1 = 0;
	while (prologue1[x1] != '\0')
	{
		cout << prologue1[x1];
		Sleep(50);
		x1++;
	};
	system("pause");
	system("cls");

	string story1 = "\n\t15 February 2060 \n\n======================================\n\nGrrrrrrr......... Wait, what I just said ?\nWhy I'm here and these tight belts though, Grrrrrrr...\n\n======================================\n\n";
	int x2 = 0;
	while (story1[x2] != '\0')
	{
		cout << story1[x2];
		Sleep(50);
		x2++;
	};
}