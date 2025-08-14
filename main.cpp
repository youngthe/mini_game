#include <iostream>
#include <string>

class Player {
public:
    int health = 100;
    int power = 10;
    std::string m_name;

    int poison_power = 3;
    int poison_count = 0;

    int getHealth(){
        return health;
    }
    int getPower(){
        return power;
    }

    int upPower(){
        power += 5;
        return power;
    }

    int debuf(){
        power -= 3;
        return power;
    }

    void setName(std::string name){
        m_name = name;
    }

    std::string getName(){
        return m_name;
    }


    int hitDamage(int power){
        this->health -= power;
        return this->health;
    }

    int getPoisonPower(){
        return poison_power;
    }

    bool isPoison(){
        if(poison_count > 0){
            return true;
        }else{
            return false;
        }
    }

    int skillPoison(){
        poison_count += 5;
        return poison_count;
    }

    int usePoison(){
       return poison_count -= 1;
    }

  
    
};


bool isDie(int health){
    if(health > 0){
        return 0;
    }else{
        return 1;
    }
}

int main() {

    std::string name;
    int command;
    std::cout << "player1 : ";
    std::cin >> name;  // 공백 전까지만 읽음
    Player player1;
    player1.setName(name);
    std::cout << "안녕하세요, " << player1.getName() << "님!" << std::endl;

    std::cout << "player2 : ";
    std::cin >> name;  // 공백 전까지만 읽음
    
    Player player2;
    player2.setName(name);
    std::cout << "안녕하세요, " << player2.getName() << "님!" << std::endl;

    while(1){
        
        if(player1.isPoison()){
            std::cout << player1.getName() << " 맹독 발동 "  << player1.usePoison() <<"회 남았습니다."<< std::endl;
            std::cout << player2.getName() << "의 남은 피 : "  << player2.hitDamage(player1.getPoisonPower()) << std::endl;
        }

        if(player2.isPoison()){
            std::cout << player2.getName() << " 맹독 발동 "  << player2.usePoison() <<"회 남았습니다."<< std::endl;
            std::cout << player1.getName() << "의 남은 피 : "  << player1.hitDamage(player2.getPoisonPower()) << std::endl;
        }


        std::cout << player1.getName() << "님! 행위를 고르시오 : (1 공격, 2. 파워 업(힘 5 증가), 3. 맹독 피해)"  << std::endl;
        std::cin >> command;

        if(command == 1){
            std::cout << "공격 ! player2의 남은 피 : " << player2.hitDamage(player1.getPower()) << std::endl;
        }else if(command == 2){
            std::cout << "파워 업 ! player1의 힘 : " << player1.upPower() << std::endl;
        }else if(command == 3){
            std::cout << "맹독 공격 시전! " << player1.skillPoison() << "회 사용됩니다. "<< std::endl;
        }


        if(isDie(player2.getHealth())){
            std::cout << "player1 winner" << std::endl;
            return 0;
        }

        std::cout << player2.getName() << "님! 행위를 고르시오 : (1. 공격, 2. 파워 업(힘 5 증가), 3. 맹독 피해 5회)"  << std::endl;
        std::cin >> command;
        
        if(command == 1){
            std::cout << "공격 ! player1의 남은 피 : " << player1.hitDamage(player2.getPower()) << std::endl;
        }else if(command == 2){
            std::cout << "파워 업 ! player2의 힘 : " << player2.upPower() << std::endl;
        }else if(command == 3){
            std::cout << "맹독 공격 시전!" << player2.skillPoison() << "회 사용됩니다. "<< std::endl;
        }

        if(isDie(player1.getHealth())){
            std::cout << "player2 winner" << std::endl;
            return 0;
        }

    }
    
    return 0;
}